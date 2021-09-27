inputFile = open("sygnaly.txt", "r")
outputFile = open("wyniki4.txt", "w")

lines = inputFile.readlines()

strings = list(map(lambda line: line.strip(), lines))

# 4.1

counter = 1
hiddenMessage = ""
for string in strings:
    # print(string)
    if counter % 40 == 0:
        hiddenMessage += string[9]
    counter += 1

print(hiddenMessage)

outputFile.write("4.1:\n")
outputFile.write(hiddenMessage + "\n")

# 4.2

maxUniqueLettersQuantity = 0
maxUniqueLettersString = ""
for string in strings:
    uniqueLetters = []
    for letter in string:
        if letter not in uniqueLetters:
            uniqueLetters.append(letter)
    # print(len(uniqueLetters), uniqueLetters)
    if len(uniqueLetters) > maxUniqueLettersQuantity:
        maxUniqueLettersQuantity = len(uniqueLetters)
        maxUniqueLettersString = string

outputFile.write("\n4.2:\n")
print(maxUniqueLettersString + " " + str(maxUniqueLettersQuantity))
outputFile.write(maxUniqueLettersString + " " + str(maxUniqueLettersQuantity))

# 4.3
outputFile.write("\n\n4.3:\n")
for string in strings:
    areLettersCloseEnough = True
    letters = [char for char in string]
    minLetter = min(letters)
    maxLetter = max(letters)
    # print(minLetter, maxLetter, abs(ord(minLetter) - ord(maxLetter)), string)
    if abs(ord(minLetter) - ord(maxLetter)) <= 10:
        print("--", string)
        outputFile.write(string + "\n")

