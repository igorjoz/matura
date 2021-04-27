# 4.1 - ilość liczb, które są potęgami 3
# alternatywne rozwiązanie zadania: stworzenie tablicy z potęgami liczby 3 do potrzebnego zakresu i sprawdzenie, czy liczba się w nim zawiera
def isPowerOf3(number):
    if number % 3 == 0 or number == 1:
        while (True):
            if number == 1:
                return True
            elif number < 1:
                return False
            else:
                number /= 3


# 4.2 - Silnia liczby
def factorial(number):
    result = 1
    for i in range(1, number + 1):
        result *= i
    return result


# 4.2 - Czy liczba jest równa sumie silni cyfr
def isNumberEqualToSumOfDigitsFactorials(number):
    sum = 0
    for letter in str(number):
        sum += factorial(int(letter))
    return sum == number


# 4.3 - NWD - największy wspólny dzielnik
def nwd(a, b):
    while b:
        a, b = b, a % b
    return a


with open("liczby.txt", "r") as file:
    lines = file.readlines()
    # print(lines)
    numbers = list(map(lambda string: int(string), lines))
    # można tak, ale wystarczy sama zmiana na int
    # numbers = list(map(lambda str: int(str[:-1]), lines))
    # print(numbers)

    print("--- 4.1")
    counter = 0
    for number in numbers:
        if isPowerOf3(number):
            counter += 1
            print(number, counter)
    print("ilość liczb, które są potęgami 3:", counter)

    print("--- 4.2")
    print("liczby, które są równe sumie silni jej cyfr")
    for number in numbers:
        if isNumberEqualToSumOfDigitsFactorials(number):
            print(number)

    print("---4.3")
    counter = 1
    streakStartNumber = 0
    divider = 0

    maxCounter = 1
    maxStreakStartNumber = 0
    maxDivider = 0

    i = 2
    while i < len(numbers):
        if counter == 1 and nwd(numbers[i - 1], numbers[i]) != 1:
            i -= 1
            streakStartNumber = numbers[i - 1]
            divider = nwd(numbers[i - 1], numbers[i])
            counter += 1
        elif nwd(divider, nwd(numbers[i - 1], numbers[i])) != 1:
            counter += 1
            divider = nwd(divider, nwd(numbers[i - 1], numbers[i]))
            # print(nwd(divider, nwd(numbers[i - 1], numbers[i])), "---", numbers[i - 1], numbers[i], "---", counter)
        else:
            if maxCounter < counter:
                maxCounter = counter
                maxStreakStartNumber = streakStartNumber
                maxDivider = divider
            counter = 1
        i += 1
    if maxCounter < counter:
        maxCounter = counter
        maxStreakStartNumber = streakStartNumber
        maxDivider = divider
    print("początek:", maxStreakStartNumber)
    print("streak:", maxCounter)
    print("divider:", maxDivider)
