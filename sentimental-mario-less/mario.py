from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height>0:
        break

for i in range(height):
    
    print(" "*(height-1), end="")
    print("#" * (height-1))
    height = height - 1