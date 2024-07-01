import os
from flask import Flask, render_template, request, redirect, g, url_for, make_response
import requests

app = Flask(__name__)

FLAG = os.getenv('FLAG', 'GTBQ{Contact_Admin_If_You_See_This}')

@app.route('/')
def index():
    return redirect(url_for('fetch'))

@app.route('/fetch', methods=['GET', 'POST'])
def fetch():
    if request.method == 'POST':
        url = request.form['url']
        try:
            response = requests.get(url)
            return render_template('fetch.html', response=response.text)
        except requests.exceptions.RequestException as e:
            return str(e)
    return render_template('fetch.html')

@app.route('/admin')
def admin():
    # allow only requests coming from localhost
    if request.remote_addr != '127.0.0.1':
        error = 'Only localhost is allowed to access this page'
        return render_template('fetch.html', error=error)
    return render_template('admin.html', flag=FLAG)

app.run(host='0.0.0.0', port=80, debug=True)
