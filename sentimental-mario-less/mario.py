# forces the user to input a valid answer
try:
    while True:
        height = int(input("Height: "))
        if height > 0 and height < 9:
            break
except ValueError:
   height = int(input("Height: "))

# prints the pyramid piramid pirâmide
for i in range(height):
    print((height - 1 - i) * " ", end="")
    print((i + 1) * "#")