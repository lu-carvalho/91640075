-- list all movies released in 2010: SELECT title FROM movies WHERE year = 2010;
-- and their ratings: SELECT rating FROM ratings WHERE movie_id IN (SELECT id FROM movies WHERE year = 2010);
--  in descending order by rating: ORDER BY rating DESC;
-- For movies with the same rating, order them alphabetically by title.

SELECT movies.title, ratings.rating FROM movies JOIN ratings ON ratings.movie_id = movies.id WHERE year = 2010 ORDER BY rating DESC, title ASC;