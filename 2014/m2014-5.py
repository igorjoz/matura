inputFile = open("dziennik.txt", "r")
outputFile = open("wynik5.txt", "w")

lines = inputFile.readlines()
nums = list(map(lambda line: int(line), lines))
print(nums)

# 5.1
previousNum = nums[0]
firstNumOfString = nums[0]
streakCounter = 1
maxStreakCounter = 1
longerThanThreeStreaksCounter = 0
streakNums = [nums[0]]
maxStreakNums = [nums[0]]
dayCounter = 2
minNum = nums[0]
maxNum = nums[0]
minNumDay = 1
maxNumDay = 1

for index in range(1, len(nums)):
    num = nums[index]

    if minNum > num:
        minNum = num
        minNumDay = dayCounter

    if maxNum < num:
        maxNum = num
        maxNumDay = dayCounter

    if num > previousNum:
        streakCounter += 1
        streakNums.append(num)
        print(firstNumOfString, previousNum, num, streakCounter)
    else:
        firstNumOfString = num
        streakCounter = 1
        streakNums = [num]
    previousNum = num

    if maxStreakCounter < streakCounter:
        maxStreakCounter = streakCounter
        maxStreakNums = streakNums

    if streakCounter == 4:
        longerThanThreeStreaksCounter += 1

    dayCounter += 1

print(longerThanThreeStreaksCounter)
outputFile.write("5.1:\n")
outputFile.write(str(longerThanThreeStreaksCounter) + "\n\n")

# 5.2
print(minNum, maxNum)
outputFile.write("5.2:\n")
outputFile.write("Najkrótszy skok: " + str(minNum) + ", dzień: " + str(minNumDay) + "\n")
outputFile.write("Najdłuższy skok: " + str(maxNum) + ", dzień: " + str(maxNumDay) + "\n\n")

# 5.3
print(maxStreakNums)
outputFile.write("5.3:\n")
outputFile.write("Ilość dni: " + str(len(maxStreakNums)) + "\n")
outputFile.write("Poprawa wyniku o: " + str(maxStreakNums[-1] - maxStreakNums[0]) + "cm\n")
