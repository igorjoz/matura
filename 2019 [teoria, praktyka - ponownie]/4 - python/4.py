from math import gcd

inputFile = open("liczby.txt", "r")
outputFile = open("wyniki4.txt", "w")

powsOfThree = []
currentNum = 1
while currentNum <= 100000:
    powsOfThree.append(currentNum)
    currentNum *= 3
print("powsOfThree:", powsOfThree)

factorials = [1, 1]
currentFactorial = 1
for i in range(2, 10):
    currentFactorial *= i
    factorials.append(currentFactorial)
print("factorials:", factorials)

nums = list(map(lambda line: int(line), inputFile.readlines()))
print("nums:", nums)

# 4.1
powsOfThreeCount = 0
for num in nums:
    if num in powsOfThree:
        powsOfThreeCount += 1
print("powsOfThreeCount:", powsOfThreeCount)
outputFile.write("4.1:\n")
outputFile.write(str(powsOfThreeCount))

# 4.2
outputFile.write("\n\n4.2:\n")
factorialsOfDigitsEqualsNumList = []
for num in nums:
    factorialsSum = 0
    for digit in str(num):
        factorialsSum += factorials[int(digit)]
    if factorialsSum == num:
        factorialsOfDigitsEqualsNumList.append(num)
        outputFile.write(str(num) + "\n")
print("factorialsOfDigitsEqualsNumList:", factorialsOfDigitsEqualsNumList)

# 4.3
outputFile.write("\n4.3:\n")

gcdValue = nums[0]
currentStrLength = -1
currentFirstNum = -1

maxStrLength = -1
maxStrGcd = -1
maxStrFirstNum = -1
maxStrFirstNumIndex = -1

for i in range(1, len(nums)):
    currentFirstNum = nums[i - 1]
    currentStrLength = 1
    gcdValue = currentFirstNum
    for j in range(i, len(nums)):
        gcdValue = gcd(gcdValue, nums[j])
        if gcdValue == 1:
            break
        currentStrLength += 1
        if currentStrLength > maxStrLength:
            maxStrLength = currentStrLength
            maxStrGcd = gcdValue
            maxStrFirstNum = currentFirstNum
            maxStrFirstNumIndex = i

print("maxStrLength:", maxStrLength)
print("maxStrFirstNum:", maxStrFirstNum)
print("maxStrFirstNumIndex:", maxStrFirstNumIndex)
print("maxStrGcd:", maxStrGcd)

outputFile.write("pierwsza liczba ciagu " + str(maxStrFirstNum) + "\n")
outputFile.write("dlugosc " + str(maxStrLength) + "\n")
outputFile.write("najwiekszy wspolny dzielnik " + str(maxStrGcd) + "\n")
