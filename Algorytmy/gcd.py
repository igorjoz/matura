def gcd(a, b):
    while a != 0 and b != 0:
        if a >= b:
            a %= b
        else:
            b %= a
    return a + b


def gcdRecursive(a, b):
    if a == 0 or b == 0:
        return a + b
    elif a >= b:
        return gcdRecursive(a % b, b)
    else:
        return gcdRecursive(a, b % a)


result = gcd(70, 50)
print(result)

result = gcdRecursive(5, 10)
print(result)

print(100000 // 3211)
print(100000 % 3211)
