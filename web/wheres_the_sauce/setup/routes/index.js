const express = require('express')
const router = express.Router({ caseSensitive: true });

const response = data => ({ message: data });
flag = process.env.flag

const flag_part_1 = flag.slice(0, flag.length / 2)
const flag_part_2 = flag.slice(flag.length / 2, flag.length)


router.get('/', async (req, res) => {

    return res.render('index.html');
});


router.get('/flag-endpoint-1', async (req, res) => {
    error=""
    success=""

    if(req.query.secret_param1 == 1337){
        if(req.headers.give_me == "my_flag_please"){
            if(req.query.secret_param2 == 7331){
            
                return res.render('index.html', {success: flag_part_1});

            }
        }
    }

    return res.render('index.html', {error: "No flag for you!"});
});


router.options('/flag-endpoint-2', async (req, res) => {

    success=""

    return res.render('index.html', {success: flag_part_2});
});


module.exports = database => {
    db = database;
    return router;
};

