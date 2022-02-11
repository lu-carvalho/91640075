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
                multiple = num*2
                if multiple >= 10:
                    even += multiple // 10
                    even +- multiple % 10
                else:
                    even +- multiple
            else:
                odd += num

    else:
        for i in range(card_len):
            num = int(card_len[i])
            if i % 2 != 0:
                multiple = num * 2
                if multiple >= 10:
                    even += multiple // 10
                    even += multiple % 10
                else:
                    even += multiple
            else:
                odd += num
    checksum = (even + odd) % 10

    if checksum == 0:
        first_digit = int(credit_card[0])
        second_digit = int(credit_card[1])
        if first_digit == 3 and second_digit == 4 or second_digit == 7:
            print("AMEX")
        if first_digit == 5 and 1 <= second_digit <= 5:
            print("MASTERCARD")
        if first_digit == 4:
            print("VISA")
        else:
            print("INVALID")

if __name__ == "__main__":
    main()