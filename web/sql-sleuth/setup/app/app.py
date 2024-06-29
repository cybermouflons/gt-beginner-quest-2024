import sqlite3
import random
import string
from flask import Flask, render_template, request, redirect, g, url_for
import os

app = Flask(__name__)
app.database = "app.db"

FLAG = os.getenv('FLAG', 'GTBQ{Contact_Admin_If_You_See_This}')

def connect_db():
    return sqlite3.connect(app.database)

def rand_str(k=10) -> str:
    return ''.join(random.choices(string.ascii_letters + string.digits, k=k))

@app.route('/')
def index():
    return redirect(url_for('login'))

@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']

        g.db = connect_db()
        c = g.db.cursor()
        g.query = f"SELECT * FROM users WHERE username='{username}' AND password = '{password}'"
        try:
            c.execute(g.query)
        except Exception as e:
            return render_template('login.html', error="Something went wrong", query=g.query)
        user = c.fetchone()
        if user:
            return render_template('loggedin.html', flag=FLAG)
        else:
            return render_template('login.html', error="Invalid username or password")
    return render_template('login.html')

#create database if it doesn't exist yet
with app.app_context():
    g.db = connect_db()
    c = g.db.cursor()
    if c.execute("SELECT name FROM sqlite_master WHERE type='table' AND name='users'").fetchone() is None:
        c.execute("""CREATE TABLE users (id INTEGER PRIMARY KEY, username TEXT, password TEXT)""")
    admin_password = rand_str()
    if c.execute("SELECT * FROM users WHERE username='admin'").fetchone() is None:
        # insert the admin user
        c.execute(f"INSERT INTO users (username, password) VALUES ('admin', '{admin_password}')")
    else:
        c.execute(f"UPDATE users SET password='{admin_password}' WHERE username='admin'")
    g.db.commit()
    g.db.close()

app.run(host='0.0.0.0', port=80)
