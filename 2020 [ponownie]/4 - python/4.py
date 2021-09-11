from math import *


def isPrime(num):
    if num < 2:
        return False
    elif num == 2:
        return True

    for j in range(2, int(sqrt(num)) + 1):
        if num % j == 0:
            return False
    return True


primeNums = []
for i in range(2, 101):
    if isPrime(i):
        primeNums.append(i)
print(primeNums)

# with open("przyklad.txt", "r") as inputFile:
with open("pary.txt", "r") as inputFile:
    with open("wyniki4.txt", "w") as outputFile:
        lines = inputFile.readlines()

        # 4.1
        outputFile.write("4.1:\n")
        for line in lines:
            num, string = line.strip().split()
            num = int(num)

            if num % 2 == 0:
                maxDifferenceNums = [0, 0]
                for num1 in primeNums:
                    for num2 in primeNums:
                        if num1 + num2 == num and abs(num1 - num2) > abs(maxDifferenceNums[0] - maxDifferenceNums[1]):
                            maxDifferenceNums = [num1, num2]
                            print(num, maxDifferenceNums[0], maxDifferenceNums[1])
                            outputFile.write(str(num) + " " + str(maxDifferenceNums[0]) + " " + str(maxDifferenceNums[1]) + "\n")

        # 4.2
        outputFile.write("\n4.2:\n")
        for line in lines:
            num, string = line.strip().split()
            num = int(num)

            longestStringChar = ""
            longestCharCount = 0
            currentStringChar = ""
            currentCharCount = 0
            lastLetter = ""

            for letter in string:
                if letter == lastLetter:
                    currentCharCount += 1
                else:
                    currentCharCount = 1
                    currentStringChar = letter

                if currentCharCount > longestCharCount:
                    longestStringChar = currentStringChar
                    longestCharCount = currentCharCount

                lastLetter = letter

            print(longestStringChar, longestCharCount)
            outputFile.write(longestStringChar * longestCharCount + " " + str(longestCharCount) + "\n")

        # 4.3
        outputFile.write("\n4.3:\n")
        nums = []
        strings = []
        pairs = []
        for line in lines:
            num, string = line.strip().split()
            num = int(num)

            if num == len(string):
                nums.append(num)
                strings.append(string)
                pairs.append([num, string])

        print(pairs)
        minNum = min(nums)
        minNumStrings = []
        for pair in pairs:
            if pair[0] == minNum:
                minNumStrings.append(pair[1])
        print(minNumStrings)
        minString = min(minNumStrings)
        print(minString)
        outputFile.write(str(minNum) + " " + minString + "\n")


