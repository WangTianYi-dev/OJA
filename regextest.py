import re

pattern = input("Pattern? \n")
while True:
    text = input("Text?\n")
    matchobj = re.match(pattern, text)
    if matchobj:
        print("True")
    else:
        print("False")