# forces the user to input a valid answer
while True:
    height = int(input("Height: "))
    if height > 0 and height < 9:
        break
    except ValueError

# prints the pyramid piramid pirâmide
for i in range(height):
    print((height - 1 - i) * " ", end="")
    print((i + 1) * "#")