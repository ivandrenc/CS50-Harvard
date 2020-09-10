SELECT DISTINCT name from
people WHERE id in 
(SELECT person_id from 
stars WHERE movie_id in 
(SELECT movie_id from stars where person_id in (SELECT id from people WHERE name = "Kevin Bacon" and birth = 1958))) and NOT id = 102
ORDER by name