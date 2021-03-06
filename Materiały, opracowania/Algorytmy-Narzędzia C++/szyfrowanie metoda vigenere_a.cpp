#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

std::string encrypt(std::string data, std::string key);
std::string decrypt(std::string data, std::string key);

int main()
{
    std::cout << encrypt("ABC", "abc") << '\n';
    std::cout << decrypt("ace", "abc") << '\n';

    return 0;
}

std::string encrypt(std::string data, std::string key)
{
    std::transform(data.begin(), data.end(), data.begin(), [](unsigned char c) { return std::toupper(c); });
    std::transform(key.begin(), key.end(), key.begin(), [](unsigned char c) { return std::toupper(c); });

    unsigned keyLen = key.length();
    std::string newString;
    unsigned spaces = 0;

    for (unsigned i = 0; i != data.length(); ++i)
        if(std::isalpha(data.at(i)))
                newString += (data.at(i) + key.at((i + keyLen - spaces) % keyLen)) % 26 + 'A';
        else {
            newString += data.at(i);
            spaces++;
        }

    return newString;
}

std::string decrypt(std::string data, std::string key)
{
    std::transform(data.begin(), data.end(), data.begin(), [](unsigned char c) { return std::toupper(c); });
    std::transform(key.begin(), key.end(), key.begin(), [](unsigned char c) { return std::toupper(c); });

    unsigned keyLen = key.length();
    std::string newString;
    unsigned spaces = 0;

    for (unsigned i = 0; i != data.length(); ++i)
        if(std::isalpha(data.at(i)))
            newString += (data.at(i) - key.at((i + keyLen - spaces) % keyLen)) % 26 + 'A';
        else {
            newString += data.at(i);
            spaces++;
        }

    return newString;
}
