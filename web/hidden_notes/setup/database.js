const sqlite = require('sqlite-async');
const crypto = require('crypto');


class Database {
    constructor(db_file) {
        this.db_file = db_file;
        this.db = undefined;
    }

    async connect() {
        this.db = await sqlite.open(this.db_file);
    }

    async migrate() {
        var username = process.env.admin_username
        var password = process.env.admin_password
        var flag = process.env.flag

        // Users Table Init
        this.db.exec(`
        DROP TABLE IF EXISTS users;
            CREATE TABLE IF NOT EXISTS users (
                id         INTEGER NOT  NULL PRIMARY KEY AUTOINCREMENT,
                username   VARCHAR(255) NOT NULL UNIQUE,
                password   VARCHAR(255) NOT NULL
            );
            INSERT INTO users (username, password) VALUES
                ('${username}', '${password}');
        `);

        // Notes Table Init
        this.db.exec(`
            DROP TABLE IF EXISTS notes;
                CREATE TABLE IF NOT EXISTS notes (
                    id         INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
                    title      VARCHAR(255) NOT NULL,
                    content       VARCHAR(255) NOT NULL,
                    user_id       INTEGER NOT NULL
                );
                
                INSERT INTO notes (title, content, user_id) VALUES
                    ('Meeting Agenda', 'Discuss quarterly goals and progress. Assign action items for next months marketing campaign', 1),
                    ('Shopping List', 'Milk, eggs, bread, apples, chicken for dinner tonight. Dont forget to pick up dry cleaning.', 1),
                    ('Super Secret Note', '${flag}', 1),
                    ('Project Milestones', 'Complete wireframes by Friday. Test user interface with focus group next Monday. Prepare final presentation for stakeholders', 1),
                    ('Weekend Plans', 'Saturday: Hike at the local park in the morning. Dinner with friends in the evening. Sunday: Relax at home, catch up on reading and movies. Hack the beginners quest main login page', 1);
            `);

        return;
    }

    // User Functions
    async login(user, pass) {
        return new Promise(async(resolve, reject) => {
            try {
                let stmt = await this.db.prepare('SELECT * FROM users WHERE username = ? and password = ?');
                resolve(await stmt.get(user, pass));
            } catch (e) {
                reject(e);
            }
        });
    }

    async register(user, pass) {
        return new Promise(async(resolve, reject) => {
            try {
                let stmt = await this.db.prepare('insert into users (username, password) values (?,?)');
                resolve(await stmt.get(user, pass));
            } catch (e) {
                reject(e);
            }
        });
    }

    async check_exists(user) {
        return new Promise(async(resolve, reject) => {
            try {
                let stmt = await this.db.prepare('select 1 from users where username=?');
                resolve(await stmt.get(user));
            } catch (e) {
                reject(e);
            }
        });
    }

    async notes(user_id) {
        return new Promise(async(resolve, reject) => {
            try {
                let stmt = await this.db.prepare('SELECT * FROM notes WHERE user_id = ?');
                resolve(await stmt.all(user_id));
            } catch (e) {
                reject(e);
            }
        });
    }

    async note(note_id) {
        return new Promise(async(resolve, reject) => {
            try {
                let stmt = await this.db.prepare('SELECT * FROM notes WHERE id = ?');
                resolve(await stmt.get(note_id));
            } catch (e) {
                reject(e);
            }
        });
    }

    async insert_note(title, content, user_id) {
        return new Promise(async(resolve, reject) => {
            try {
                let stmt = await this.db.prepare('insert into notes (title, content, user_id) VALUES (?, ?, ?)');
                resolve(await stmt.get(title, content, user_id));
            } catch (e) {
                reject(e);
            }
        });
    }

    async get_username(user_id) {
        return new Promise(async(resolve, reject) => {
            try {
                let stmt = await this.db.prepare('SELECT username FROM users WHERE id = ?');
                resolve(await stmt.get(user_id));
            } catch (e) {
                reject(e);
            }
        });
    }

}

module.exports = Database;