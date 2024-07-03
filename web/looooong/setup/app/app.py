import os
from flask import Flask, render_template, request, redirect, g, url_for, make_response

app = Flask(__name__)

FLAG = os.getenv('FLAG', 'GTBQ{Contact_Admin_If_You_See_This}')

@app.route('/')
def index():
    return render_template('start.html')

@app.route('/magic')
def magic():
    response_headers = {
        'Location': url_for('end'),
        'Content-Type': 'text/html; charset=utf-8'
    }
    response = make_response(render_template('flag.html', flag=FLAG), 302)
    response.headers = response_headers
    return response

@app.route('/end')
def end():
    return render_template('end.html')

app.run(host='0.0.0.0', port=80, debug=True)
