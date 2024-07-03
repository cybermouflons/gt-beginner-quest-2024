from flask import Flask, request, render_template_string, redirect

app = Flask(__name__)

@app.route('/')
def welcome():

    if request.args.get('msg') is None:
        return redirect("/?msg=Welcome")

    msg = request.args.get('msg', 'Welcome')

    template = f"""
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Welcome</title>
        <link rel="stylesheet" href="https://hackerthemes.com/bootstrap-themes/demo/theme-machine/neon-glow/css/bootstrap4-neon-glow.css">
        <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.15.3/css/all.min.css">
        <style>
            html, body {{
                height: 100%;
            }}
            .container {{
                display: flex;
                justify-content: center;
                align-items: center;
                height: inherit;
                min-height: inherit;
            }}
            .row {{
                width: 100%;
            }}
        </style>
    </head>
    <body class="neon-glow">
        <nav class="navbar fixed-top justify-content-between">
            <a href="/" class="btn btn-primary neon-border-blue"><i class="fas fa-home"></i> Home</a>
        </nav>
        <div class="container">
            <div class="row justify-content-center">
                <div class="col-md-6">
                    <h1 class="text-center neon-text-blue">{ msg }</h1>
                </div>
            </div>
        </div>

        <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js"></script>
        <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.5.0/js/bootstrap.min.js"></script>        
    </body>
    </html>
    """

    return render_template_string(template)

if __name__ == '__main__':
    app.run(debug=True)