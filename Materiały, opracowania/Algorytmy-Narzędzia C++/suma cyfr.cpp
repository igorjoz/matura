#include <iostream>

unsigned sumOfDigits(unsigned n);
unsigned long sumOfDigits(const std::string &num)

int main()
{
    std::cout << sumOfDigits(3456);
    return 0;
}

unsigned sumOfDigits(unsigned n)
{
    auto sum = 0u;

    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

unsigned long sumOfDigits(const std::string &num)
{
    unsigned long score = 0;

    for (const auto &el: num)
        score += static_cast<unsigned long>(el - '0');

    return score;
}