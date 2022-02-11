from cs50 import get_int

# forces the user to input a valid answer
while True:
    height = get_int("Height: ")
    if height > 0 and height < 9:
        break

# prints the pyramid piramid pirâmide
for i in range(height):
    print((height - 1 - i) * " ", end="")
    print((i + 1) * "#")