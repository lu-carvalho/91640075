from cs50 import get_string
import string

# get input from user
text = get_string("Text: ")

# declare variables: words, letters and sentences so we can make the calculus
# to count words we will use spaces, so we begin with 1

letters = 0
words = 1
sentences = 0

for letter in text:
    if letter == "!" or letter == "?" or letter == ".":
        sentences += 1
    # the following avoid that other punctuation such as commas count as a letter:
    elif letter in string.punctuation:
        continue
    # 
    elif letter in string.whitespace:
        words += 1
