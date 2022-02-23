-- Keep a log of any SQL queries you execute as you solve the mystery.

-- get the description of the crime
SELECT description FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND street = "Humphrey Street";

-- get the transcripts from the interviews
SELECT id, name, transcript FROM interviews WHERE year = 2021 AND month = 7 AND day = 28;

-- get the license plates that left the bakery around 10 minutes after 10h15
SELECT license_plate, activity, minute FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 26;

-- if the thief left around 10 minutes after the theft, than we have the following license plates that are suspicious:
-- 5P2BI95 (1 min), 94KL13X (3min), 6P58WS2 (3min), 4328GD8 (4min), G412CB7(5 min), L93JTIZ(6 min), 322W7JE(8min), 0NTHK55(8min)
-- what are their names?

SELECT name FROM people
WHERE license_plate IN
(SELECT license_plate
FROM bakery_security_logs
WHERE activity = exit
AND year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 26);