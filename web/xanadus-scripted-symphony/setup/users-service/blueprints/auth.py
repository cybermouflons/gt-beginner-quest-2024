from flask import Blueprint, render_template, request, redirect, session
from flask_login import login_user
from database.db import db
from models.user import User
import hashlib

auth_blueprint = Blueprint('auth', __name__, url_prefix='/auth')

@auth_blueprint.route('/register', methods=['GET', 'POST'])
def register():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']


        user = User.query.filter_by(username=username).one_or_none()
        if user is not None:
            return render_template('register.html', error_message="User already exists")
        else:
            password = hashlib.md5(password.encode()).hexdigest()
            user = User(username, password)
            db.session.add(user)
            db.session.commit()

            #session['username'] = user.username
            return redirect('/auth/login')
        
        
    return render_template('register.html')


@auth_blueprint.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        
        user = User.query.filter_by(username=username).one_or_none()

        if user and user.password == hashlib.md5(password.encode()).hexdigest():
            
            session.permanent = True
            session['user_id'] = user.id
            login_user(user)

            return redirect('/posts')
        else:
            return render_template('login.html', error_message="Invalid credentials")
    
    return render_template('login.html')


@auth_blueprint.route('/logout', methods=['GET'])
def logout():
    session.clear()
    return redirect('/auth/login')