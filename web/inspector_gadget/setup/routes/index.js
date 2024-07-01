const express = require('express')
const router = express.Router({ caseSensitive: true });


router.get('/', async (req, res) => {
   
    return res.render('index.html');
});


module.exports = () => {
    return router
};

