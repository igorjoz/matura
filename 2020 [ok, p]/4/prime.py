def is_prime(n):
    if n == 0 or n == 1:
        return False
    elif n == 2:
        return True
    for i in range(2, n-1):
        if n % i == 0:
            return False
    else:
        return True


prime_numbers = []

for i in range (100):
    if is_prime(i):
        prime_numbers.append(i)

print(len(prime_numbers), prime_numbers)