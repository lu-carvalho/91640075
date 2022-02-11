from cs50 import get_float

coins = 0

# asks the user how much change is owed
# force him to give me a valid number
while True:
    change = get_float("Change owed: ")
    if change > 0:
        break

# spits out the minimum number of coins with which said change can be made
while change >= 0.25:
    change -= 0.25
    coins += 1
    if change < 0.25:
        break

while change >= 0.10:
    change -= 0.10
    coins += 1
    if change < 0.10:
        break

while change >= 0.05:
    change -= 0.05
    coins += 1
    if change < 0.05:
        break

while change >= 0.01:
    change -= 0.01
    coins += 1
    if change < 0.01:
        break

print("{}".format, coins)
# assume that the user will input their change in dollars

#  Assume that the only coins available are quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢).