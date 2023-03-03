inputFile = open("sygnaly.txt", "r")
lines = inputFile.readlines()
inputFile.close()

words = list(map(lambda word: word.strip(), lines))

print(words)
print(len(words))

# 4.1
decryptedMessage = ""
for i in range(39, len(words), 40):
    char = words[i][9]
    print(char)
    decryptedMessage += char
print(decryptedMessage)

# 4.2
maxDifferentCharsNumber = 0
maxDifferentCharsWord = ""

for word in words:
    charsSet = set()
    for character in word:
        charsSet.add(character)
    print(charsSet, len(charsSet))

    if maxDifferentCharsNumber < len(charsSet):
        maxDifferentCharsNumber = len(charsSet)
        maxDifferentCharsWord = word
print(maxDifferentCharsWord, maxDifferentCharsNumber)

# 4.3
correctWords = []
for word in words:
    maxCharacterValue = 0
    minCharacterValue = 999
    for character in word:
        characterValue = ord(character)
        minCharacterValue = min(minCharacterValue, characterValue)
        maxCharacterValue = max(maxCharacterValue, characterValue)
    if abs(maxCharacterValue - minCharacterValue) <= 10:
        correctWords.append(word)
    # i = 1
    # isCorrectWord = True
    # lastCharacterValue = ord(word[0])

    # while isCorrectWord and i < len(word):
    #     if abs(lastCharacterValue - ord(word[i])) > 10:
    #         isCorrectWord = False
    #     print(lastCharacterValue, ord(word[i]), abs(lastCharacterValue - ord(word[i])))
    #     lastCharacterValue = ord(word[i])
    #     i += 1
    # if isCorrectWord:
    #     correctWords.append(word)
print(correctWords)
print(len(correctWords))

print("4.3:")
for word in correctWords:
    print(word)

