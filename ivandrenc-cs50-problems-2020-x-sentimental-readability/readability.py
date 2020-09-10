from cs50 import get_string

def main():
    text = get_string("Text: ")
    L = (count_letters(text) * 100) / count_words(text)
    S = (count_sentences(text) * 100) / count_words(text)  
    index = round(0.0588 * L - 0.296 * S - 15.8)  #rounds to nearest integer
    
    if index >= 16:  # checks whether is above 16 years or before 1 year
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print("Grade", index)

def count_letters(text1):
    counterLetters = 0
    for i in range(len(text1)):
        if text1[i].isalpha():
            counterLetters = counterLetters + 1
    return counterLetters
    
def count_words(text2):
    countWords = 1
    for j in range(len(text2)):
        if text2[j] == " ":
            countWords = countWords + 1
    return countWords
    
def count_sentences(text3):
    countSentences = 0
    for k in range(len(text3)):
        if text3[k] == "." or text3[k] == "!" or text3[k] == "?":
            countSentences = countSentences + 1
    return countSentences

main()