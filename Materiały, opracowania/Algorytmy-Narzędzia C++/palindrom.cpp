#include <iostream>
#include <cstddef>
#include <string>

bool isPalindrome(const std::string& str);

int main()
{
    std::cout << isPalindrome("kajak");

    return 0;
}

bool isPalindrome(const std::string& str)
{
    std::size_t len = str.length();

    for (std::size_t i = 0; i < len / 2; ++i)
        if (str.at(i) != str.at(len - i - 1))
            return false;

    return true;
}
