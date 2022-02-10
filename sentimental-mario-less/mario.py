from cs50 import get_int

height = get_int("Height: ")

for i in range(height):
    print(" " * (height-1))
    print("#" * (height - (height-1)))
    height = height - 1