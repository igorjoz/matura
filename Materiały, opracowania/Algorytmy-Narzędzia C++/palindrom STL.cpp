#include <iostream>
#include <algorithm>
#include <string>

bool isPalindrome(const std::string& str);

int main()
{
    std::cout << isPalindrome("kajak");

    return 0;
}

bool isPalindrome(const std::string& str)
{
    auto str2 = str;
    std::reverse(str2.begin(), str2.end());

    return str == str2;
}
