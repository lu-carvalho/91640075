-- Keep a log of any SQL queries you execute as you solve the mystery.
-- get the description of the crime
SELECT description FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND street = "Humphrey Street";

--OUTPUT: Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three
--witnesses who were present at the time – each of their interview transcripts mentions the bakery.Littering took place at 16:36.
--No known witnesses.

-- Select the activity from the bakery at the day the crime happened
SELECT id, activity, hour, minute FROM bakery_security_logs
WHERE year = 2021 AND month = 7 AND day = 28;

-- the IDs 258 and 259 are suspects. I

SELECT id, name, transcript FROM interviews WHERE year = 2021 AND month = 7 AND day = 28;