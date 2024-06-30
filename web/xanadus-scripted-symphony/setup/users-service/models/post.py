from database.db import db

class Post(db.Model):

    __tablename__ = 'posts'

    id = db.Column(db.Integer, primary_key=True)
    user_id = db.Column(db.Integer, db.ForeignKey('users.id'))
    title = db.Column(db.String(100))
    content = db.Column(db.String(500))
    picture = db.Column(db.String(500))

    def __init__(self, title, content, user_id, picture=None):
        self.title = title
        self.content = content
        self.user_id = user_id
        self.picture = picture