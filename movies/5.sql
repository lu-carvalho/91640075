-- Year from each HP Movie: SELECT year FROM movies WHERE title LIKE 'Harry Potter%';
-- Title of each HP Movie: SELECT title FROM movies WHERE title LIKE 'Harry Potter%';
SELECT title, year FROM movies WHERE title LIKE 'Harry Potter%' ORDER BY year ASC;