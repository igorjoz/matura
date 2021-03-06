#include <iostream>
#include <iterator>
#include <string>
#include <cctype>

std::string encrypt(std::string data, unsigned shift);
std::string decrypt(std::string data, unsigned shift);

int main()
{
    std::string data{ "cd plhvldf pdwxud" };
    std::cout << decrypt(data, 3);

    return 0;
}

std::string encrypt(std::string data, unsigned shift)
{
    std::string newString;

    for (auto it = data.begin(); it != data.end(); ++it)
        if (std::isalpha(*it))
            newString += std::islower(*it) ? 'a' + (*it + 26 - 'a' + shift) % 26 : 'A' + (*it + 26 - 'A' + shift) % 26;
        else
            newString += *it;

    return newString;
}

std::string decrypt(std::string data, unsigned shift)
{
    std::string newString;

    for (auto it = data.begin(); it != data.end(); ++it)
        if (std::isalpha(*it))
            newString += std::islower(*it) ? 'a' + (*it + 26 - 'a' - shift) % 26 : 'A' + (*it + 26 - 'A' - shift) % 26;
        else
            newString += *it;

    return newString;
}
