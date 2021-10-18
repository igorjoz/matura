inputFile = open("liczby.txt", "r")
outputFile = open("wyniki4.txt", "w")

lines = list(map(lambda line: line.strip(), inputFile.readlines()))

# 4.1
moreZerosCounter = 0
for line in lines:
    zerosCounter = 0
    onesCounter = 0
    for letter in line:
        if letter == "0":
            zerosCounter += 1
        elif letter == "1":
            onesCounter += 1
    # print(zerosCounter, onesCounter, line)
    if zerosCounter > onesCounter:
        moreZerosCounter += 1
print(moreZerosCounter)
outputFile.write("4.1: " + str(moreZerosCounter) + "\n\n")

# 4.2
nums = []
for line in lines:
    num = int(line, 2)
    nums.append(num)
    print(num)

divisibleBy2Counter = 0
divisibleBy8Counter = 0
for num in nums:
    if num % 2 == 0:
        divisibleBy2Counter += 1
    if num % 8 == 0:
        divisibleBy8Counter += 1
print("divisibleBy2Counter", divisibleBy2Counter)
print("divisibleBy8Counter", divisibleBy8Counter)

outputFile.write("4.2:\n")
outputFile.write("Podzielne przez 2: " + str(divisibleBy2Counter) + "\n")
outputFile.write("Podzielne przez 8: " + str(divisibleBy8Counter) + "\n\n")

# 4.3
# find max & min value - print row of max & min value
minValue = min(nums)
maxValue = max(nums)
print(minValue, maxValue)

i = 1
for num in nums:
    if num == minValue:
        minValueIndex = i
    elif num == maxValue:
        maxValueIndex = i
    i += 1
print(minValueIndex, maxValueIndex)

outputFile.write("4.3:\n")
outputFile.write("wiersz najmniejszej wartości: " + str(minValueIndex) + "\n")
outputFile.write("wiersz największej wartości: " + str(maxValueIndex) + "\n")

