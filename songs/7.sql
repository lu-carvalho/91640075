-- Drake's ID: SELECT id FROM artists WHERE name = 'Drake'
-- Average of Energy: SELECT AVG(energy) FROM songs WHERE artist_id = _Drake's ID_
-- Combining them togheter: SELECT AVG(energy) FROM songs WHERE artist_id = (SELECT id FROM artists WHERE name = 'Drake');
SELECT AVG(energy) FROM songs WHERE artist_id = (SELECT id FROM artists WHERE name = 'Drake');
