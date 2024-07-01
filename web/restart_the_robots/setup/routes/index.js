const express = require('express')
const router = express.Router({ caseSensitive: true });

router.get('/', async (req, res) => {

   
    return res.render('index.html');
});

router.get('/the_robots_will_never_find_me_now', async (req, res) => {

    flag = process.env.flag
   
    return res.render('flag.html', {flag: flag});
});


module.exports = () => {
    return router;
};

