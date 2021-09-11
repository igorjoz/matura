array = [5, 99, 3, 7, 111, 13, 4, 24, 4, 8]
array = [5, 99, 5, 13, 51, 21, 13, 21, 21, 21, 3, 7, 111, 13, 4, 24, 4, 8]
array = [5, 99, 5, 13, 51, 21, 13, 21, 21, 21, 3, 7, 111, 13, 8, 12, 4, 24, 4, 8, 16, 2, 2, 4]

print(array)

left = 0
right = len(array) - 1

while left <= right:
    middle = (left + right) // 2
    print("l:", left, "m:", middle, "r:", right, "liczba:", array[middle])
    if array[middle] % 2 == 0 and array[middle - 1] % 2 == 1:
        print("znaleziono:", array[middle], "to pierwsza liczba parzysta")
        print("indeks: ", middle)
        break
    elif array[middle] % 2 == 1:
        print("nieparzysta, szukaj w prawo")
        left = middle + 1
    else:
        print("parzysta, ale nie pierwsza, szukaj w lewo")
        right = middle - 1
