<!DOCTYPE html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <title>Dashboard</title>

    <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.6.3/css/all.css" integrity="sha384-UHRtZLI+pbxtHCWp1t77Bi1L4ZtiqrqD80Kn4Z8NTSRyMA2Fd33n5dQ8lWUE00s/" crossorigin="anonymous">
    
    <link rel="stylesheet" href="css/bootstrap4-neon-glow.min.css">
    
    
    <link href="https://fonts.googleapis.com/css?family=Roboto" rel="stylesheet">
    <link rel='stylesheet' href='//cdn.jsdelivr.net/font-hack/2.020/css/hack.min.css'>
    
  </head>
  <body>

  <div class="navbar-dark text-white">
    <div class="container">
      <nav class="navbar px-0 navbar-expand-lg navbar-dark">
        <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNavAltMarkup" aria-controls="navbarNavAltMarkup" aria-expanded="false" aria-label="Toggle navigation">
          <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarNavAltMarkup">
          <div class="navbar-nav">
            <a href="#" class="pl-md-0 p-3 text-light">Start</a>
            <a href="#" class="p-3 text-decoration-none text-light">Login</a>
            <a href="#" class="p-3 text-decoration-none text-light">Register</a>
          </div>
        </div>
      </nav>

    </div>
  </div>


  

<div class="jumbotron bg-transparent mb-0 radius-0">
  <div class="container">
      <div class="row">
        <div class="col-xl-10">
          <h1 class="display-2">PHPocalyps<span class="vim-caret">e</span> Image Uploader</h1>
          <div class="lead mb-3 text-mono text-success">Upload images to the gallery, what can go wrong?</div>
          
          <form method="post" action="/upload.php" enctype="multipart/form-data" class="mt-4 pt-2 mb-lg-0 mb-5">
            <div class="input-group input-group-lg">

                <input name="file" type="file" class="form-control border-0 mt-3" id="keyword" placeholder="Choose image...">

            </div>
        
          
            <div class="text-mono">
                <button type="submit" class="btn btn-success btn-shadow px-3 my-2 ml-0 text-left">Upload</button>
            </div>
          </form>
      </div>
  </div>
</div>




  <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
  <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
  <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>

  </body>
</html>
