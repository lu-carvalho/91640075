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
    # every time we find a space, it means it's a new word
    elif letter in string.whitespace:
        words += 1
    # and, finally, if letter is not a punctuation, a ?, ! or . nor a whitespace, it is officially a letter! so:
    else:
        letters += 1

# calculate the Coleman-Liau index
wordf = words / 100
lettersw = letters / wordf
sentencesw = sentences / wordf

index = round((0.0588 * lettersw) - (0.296 * sentencesw) - 15.8)

# return to the user the grade of the text
if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade: {index}")