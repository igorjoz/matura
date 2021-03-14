def dividersSum(num):
    sum = 0
    for i in range(1, (num // 2) + 1):
        if num % i == 0:
            sum += i
    return sum


a = int(input())

divSumA = dividersSum(a)
print(divSumA, divSumA - 1)

if dividersSum(divSumA - 1) - 1 == a:
    print("TAK")
else:
    print("NIE")
