SELECT title FROM (SELECT movies.title, movies.id FROM movies
JOIN stars on stars.movie_id = movies.id 
JOIN people on stars.person_id = people.id
JOIN ratings on ratings.movie_id = movies.id
WHERE people.name = "Helena Bonham Carter")
--the function intersect is used to match all the movies that j.depp and helena starred together
INTERSECT
SELECT title FROM (SELECT movies.title, movies.id FROM movies
JOIN stars on stars.movie_id = movies.id 
JOIN people on stars.person_id = people.id
JOIN ratings on ratings.movie_id = movies.id
WHERE people.name = "Johnny Depp")
