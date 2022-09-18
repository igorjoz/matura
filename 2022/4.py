file = open("liczby.txt", "r")
nums = list(map(lambda num: int(num), file.readlines()))
# print(len(nums))
# print(nums)
file.close()

# 4.1
isFirstFound = False
firstNum = -1
counter = 0

for num in nums:
    # print(str(num)[0],  str(num)[-1], str(num)[0] == str(num)[-1])
    if str(num)[0] == str(num)[-1]:
        if not isFirstFound:
            firstNum = num
            isFirstFound = True
        counter += 1
        # print(num, str(num)[0], str(num)[-1])
print(counter)
print(firstNum)

# 4.2
numsDividers = []
numsDividersSetsList = []

for index in range(len(nums)):
    currentNum = nums[index]
    currentDivider = 2
    currentDividersList = []
    while currentNum > 1:
        if currentNum % currentDivider == 0:
            currentDividersList.append(currentDivider)
            currentNum //= currentDivider
        else:
            currentDivider += 1
        # print(currentNum, currentDivider)
    numsDividers.append(currentDividersList)
    numsDividersSetsList.append(set(currentDividersList))
print(numsDividers)

maxDividers = 0
maxDividersNum = 0
maxVariousDividers = 0
maxVariousDividersNum = 0

for index in range(len(nums)):
    num = nums[index]
    dividers = numsDividers[index]
    dividersLength = len(dividers)
    dividersSet = numsDividersSetsList[index]
    dividersSetLength = len(dividersSet)
    if dividersLength > maxDividers:
        maxDividers = dividersLength
        maxDividersNum = num

    if dividersSetLength > maxVariousDividers:
        maxVariousDividers = dividersSetLength
        maxVariousDividersNum = num
    # print(num, dividers, dividersSet)

print(maxDividersNum, maxDividers)
print(maxVariousDividersNum, maxVariousDividers)

# 4.3
# a
outputFile = open("trojki.txt", "w")
combinations = []

for num1 in nums:
    for num2 in nums:
        if num2 % num1 == 0 and num1 != num2:
            for num3 in nums:
                if num3 % num2 == 0 and num2 != num3:
                    combination = [num1, num2, num3]
                    if combination not in combinations:
                        combinations.append(combination)
                    # distinctCombinations.add([num1, num2, num3])

print("LEN TRÓJKI: " + str(len(combinations)))
print(combinations)
for combination in combinations:
    line = ""
    for num in combination:
        line += str(num) + " "
    line += "\n"
    # print(line)
    outputFile.write(line)
outputFile.close()

# b
combinations = []
for num1 in nums:
    for num2 in nums:
        if num2 % num1 == 0 and num1 != num2:
            for num3 in nums:
                if num3 % num2 == 0 and num2 != num3:
                    for num4 in nums:
                        if num4 % num3 == 0 and num3 != num4:
                            for num5 in nums:
                                if num5 % num4 == 0 and num4 != num5:
                                    combination = [num1, num2, num3, num4, num5]
                                    if combination not in combinations:
                                        combinations.append(combination)

print("LEN PIĄTKI: " + str(len(combinations)))
print(combinations)
