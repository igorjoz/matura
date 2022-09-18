from string import *

file = open("instrukcje.txt", "r")
lines = file.readlines()
# print(lines)
file.close()

instructions = list(map(lambda line: line.strip().split(), lines))
# print(instructions)

string = ""

for instruction in instructions:
    givenOrder = instruction[0]
    givenLetter = instruction[1]
    if givenOrder == "DOPISZ":
        string += givenLetter
    elif givenOrder == "ZMIEN":
        string = string[0:-1] + givenLetter
    elif givenOrder == "USUN":
        string = string[0:-1]
    elif givenOrder == "PRZESUN":
        for index in range(len(string)):
            if string[index] == givenLetter:
                characterIndex = index
                character = string[index]
                characterValue = ord(character)
                if character == "Z":
                    newCharacter = "A"
                else:
                    newCharacter = chr(characterValue + 1)
                # print(characterIndex, character, characterValue, newCharacter)
                string = string[0:index] + newCharacter + string[index + 1:]
                break

# 4.1
print(len(string))

# 4.2
maxCounter = 1
maxInstruction = instructions[0][0]
counter = 1
currentInstruction = instructions[0][0]

for index in range(1, len(instructions)):
    instruction = instructions[index][0]
    if instruction == currentInstruction:
        counter += 1

    if counter > maxCounter:
        maxCounter = counter
        maxInstruction = instruction

    if instruction != currentInstruction:
        counter = 1
        currentInstruction = instruction
print(maxInstruction, maxCounter)

# 4.3
letters = {}
alphabet = ascii_uppercase
maxLetterCount = 0
maxLetter = ""

for letter in alphabet:
    letters[letter] = 0

for instruction in instructions:
    if instruction[0] == "DOPISZ":
        letter = instruction[1]
        letters[letter] += 1
        if letters[letter] > maxLetterCount:
            maxLetterCount = letters[letter]
            maxLetter = letter
print(maxLetter, maxLetterCount)

# 4.4
print(string)
