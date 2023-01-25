# 3.1
s = "abcdefghabbcccdddd"
counter = 0
letters = []
for letter in s:
    if letter not in letters:
        counter += 1
        letters.append(letter)

print(letters)
print(counter)

# 3.3
dictionary = {
    "January": "Styczeń",
    "February": "Luty",
}

print(dictionary)
print(dictionary["January"])

v = ["00101001", "11000100"]
n = len(v)
r = 3
t = {
    "001": "H",
    "010": "A",
    "011": "N",
    "100": "I",
    # "01": "K",
    # "10": "A",
    # "11": "J",
}
bity = 3

string = ""
bits = ""

for byte in v:
    bits += byte
    print(byte)
print(bits)

for index in range(0, len(bits), bity):
    letterBits = bits[index: index + bity]
    # print(letterBits)
    if len(letterBits) == bity:
        letter = t[letterBits]
        string += letter
        print(letter)
print(string)
