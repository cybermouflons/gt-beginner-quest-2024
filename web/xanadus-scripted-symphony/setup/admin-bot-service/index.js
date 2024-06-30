const puppeteer = require('puppeteer');
const express = require('express');
const fs = require('fs');
const app = express();
const port = 3000;
const flag = fs.readFileSync('/flag.txt', 'utf8').trim();

app.get('/report', async (req, res) => {
    const browser = await puppeteer.launch({
        args: ['--no-sandbox', '--disable-setuid-sandbox']
      });
    const page = await browser.newPage();

    await page.setCookie({
        name: 'FLAG',
        value: flag,
        url: req.query.url
    });

    await page.goto(req.query.url);
    await browser.close();
    res.send('Visited ' + req.query.url);
});

app.listen(port, () => {
    console.log(`Admin bot service listening at http://localhost:${port}`);
});