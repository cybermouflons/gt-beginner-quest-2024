import os
from flask import Flask, render_template, request, redirect, g, url_for, make_response
import subprocess

app = Flask(__name__)

FLAG = os.getenv('FLAG', 'GTBQ{Contact_Admin_If_You_See_This}')

@app.route('/')
def index():
    return redirect(url_for('nmap'))

@app.route('/nmap', methods=['GET', 'POST'])
def nmap():
    if request.method == 'GET':
        return render_template('nmap.html')
    elif request.method == 'POST':
        target = request.form['target']
        output = subprocess.check_output(f'nmap {target}', shell=True)
        return render_template('nmap.html', output=output.decode('utf-8'))


app.run(host='0.0.0.0', port=80, debug=True)
