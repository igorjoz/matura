def d(T, s, counter):
    while s // 2 >= 1 and T[s] > T[s // 2]:
        counter += 1
        temp = T[s]
        T[s] = T[s // 2]
        T[s // 2] = temp
        s //= 2


n = 0
# T = [0, 26, 3, 5, -4]
# T = [0, 36, 15, 17, 3]
# T = [0, 27, 6, 13, 4, -3, -2, -3]
T = [0]
args = [6, -4, 12, 27, 26, 8]

counter = 1

for arg in args:
    n += 1
    T.append(arg)
    s = n
    d(T, s, counter)
    print(T)
    print(counter)

print(T)
print(counter)
