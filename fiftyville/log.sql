-- Keep a log of any SQL queries you execute as you solve the mystery.

-- get the description of the crime
SELECT description FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND street = "Humphrey Street";

-- get the transcripts from the interviews
SELECT id, name, transcript FROM interviews WHERE year = 2021 AND month = 7 AND day = 28;

-- 