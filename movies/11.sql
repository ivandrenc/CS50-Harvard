SELECT title FROM (SELECT movies.title, movies.id FROM movies
JOIN stars on stars.movie_id = movies.id 
JOIN people on stars.person_id = people.id
JOIN ratings on ratings.movie_id = movies.id
WHERE people.name = "Chadwick Boseman"
ORDER by rating DESC LIMIT 5)