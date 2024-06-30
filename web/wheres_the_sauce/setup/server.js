const express = require('express');
const nunjucks = require('nunjucks');
const bodyParser = require('body-parser');
const http = require('http');

app = express();

var httpServer = http.createServer(app);
const routes = require('./routes'); 

app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.json());

nunjucks.configure('views', {
  autoescape: true,
  express: app
});

app.set('view engine', 'nunjucks');
app.set('views', './views');
app.use(express.static('./static'));


app.use(routes());

app.use(function(err, req, res, next) {
    console.log(err)
    res.status(500).json({ message: 'You broke me :(' });
  });

(async() => {


    httpServer.listen(3000, () => {
        console.log(`Server running at http://0.0.0.0:3000/`);
    });

})();