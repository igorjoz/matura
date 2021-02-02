from math import *

def isPrime(n):
    if n == 0 or n == 1:
        return False
    elif n == 2:
        return True
    for i in range(2, n-1):
        if n % i == 0:
            return False
    else:
        return True


even_numbers = []
primes = []

# generate prime numbers
for i in range(100):
    if isPrime(i):
        primes.append(i)
print("\n", len(primes), primes, "\n")

data_file = open("pary.txt", "r")

if data_file.readable():

    output = open("4.1.txt", "w")

    # print(data_file.read())
    file_lines = data_file.readlines()
    # print(file_lines)

    for line in file_lines:
        file_number = int(line.split()[0])
        if file_number % 2 == 0:
            even_numbers.append(file_number)
    print(even_numbers)
    print(len(even_numbers))

    for number in even_numbers:
        num_prime_combinations = []
        biggest_difference = ""
        biggest_difference_primes = []
        for prime1 in primes:
            for prime2 in primes:
                combination = prime1 + prime2
                if combination == number:
                    # print(combination, number)
                    difference = abs(prime1 - prime2)
                    if biggest_difference == "":
                        biggest_difference = difference
                        biggest_difference_primes = [prime1, prime2]
                    elif difference > biggest_difference:
                        biggest_difference = difference
                        biggest_difference_primes = [prime1, prime2]
                    # print(difference)
                    num_prime_combinations.append([prime1, prime2])
        # print(num_prime_combinations)
        if biggest_difference_primes[0] > biggest_difference_primes[1]:
            temp = biggest_difference_primes[0]
            biggest_difference_primes[0] = biggest_difference_primes[1]
            biggest_difference_primes[1] = temp
        print(biggest_difference_primes)
        output.write(str(number))
        output.write(" ")
        output.write(str(biggest_difference_primes[0]))
        output.write(" ")
        output.write(str(biggest_difference_primes[1]))
        output.write("\n")

    output.close()


else:
    print("problem z plikiem")

data_file.close()
