import cs50

while True:
    text = cs50.get_string("Text: ")

    characteres = 0

    if(text):
        for i in range(len(text)):
            if(text[i].isalpha()):
                characteres += 1
            elif(text[i])
            
