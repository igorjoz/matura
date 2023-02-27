mpy = 1
newNum = 0
n = 13445

while n > 0:
    newNum = newNum + (9 - (n % 10)) * mpy
    n //= 10
    # n = n // 10
    mpy *= 10
print(newNum)
