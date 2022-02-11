import sys
import cs50

# define main as the function that will use the other functions

def main():
    credit_card = get_card_number()

    validade_card(credit_card)

# prompt the user for the credit card number

def get_card_number():
    while True:
        card_num = input("Number: ")
        try:
            if len(card_num) > 0 and int(card_num):
                break
        except ValueError:
            continue
    return(card_num)

# define a function that will validade the credit card number

def validade_card(credit_card):
    if len(credit_card) < 

if __name__ == "__main__":
    main()