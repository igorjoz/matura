def calc(num):
    sum = 1
    i = 2

    while i * i <= num:
        if num % i == 0:
            sum += i
            if num // i != i:
                sum += num // i
        i += 1
    return sum


a = 140

num = calc(a) - 1
num2 = calc(num) - 1

print(num, num2)

if num2 == a:
    print(num)
else:
    print("NIE")
