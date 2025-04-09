const readline = require('readline');
const getMovie = require('./movieFetcher');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question(`Enter a movie title: `, async (title) => {
    const data = await getMovie(title);
    console.log(data);
    rl.close();
})