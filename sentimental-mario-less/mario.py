from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height>0 and height<9:
        break

for i in range(height):
    for s in range(height - 1 - i):
        print(" ", end="")
    for h in range(height-1-s):
        print("#", end="")
    print()