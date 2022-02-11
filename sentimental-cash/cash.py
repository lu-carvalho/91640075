from cs50 import get_float

# asks the user how much change is owed
# force him to give me a valid number

while True:
    change = get_float("Change owed: ")
    if change > 0:
        break

# spits out the minimum number of coins with which said change can be made


# assume that the user will input their change in dollars

#  Assume that the only coins available are quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢).