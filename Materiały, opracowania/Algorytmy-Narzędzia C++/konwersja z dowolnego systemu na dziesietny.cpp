#include <iostream>
#include <cctype>
#include <string>

int convertToDec(std::string number, unsigned base);

int main()
{
    std::cout << convertToDec("101", 2) << '\n';
    std::cout << convertToDec("F", 16) << '\n';
    std::cout << convertToDec("777", 8) << '\n';

    return 0;
}

int convertToDec(std::string number, unsigned base)
{
    auto result = 0;

    for (std::size_t i = 0; i < number.length(); ++i)
        if (std::isdigit(number.at(i)))
            result = result * base + (number.at(i) - '0');
        else
            result = result * base + (number.at(i) - 'A' + 10);

    return result;
}
