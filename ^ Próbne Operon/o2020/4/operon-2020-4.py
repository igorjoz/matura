inputFile = open("dane.txt", "r")
nums = list(map(lambda line: int(line), inputFile.readlines()))
print(nums)

n = 10001
luckyNums = []

for index in range(1, n, 2):
    luckyNums.append(index)

print(luckyNums)

luckyNumIndex = 1
luckyNum = luckyNums[luckyNumIndex]

index = 2 * luckyNumIndex
numsToDelete = []

while index < len(luckyNums):
    numToDelete = luckyNums[index]
    # print(index, numToDelete)
    numsToDelete.append(numToDelete)
    index += luckyNum

    if index >= len(luckyNums):
        # print(numsToDelete)
        for numToDelete in numsToDelete:
            luckyNums.remove(numToDelete)
        # print(len(luckyNums), luckyNums)
        luckyNumIndex += 1
        index = 2 * luckyNumIndex
        if index < len(luckyNums):
            luckyNum = luckyNums[luckyNumIndex]
            numsToDelete = []
            print(index, len(luckyNums), luckyNums)

print(len(luckyNums))
print(luckyNums)
