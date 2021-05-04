k = int(input())
x = int(input())
y = int(input())
maxValue = 0

if x < y:
    maxValue = y - x
else:
    maxValue = x - y

counter = 1
num = 2

for i in range(k):
    if num - 1 >= maxValue:
        print(counter)
        break
    else:
        num *= 2
        counter += 1
