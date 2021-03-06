// zad/odp 126/

#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>

unsigned long fib(const unsigned& n);
std::string toBin(const unsigned& num);
bool isPrimaryNumber(const unsigned long& num);
std::string toBin(const unsigned& num, short& c);

int main()
{
    std::ofstream answer {"wyniki.txt"};
    std::vector<unsigned long> fibNumbers;

    for (unsigned int i = 1; i <= 40; ++i)
        fibNumbers.emplace_back(fib(i));

    std::cout << "zad 67.1.\n";
    std::cout << fibNumbers.at(9) << '\n';
    std::cout << fibNumbers.at(19) << '\n';
    std::cout << fibNumbers.at(29) << '\n';
    std::cout << fibNumbers.at(39) << '\n';

    std::cout << "\nzad 67.2.\n";
    for (const auto& num : fibNumbers)
        if (isPrimaryNumber(num))
            std::cout << num << '\n';

    std::ofstream numbers {"numery.txt"};

    for (const auto& num : fibNumbers)
        numbers << toBin(num) << '\n';

    std::cout << "\nzad 67.4.\n";
    for (const auto& num : fibNumbers) {
        short quanitityOfOnes {0};
        std::string str = toBin(num, quanitityOfOnes);

        if (quanitityOfOnes == 6)
            std::cout << str << '\n';
    }

    return 0;
}

/*unsigned long fib(const unsigned n)
{
    if (n == 1 || n == 2)
        return 1;

    return fib(n - 1) + fib(n - 2);
}*/

unsigned long fib(const unsigned& n)
{
    unsigned a {0};
    unsigned b {1};

    for (unsigned long i = 0; i < (n - 1); ++i) {
        std::swap(a, b);
        b += a;
    }

    return b;
}

std::string toBin(const unsigned& num)
{
    return std::bitset<27>{num}.to_string();
}

bool isPrimaryNumber(const unsigned long& num)
{
    if (num == 2)
        return true;

    if (num < 2 || (num % 2 == 0 && num != 2))
        return false;

    unsigned x = std::sqrt(num);

    for (unsigned long  i = 3; i <= x; ++i)
        if (num % i == 0)
            return false;

    return true;
}

std::string toBin(const unsigned& num, short& c)
{
    std::bitset<27>x {num};
    c = x.count();
    auto str = x.to_string();

    return str.erase(0, str.find('1'));
}
