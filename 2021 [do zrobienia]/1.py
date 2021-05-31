n = int(input())

newNum = 0
mpy = 1

while n > 0:
    print((9 - (n % 10)) * mpy)
    newNum = newNum + (9 - (n % 10)) * mpy
    n //= 10
    mpy *= 10

print(newNum)
