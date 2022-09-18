file = open("liczby.txt")

lines = file.readlines()
nums = list(map(lambda line: int(line), lines))

happyNums = []

for num in nums:
    numCopy = num
    possibleHappyNums = []
    digitsSum = 0
    while digitsSum != 1:
        digitsSum = 0
        while num > 0:
            digit = num % 10
            digitsSum += digit
            print(num, digit)
            num //= 10
        print("digitsSum: ", digitsSum)
        if digitsSum == 0:
            break
        elif digitsSum == 1:
            happyNums.append(numCopy)

