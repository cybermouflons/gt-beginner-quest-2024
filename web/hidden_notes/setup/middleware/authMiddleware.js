
function authenticated(req, res, next){

    if(req.session.user){
        next()
    }else{
        req.session.error = 'Login required!'
        return res.redirect('/login')
    }
}

module.exports = {
    authenticated
};