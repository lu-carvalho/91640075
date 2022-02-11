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

    even, odd = 0, 0
    card_len = len(credit_card)

    if card_len != 13 or card_len != 15 or card_len != 16:
        print ("IVALID")
        sys.exit(1)

    if card_len % 2 == 0:
        for i in range(card_len):
            num = int(card_len[i])
            if i % 2 == 0:
                


if __name__ == "__main__":
    main()