from math import gcd


factorials = []
factorialValue = 1
factorials.append(1)
for i in range(1, 10):
    factorialValue *= i
    factorials.append(factorialValue)
print("factorials: ", factorials)


def getSumOfFactorialsOfDigitsSum(num):
    numStr = str(num)
    sumValue = 0
    for digit in numStr:
        sumValue += factorials[int(digit)]
    return sumValue


outputFile = open("wyniki4.txt", "w")

with open("liczby.txt") as inputFile:
    nums = []
    for line in inputFile.readlines():
        nums.append(int(line.strip()))
    print(nums)

    # 4.1
    powsOfThree = set()
    powOfThree = 1
    while powOfThree < 100000:
        powsOfThree.add(powOfThree)
        powOfThree *= 3
    print(powsOfThree)

    counter = 0
    for num in nums:
        if num in powsOfThree:
            counter += 1
    print(counter)

    outputFile.write("4.1.: ")
    outputFile.write(str(counter))
    outputFile.write("\n\n")

    # 4.2
    result2 = []
    for num in nums:
        sumOfFactorialsOfDigitsSum = getSumOfFactorialsOfDigitsSum(num)
        if num == sumOfFactorialsOfDigitsSum:
            print(num, sumOfFactorialsOfDigitsSum)
            result2.append(num)
    outputFile.write("4.2.:\n")
    for num in result2:
        outputFile.write(str(num))
        outputFile.write("\n")
    outputFile.write("\n")

    # 4.3
    maxSequenceLength = -1
    maxFirstValue = -1
    maxGcdValue = -1

    # brute solution, but matura practical part doesn't care about time complexity
    for i in range(len(nums) - 1):
        firstValue = nums[i]
        sequenceLength = 2
        gcdValue = gcd(nums[i], nums[i + 1])

        for j in range(i + 2, len(nums)):
            if gcd(gcdValue, nums[j]) == 1:
                break
            else:
                sequenceLength += 1
                gcdValue = gcd(gcdValue, nums[j])

        if sequenceLength > maxSequenceLength:
            maxSequenceLength = sequenceLength
            maxFirstValue = firstValue
            maxGcdValue = gcdValue

    print(maxFirstValue, maxSequenceLength, maxGcdValue)
    result3 = str(maxFirstValue) + " " + str(maxSequenceLength) + " " + str(maxGcdValue)
    outputFile.write("4.3.: ")
    outputFile.write(result3)
