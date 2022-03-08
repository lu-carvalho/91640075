-- Keep a log of any SQL queries you execute as you solve the mystery.

-- get crime's description
SELECT description FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND street = "Humphrey Street";

-- get the transcripts from the interviews
SELECT id, name, transcript FROM interviews WHERE year = 2021 AND month = 7 AND day = 28;

-- get the license plates that left the bakery around 10 minutes after 10h15
SELECT license_plate, activity, minute FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 26;

-- if the thief left around 10 minutes after the theft, than we have the following license plates that are suspicious:
-- 5P2BI95 (1 min), 94KL13X (3min), 6P58WS2 (3min), 4328GD8 (4min), G412CB7(5 min), L93JTIZ(6 min), 322W7JE(8min), 0NTHK55(8min)
-- what are their names and ID?

SELECT name, id FROM people
WHERE license_plate IN
(SELECT license_plate
FROM bakery_security_logs
WHERE activity = "exit"
AND year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 26);

-- Those are my suspects: Vanessa 221103, Barry 243696, Iman 396669, Sofia 398010, Luca 467400, Diana 514354, Kelsey 560886 and Bruce 686048.
-- Which one of those where by the ATM at Leggett Street withdrawing money?

SELECT name, person_id
FROM bank_accounts
JOIN people
ON people.id = bank_accounts.person_id
JOIN atm_transactions
ON atm_transactions.account_number = bank_accounts.account_number
WHERE transaction_type = "withdraw"
AND atm_location = "Leggett Street"
AND atm_transactions.year = 2021 AND atm_transactions.month = 7 AND atm_transactions.day = 28;

-- So from these list I'm down to Iman 396669, Luca 467400, Bruce 686048 or Diana 514354.
-- Here I have everyone that was on the firts flight out of Fiftyville
SELECT people.name, people.id, flights.hour, flights.minute, flights.destination_airport_id
FROM people
JOIN passengers
ON people.passport_number = passengers.passport_number
JOIN flights
ON passengers.flight_id = flights.id
JOIN airports
ON flights.origin_airport_id = airports.id
WHERE airports.city = "Fiftyville"
AND flights.year = 2021
AND flights.month = 7
AND flights.day = 29
ORDER BY flights.hour;

-- now I'm down to Luca 467400 or Bruce 686048. Let me check the phone calls

SELECT people.name, phone_calls.receiver
FROM people
JOIN phone_calls
ON people.phone_number = phone_calls.caller
WHERE phone_calls.year = 2021
AND phone_calls.month = 7
AND phone_calls.day = 28
AND phone_calls.duration < 61;

-- ok, so I know bruce was the thief, the receiver is the one that helped him and has the phone number (375) 555-8161

SELECT name FROM people WHERE phone_number = "(375) 555-8161";

-- great so Bruce did it, Robin helped him and I forgot to see where he scaped to, but I know the destination airport ID is 4:

SELECT city FROM airports WHERE id = 4;

-- NEW YORK CITY!!