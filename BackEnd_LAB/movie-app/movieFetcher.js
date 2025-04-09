const axios = require('axios');

async function getMovie(title) {
    const apikey = 'cb833bc9';
    const url = `http://www.omdbapi.com/?t=${title}&apikey=${apikey}`;

    try {
        const response = await axios.get(url);
        return response.data;
    }catch(error){
        return { error: 'Movie not found' };
    }
}

module.exports = getMovie;