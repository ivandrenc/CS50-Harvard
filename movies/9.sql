SELECT name FROM (SELECT DISTINCT people.id, name FROM people
JOIN stars on people.id = stars.person_id 
JOIN movies on stars.movie_id = movies.id
WHERE year = 2004
ORDER by birth ASC)



 