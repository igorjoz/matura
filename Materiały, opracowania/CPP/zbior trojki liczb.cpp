// zad/odp 126/458
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>

unsigned long sumOfDigits(unsigned long num);
bool isPrime(unsigned long n);
bool correctScoreOfMultiply(const unsigned long &a, const unsigned long &b, const unsigned long &c);
bool iSRectangularTriangle(const unsigned long &a, const unsigned long &b, const unsigned long &c);
bool isTriangle(const unsigned long &a, const unsigned long &b, const unsigned long &c);
std::string toString(unsigned long val);

int main()
{
    std::ifstream data{"trojki.txt"};
    std::string task1;
    std::string task2;
    std::string task3;
    std::string task4;
    std::ofstream answer{"wyniki_trojki.txt"};
    unsigned long a;
    unsigned long b;
    unsigned long c;
    unsigned int countRow{0};
    unsigned int longest{0};
    unsigned int temp{0};

    while (data >> a >> b >> c) {

        if (sumOfDigits(a) + sumOfDigits(b) == c)
            task1 += toString(a) + ' ' + toString(b) + ' ' + toString(c) + '\n';

        if (isPrime(a) && isPrime(b) && correctScoreOfMultiply(a, b, c))
            task2 += toString(a) + ' ' + toString(b) + ' ' + toString(c) + '\n';

        if (iSRectangularTriangle(a, b, c))
            task3 += toString(a) + ' ' + toString(b) + ' ' + toString(c) + '\n';

        if (isTriangle(a, b, c)) {
            countRow++;
            temp++;
        } else {
            if (temp > longest)
                longest = temp;
            temp = 0;
        }
    }

    answer << task1 << '\n';
    answer << task2 << '\n';
    answer << task3 << '\n';
    answer << "liczba wierszy: " << countRow << ", najdluzszy: " << longest << '\n';

    return 0;
}

unsigned long sumOfDigits(unsigned long num)
{
    auto score = 0u;

    while (num > 0) {
        score += num % 10;
        num /= 10;
    }

    return score;
}

bool isPrime(unsigned long n)
{
    if (n == 2)
        return true;

    if (n < 2 || (n % 2 == 0 && n != 2))
        return false;

    for (std::size_t i = 3; i <= std::sqrt(n); i += 2)
        if (n % i == 0)
            return false;

    return true;
}

bool correctScoreOfMultiply(const unsigned long &a, const unsigned long &b, const unsigned long &c)
{
    return a * b == c;
}

bool iSRectangularTriangle(const unsigned long &a, const unsigned long &b, const unsigned long &c)
{
    double sqareA = a * a;
    double sqareB = b * b;
    double sqareC = c * c;

    return (sqareA + sqareB == sqareC ||
            sqareA + sqareC == sqareB ||
            sqareB + sqareC == sqareA);
}

bool isTriangle(const unsigned long &a, const unsigned long &b, const unsigned long &c)
{
    return ((a + b > c ) && (a + c > b) && (b + c > a));
}
std::string toString(unsigned long val)
{
    std::ostringstream ss;
    ss << val;
    return ss.str();
}
