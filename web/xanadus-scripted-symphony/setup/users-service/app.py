from flask import Flask
from flask_login import LoginManager
from config.config import get_app_config
from database.db import db
from blueprints.auth import auth_blueprint
from blueprints.posts import posts_blueprint
from blueprints.home import home_blueprint
from models.user import User

app = Flask(__name__)
app.config.from_object(get_app_config())

login_manager = LoginManager()
login_manager.login_view = 'auth.login'
login_manager.init_app(app)


app.register_blueprint(auth_blueprint)
app.register_blueprint(posts_blueprint)
app.register_blueprint(home_blueprint)

db.init_app(app)

@login_manager.user_loader
def load_user(user_id):
    return User.query.get(int(user_id))

with app.app_context():
    db.create_all()
    

if __name__ == '__main__':
    app.run(host=app.config['HOST'], port=app.config['PORT'])