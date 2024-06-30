import os
from datetime import timedelta


def get_app_config():
    return Config()

class Config:
    APP_NAME = 'users-service'
    
    SECRET_KEY = os.urandom(24).hex()
    SESSION_COOKIE_SECURE = True
    PERMANENT_SESSION_LIFETIME = timedelta(minutes=10)
    SQLALCHEMY_DATABASE_URI = 'sqlite:///chall.db'
    SQLALCHEMY_TRACK_MODIFICATIONS = False
    SESSION_COOKIE_SECURE = False
    HOST = '0.0.0.0'
    PORT = 5000