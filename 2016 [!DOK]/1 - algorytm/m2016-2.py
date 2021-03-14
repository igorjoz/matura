def findDividers(num):
    for i in range(1, (num // 2) + 1):
        if num % i == 0:
            yield i


num1 = int(input())

dividers1 = list(findDividers(num1))
print(dividers1)

dividers1Sum = sum(dividers1)
print(dividers1Sum)

num2 = dividers1Sum - 1

dividers2 = list(findDividers(num2))
print(dividers2)
dividers2Sum = sum(dividers2)
print(dividers2Sum, dividers2Sum - 1)

if dividers2Sum - 1 == num1:
    print("TAK")
else:
    print("NIE")
