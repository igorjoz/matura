#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <iterator>
#include <bitset>
#include <string>
#include <algorithm>

std::vector<unsigned> getPrimeNumbers(unsigned n);
bool isPrimeNumber(unsigned n);
unsigned sumOfDigits(unsigned n);
unsigned sumOfBinaryDigits(unsigned n);
bool isSuperPrimeNumber(unsigned n);
bool isSuperBinaryPrimeNumber(unsigned n);
std::vector<unsigned>::iterator moveIterator(std::vector<unsigned> &vec, unsigned target);

int main()
{
    auto primeNumber = getPrimeNumbers(100000);
    std::ofstream txt1{"1.txt"};
    std::ofstream txt2{"2.txt"};
    std::ofstream txt3{"3.txt"};

    auto it = primeNumber.begin();
    unsigned quantityBPrime = 0;

    // <2; 1000>

    while (*it++ < 1000) {
        if (isSuperBinaryPrimeNumber(*it)) {
            txt1 << *it << '\n';
            quantityBPrime++;
        }
    }

    std::cout << "a) Liczb super B pierwszych w przedziale <2; 1000>: " << quantityBPrime << '\n';

    // <100; 10000>
    it = moveIterator(primeNumber, 100);
    quantityBPrime = 0;
    unsigned sumOfBPrime = 0;

    while (*it++ < 10000) {
        if (isSuperBinaryPrimeNumber(*it)) {
            txt2 << *it << '\n';
            quantityBPrime++;
            sumOfBPrime += *it;
        }
    }

    std::cout << "a) Liczb super B pierwszych w przedziale <100; 10000>: " << quantityBPrime << '\n';

    // <1000; 100000>
    it = moveIterator(primeNumber, 1000);
    quantityBPrime = 0;

    while (*it++ < 100000) {
        if (isSuperBinaryPrimeNumber(*it)) {
            txt3 << *it << '\n';
            quantityBPrime++;
        }
    }

    std::cout << "a) Liczb super B pierwszych w przedziale <1000; 100000>: " << quantityBPrime << '\n';

    unsigned quantityPrime = 0;

    for (unsigned i = 100; i < 10000; ++i)
        if (isPrimeNumber(sumOfDigits(i)))
            quantityPrime++;

    std::cout << "\nb) W przedziale <100; 10000> jest " << quantityPrime << " liczb, ktorych suma daje liczbe pierwsza\n";

    if (isPrimeNumber(sumOfBPrime))
        std::cout << "\nc) Tak\n";
    else
        std::cout << "\nc) Nie\n";

    return 0;
}

std::vector<unsigned> getPrimeNumbers(unsigned n)
{
    std::vector<unsigned> helperArray(n + 1, 0);
    std::vector<unsigned> primeNumbers;
    unsigned sqrtN = std::sqrt(n);

    for (unsigned i = 2; i < sqrtN; ++i)
        if (helperArray.at(i) == 0)
            for (unsigned j = i * i; j <= n; j += i)
                helperArray.at(j) = 1;

    for (unsigned i = 2; i <= n; ++i)
        if (helperArray.at(i) != 1)
            primeNumbers.push_back(i);

    return primeNumbers;
}

unsigned sumOfDigits(unsigned n)
{
    unsigned sum = 0;

    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

unsigned sumOfBinaryDigits(unsigned n)
{
    std::string numAsString = std::bitset<64>(n).to_string();

    unsigned sum = std::count_if(numAsString.begin(), numAsString.end(), [](char c){ return c == '1'; });

    return sum;
}

bool isPrimeNumber(unsigned n)
{
    if (n == 2)
        return true;

    if (n % 2 == 0 && n != 2 || n < 2)
        return false;

    unsigned sqrtN = std::sqrt(n);

    for (unsigned i = 3; i <= sqrtN; i += 2)
        if (n % i == 0)
            return false;

    return true;
}

bool isSuperPrimeNumber(unsigned n)
{
    unsigned sum = sumOfDigits(n);

    return isPrimeNumber(sum);
}

bool isSuperBinaryPrimeNumber(unsigned n)
{
    unsigned sum = sumOfBinaryDigits(n);

    return isSuperPrimeNumber(n) && isPrimeNumber(sum);
}

std::vector<unsigned>::iterator moveIterator(std::vector<unsigned> &vec, unsigned target)
{
    auto it = vec.begin();

    while (*it < target)
        it++;

    return it;
}
