# --- 1.2
n = 0
k = 54321
kCopy = k
digits = []

while k > 0:
    # digits[n] = k % 10
    digits.append(k % 10)
    k //= 10
    n += 1
print(n)
print(digits)

k = kCopy

# --- 1.3
sum = 0
isNarcissistic = False
for index in range(n):
    sum += pow(digits[index], n)
print(k, sum)
isNarcissistic = (k == sum)
print(isNarcissistic)
