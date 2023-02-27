# A = [7, 5, 11, 33]
A = [15, 12, 10, 6, 5, 1]
A = [6, 28, 7, 12, 10, 14, 5, 9, 4, 8, 18]
n = len(A)
p = 7

maxVal = 0
secondMaxVal = 0

for i in range(n):
    print(i, A[i], maxVal, secondMaxVal)
    if A[i] % p != 0:
        if A[i] > maxVal:
            secondMaxVal = maxVal
            maxVal = A[i]
        elif maxVal > A[i] > secondMaxVal:
            secondMaxVal = A[i]
        if secondMaxVal > maxVal:
            maxVal, secondMaxVal = secondMaxVal, maxVal
print(maxVal * secondMaxVal, maxVal, secondMaxVal)

