import os
import re
fileNToOpen = input("Input File?\n")

fileNToWrite = input("Output File?\n")

fileToRead = open(fileNToOpen, 'r')
fileToWrite = open(fileNToWrite, 'w')
pattern = r"^\d+\."
content = fileToRead.readlines()
newcontent = []
for line in content:
    if re.match(pattern, line) != None:
        newcontent.append("# " + line)
    else:
        newcontent.append(line)

fileToWrite.writelines(content)

fileToWrite.close()
fileToRead.close()
    
