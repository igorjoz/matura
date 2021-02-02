A = [1, 4, 7, 9, 1, 3, 7, 7, 7, 4, 7]
B = [1, 3, 7, 7, 7, 4, 7, 1, 4, 7, 9]

n = 11
k = 4

# A = [5, 7, 9]
# B = [5, 7, 9]

# n = 3
# k = 0

def czy_k_podobne(n, A, B, k):
    if k == 0 and A != B:
        return False
    else:
        for i in range(k):
            print("a", A[i], B[n - k + i], A[i] != B[n - k + i])
            if A[i] != B[n - k + i]:
                return False
        for i in range(n - k):
            print("b", A[k + i], B[i], A[k + i] != B[i])
            if A[k + i] != B[i]:
                return False
    return True


wynik = czy_k_podobne(n, A, B, k)
print(wynik)
