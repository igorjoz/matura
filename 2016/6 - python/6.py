import string


def caesarsCipher(word, key):
    key %= 26
    encrypted = ""
    alphabet = list(string.ascii_uppercase)
    for letter in word:
        letterIndex = alphabet.index(letter)
        shift = (letterIndex + key) % 26
        # print(letterIndex, shift, alphabet[shift])
        encrypted += alphabet[shift]
    return encrypted


def decodeCaesarsCipher(word, key):
    key %= 26
    key = 26 - key
    decrypted = ""
    alphabet = list(string.ascii_uppercase)
    for letter in word:
        letterIndex = alphabet.index(letter)
        shift = (letterIndex + key) % 26
        # print(letterIndex, shift, alphabet[shift])
        decrypted += alphabet[shift]
    return decrypted


input1 = open("dane_6_1.txt", "r")
output1 = open("wyniki_6_1.txt", "w")

input2 = open("dane_6_2.txt", "r")
output2 = open("wyniki_6_2.txt", "w")

input3 = open("dane_6_3.txt", "r")
output3 = open("wyniki_6_3.txt", "w")

# 1
key = 107

words = input1.readlines()
words = list(map(lambda word: word.strip(), words))
print(words)

# print(caesarsCipher("ABCDXYZ", 3))
for word in words:
    encrypted = caesarsCipher(word, key)
    output1.write(encrypted + "\n")


# 2
for i in range(700):
    line = input2.readline().strip()
    word, key = line.split()
    key = int(key)
    # print(word, key)

    decoded = decodeCaesarsCipher(word, key)
    output2.write(decoded + "\n")


# 3
for i in range(3000):
    line = input3.readline().strip()
    w1, w2 = line.split()
    hasCorrectEncryption = False
    print(w1, w2)
    for j in range(26):
        if caesarsCipher(w1, j) == w2:
            hasCorrectEncryption = True
    if not hasCorrectEncryption:
            output3.write(w1 + "\n")

    # decoded = decodeCaesarsCipher(word, key)
    # output2.write(decoded + "\n")


input1.close()
output1.close()

input2.close()
output2.close()

input3.close()
output3.close()
