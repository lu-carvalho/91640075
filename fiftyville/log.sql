-- Keep a log of any SQL queries you execute as you solve the mystery.

-- get the description of the crime
SELECT description FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND street = "Humphrey Street";

-- get the transcripts from the interviews
SELECT id, name, transcript FROM interviews WHERE year = 2021 AND month = 7 AND day = 28;

-- get the license plates that left the bakery around 10 minutes after 10h15
SELECT license_plate, activity, minute FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10;