#include <iostream>
#include <string>

std::string convertFromDec(unsigned num, unsigned base);

int main()
{
    std::cout << convertFromDec(360, 2) << '\n';
    std::cout << convertFromDec(920, 8) << '\n';
	std::cout << convertFromDec(64365, 16) << '\n';

    return 0;
}

std::string convertFromDec(unsigned num, unsigned base)
{
    std::string number;

    while (num > 0) {
        char c = '0' + num % base;
        if (c > '9')
            c += 7;
        number = c + number;
        num /= base;
    }

    return number;
}
