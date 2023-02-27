def isKSimilar(n, A, B, k):
    for i in range(0, n):
        j = (i + k) % n
        if A[i] != B[j]:
            # print("FAŁSZ", i, j, A, B)
            return False
    # print("PRAWDA", k)
    return True


def isSimilar(n, A, B):
    for i in range(0, n):
        if isKSimilar(n, A, B, i):
            print("Is " + str(i) + " similar")
            return True
    return False

A = [1, 2, 3, 4, 5]
B = [3, 4, 5, 1, 2]
k = 2
n = len(A)

print(isKSimilar(n, A, B, k))

# 1.3
print(isSimilar(n, A, B))
