import os
from flask import Flask, render_template, request, redirect, g, url_for, make_response

app = Flask(__name__)

FLAG = os.getenv('FLAG', 'GTBQ{Contact_Admin_If_You_See_This}')

@app.route('/')
def index():
    resp = make_response(render_template('index.html'))
    resp.set_cookie('is_admin', 'false')
    return resp

@app.route('/admin')
def admin():
    if request.cookies.get('is_admin') == 'true':
        return render_template('admin.html', flag=FLAG)
    else:
        return redirect(url_for('index'))

app.run(host='0.0.0.0', port=80, debug=True)
