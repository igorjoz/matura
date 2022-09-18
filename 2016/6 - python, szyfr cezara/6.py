def caesar(word, key):
    length = len(word)
    encryptedWord = ""
    for index in range(length):
        currentLetterIndex = (ord(word[index]) % 65)
        encryptedLetterIndex = ((currentLetterIndex + key) % 26) + 1
        encryptedLetterASCIIValue = encryptedLetterIndex + 64
        encryptedLetter = chr(encryptedLetterASCIIValue)
        # print(word[index], currentLetterIndex, encryptedLetterIndex, encryptedLetterASCIIValue, encryptedLetter)
        encryptedWord += encryptedLetter
    return encryptedWord


# 6.1 - encryption
inputFile1 = open("dane_6_1.txt", "r")
outputFile1 = open("wyniki_6_1.txt", "w")

outputFile1.write("6.1:\n")

key = 107
key = 107 % 26  # 26: quantity of alphabet letters

lines = list(map(lambda line: line.strip(), inputFile1.readlines()))
print(lines)
print(key)

for word in lines:
    encryptedWord = caesar(word, key)
    # print(word, encryptedWord)
    outputFile1.write(encryptedWord + "\n")

# 6.2 - decryption
inputFile2 = open("dane_6_2.txt", "r")
outputFile2 = open("wyniki_6_2.txt", "w")

outputFile2.write("6.2:\n")

lines = list(map(lambda line: line.strip().split(), inputFile2.readlines()))
for line in lines:
    word = line[0]
    length = len(word)
    if len(line) == 2:  # błąd w danych do zadania 6.2 - obejście
        line[1] = int(line[1])
        key = 26 - (line[1] % 26)
        decryptedWord = caesar(word, key)
        print(word, decryptedWord)
        outputFile2.write(decryptedWord + "\n")
encryptedWords = []

# 6.3
inputFile3 = open("dane_6_3.txt", "r")
outputFile3 = open("wyniki_6_3.txt", "w")

outputFile3.write("6.3:\n")

lines = list(map(lambda line: line.strip().split(), inputFile3.readlines()))

for line in lines:
    isEncryptedProperly = False
    word = line[0]
    possibleEncryption = line[1]
    for key in range(26):
        if (caesar(word, key) == possibleEncryption):
            isEncryptedProperly = True
            break
    if not isEncryptedProperly:
        print(word)
        outputFile3.write(word + "\n")
