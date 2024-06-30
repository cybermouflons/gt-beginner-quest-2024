from flask import Blueprint, request, jsonify, render_template, redirect, current_app
from flask_login import login_required, current_user
from database.db import db
from models.post import Post
from models.user import User
from PIL import Image
import os
import random
import base64
import requests

posts_blueprint = Blueprint('posts', __name__, url_prefix='/posts')

@posts_blueprint.route('', methods=['GET'])
@login_required
def show_all_posts():
    return render_template('posts.html')


@posts_blueprint.route('/all', methods=['GET'])
@login_required
def get_posts():
    posts = Post.query.filter_by(user_id=current_user.id).all()
    
    posts_list = [{"id": post.id, "title": post.title, "content": post.content, "user_id": post.user_id, "picture": post.picture} for post in posts]

    return jsonify(posts_list)


@posts_blueprint.route('/add', methods=['GET', 'POST'])
@login_required
def add_post():
    if request.method == 'POST':
        title = request.form['title']
        content = request.form['content']

        images_dir = os.path.join(current_app.root_path, 'static', 'images')
        images = os.listdir(images_dir)
        image_path = os.path.join(images_dir, random.choice(images))

        img = Image.open(image_path)
        img.resize((300, 500))
        img.save(image_path)

        with open(image_path, "rb") as image_file:
            encoded_string = base64.b64encode(image_file.read()).decode('utf-8')

        post = Post(title, content, current_user.id, picture=encoded_string)
        db.session.add(post)
        db.session.commit() 

        return redirect('/posts')

    return render_template('add_post.html')


@posts_blueprint.route('/<int:post_id>', methods=['GET'])
def show_post(post_id):
    post = Post.query.filter_by(id=post_id).one_or_none()
    user = User.query.filter_by(id=post.user_id).one_or_none()

    if post is None:
        return jsonify({"error": "Post not found"}), 404

    
    return render_template('post.html', post=post, user=user)


@posts_blueprint.route('/report', methods=['GET', 'POST'])
@login_required
def report_post():
    if request.method == 'POST':
        url = request.form['url']

        requests.get(f"http://admin-bot-service:3000/report?url={url}")


        return render_template('report_url.html', success_message="The admin will visit your URL soon.")

    return render_template('report_url.html')