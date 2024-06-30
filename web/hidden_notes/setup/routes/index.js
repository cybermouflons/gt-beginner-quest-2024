const express = require('express')
const router = express.Router({ caseSensitive: true });
const { authenticated }  = require('../middleware/authMiddleware');

const response = data => ({ message: data });

router.get('/',authenticated, async (req, res) => {

    const success = req.session.success
    const error = req.session.error
    delete req.session.error;
    delete req.session.success;
    
    user = req.session.user

    // Get all notes
    await db.notes(user.id).then(async notes => {
        if (notes){
            return res.render('index.html', {user: user, notes: notes, success: success, error: error});
        }
        else{
            return res.status(500).json({ message: 'Could not fetch notes' });       
        }
    })
   
});


router.post('/note',authenticated, async (req, res) => {

    const { title, content } = req.body;
    user_id = req.session.user.id

    try{
        await db.insert_note(title, content, user_id)
        req.session.success = "Note added successfully"
        return res.redirect('/');
    }
    catch(err){
        req.session.error = "Could not add note - Please request support"
        console.log(err)
        return res.redirect('/');
    }
    
})

router.get('/note/:id',authenticated, async (req, res) => {

    const id = req.params.id



    await db.note(id).then(async note => {
        if(note){

            const author = await db.get_username(note.user_id)
            return res.render('note.html', {note: note, author: author.username});
        }
        else{
            return res.status(404).json({ message: 'Note not found! :(' });
        }
    })
})

router.get('/login', (req, res) => {

    const success = req.session.success;
    const error = req.session.error;
    delete req.session.error;
    delete req.session.success;


    return res.render('login.html', {success: success, error: error});
});

router.post('/login', async (req, res) => {
    
    const { username, password } = req.body;
  
    if (username && password) {

        return db.login(username, password)
            .then(async user => {
                if(user){
                    req.session.user = user
                    return res.redirect('/');
                }
                else{
                    return res.render('login.html', { error: 'Invalid username or password! Try again..'} )   
                }
            });
    }
    return res.status(500).send(response('Missing parameters!'));
});

router.get('/register', (req, res) => {
    return res.render('register.html');
});

router.post('/register', (req, res) => {
    const { username, password } = req.body;
    if( username && password){
        
        return db.check_exists(username).then(async user => {
            if(user){
                return res.render('register.html', {error: 'Username already exists, pick another one!'})
            }
            else{

                db.register(username,password)
                req.session.success = 'Registered account successfully';
                return res.redirect('/login')
            }
        })
    }

    return res.render('register.html');
});


router.get('/logout', (req, res) => {
    req.session = null
    return res.clearCookie('session').redirect('/login');
});


module.exports = database => {
    db = database;
    return router;
};

