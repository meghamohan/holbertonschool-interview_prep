#!/usr/bin/node
const request = require('request');
const movie = process.argv.slice(2)[0];
movieCharacters('https://swapi.co/api/people/', movie);

function movieCharacters (url, movieId) {
  request(url, function (error, response, body) {
    if (error) {
      console.log(error);
    } else {
      const resp = JSON.parse(response.body);
      url = resp.next; /*response in the next page*/
      let characters = resp.results;
      characters.forEach(function (character) {
        const movies = character.films;
        movies.forEach(function (mov) {
          if (mov.includes(movieId)) {
            console.log(character.name);
          }
        });
      });
    }
    if (url) { /*print only if page isnt null*/
      movieCharacters(url, movieId);
    }
  });
}
