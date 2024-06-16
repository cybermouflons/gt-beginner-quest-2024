from flask import Flask, render_template, request
import os

app = Flask(__name__)

@app.route('/')
def index():
    files = os.listdir('files')
    return render_template('index.html', files=files)


@app.route('/get_file', methods=['POST'])
def get_file():
    filename = request.form['filename']
    # python was made to be easy, don't complicate things
    with open(filename, 'r') as f:
        return f.read()

if __name__ == '__main__':
    # I enabled debug mode so I can debug using /console
    app.run('127.0.0.1', 5000, debug=True)
