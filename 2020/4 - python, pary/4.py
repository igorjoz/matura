from math import *


def isPrime(num):
    if num < 2:
        return False
    if num == 2:
        return True
    if num % 2 == 0:
        return False

    for divider in range(3, int(sqrt(num)) + 1, 2):
        if num % divider == 0:
            return False
    return True


inputFile = open("pary.txt", "r")
lines = inputFile.readlines()
inputFile.close()

outputFile = open("wyniki4.txt", "w")

pairs = list(map(lambda line: [int(line.strip().split()[0]), line.strip().split()[1]], lines))
nums = list(map(lambda pair: pair[0], pairs))
words = list(map(lambda pair: pair[1], pairs))

# print(pairs)
# print(nums)
# print(words)

evenNums = [num for num in nums if num % 2 == 0]
print(evenNums)

primeNums = []
for num in range(2, 100):
    if isPrime(num):
        primeNums.append(num)
print(primeNums)

# 4.1
nextNum = False
result = []

for num in evenNums:
    for i in primeNums:
        if nextNum:
            nextNum = False
            break
        else:
            for j in range(len(primeNums) - 1, 0, -1):
                if i + primeNums[j] == num:
                    result.append([num, i, primeNums[j]])
                    nextNum = True
                    break
print(result)

outputFile.write("4.1:\n")
for line in result:
    resultLine = str(line[0]) + " " + str(line[1]) + " " + str(line[2]) + " "
    print(resultLine)
    outputFile.write(resultLine + "\n")

# 4.2
outputFile.write("\n4.2:\n")
for word in words:
    maxStreakValue = 1
    maxStreakChar = word[0]
    currentStreakValue = 1
    currentStreakChar = word[0]
    for i in range(1, len(word)):
        if word[i] == currentStreakChar:
            currentStreakValue += 1
        else:
            if currentStreakValue > maxStreakValue:
                maxStreakValue = currentStreakValue
                maxStreakChar = currentStreakChar
            currentStreakValue = 1
            currentStreakChar = word[i]

        if currentStreakValue > maxStreakValue:
            maxStreakValue = currentStreakValue
            maxStreakChar = currentStreakChar
    print(maxStreakChar * maxStreakValue, maxStreakValue)
    outputFile.write(str(maxStreakChar * maxStreakValue) + " " + str(maxStreakValue) + "\n")

# 4.3
minNum = 100
minPairs = []
minWords = []
matchingPairs = []
for pair in pairs:
    num, word = pair
    if num == len(word):
        matchingPairs.append(pair)
        minNum = min(minNum, num)

for pair in matchingPairs:
    num, word = pair
    if num == minNum:
        minPairs.append(pair)
        minWords.append(word)
minWord = min(minWords)

print(minNum)
print(minPairs)
print(minWord)

outputFile.write("\n4.3:\n")
outputFile.write(str(len(minWord)) + " " + minWord + "\n")

outputFile.close()
