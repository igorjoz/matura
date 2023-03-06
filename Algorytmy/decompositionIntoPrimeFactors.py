num = 1050403310

divider = 2
primeFactors = []

while num > 1:
    while num % divider == 0:
        primeFactors.append(divider)
        num //= divider
    divider += 1

print(primeFactors)
