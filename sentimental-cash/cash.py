from cs50 import get_float

coins = 0

# asks the user how much change is owed
# force him to give me a valid number
while True:
    change_dol = get_float("Change owed: ")
    if change_dol > 0:
        break

change = round(int(change_dol * 100))

# spits out the minimum number of coins with which said change can be made
while change > 0:
    while change > 0.25:
        change -= 0.25
        coins += 1
    while change > 0.10:
        change -= 0.10
        coins += 1
    while change > 0.05:
        change -= 0.05
        coins += 1
    while change > 0.01:
        change -= 0.01
        coins += 1
print(coins)

# assume that the user will input their change in dollars

#  Assume that the only coins available are quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢).