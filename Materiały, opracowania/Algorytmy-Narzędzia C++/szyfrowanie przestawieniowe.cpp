#include <iostream>
#include <string>
#include <vector>
#include <cmath>

unsigned returnLen(double num);
std::string dEncrypt(std::string sentence);

int main()
{
    std::cout << dEncrypt("alamakota");

    return 0;
}

unsigned returnLen(double num)
{
    if (std::floor(num) == num)
        return num;
    else
        return floor(num + 1);
}

std::string dEncrypt(std::string sentence)
{
    auto len = sentence.length();
    unsigned sideLength = returnLen(std::sqrt(len));
    std::string newSentence;
    std::vector<std::vector<char>> array;

    array.resize(sideLength);

    for (std::size_t i = 0; i < sideLength; ++i)
        array.at(i).resize(sideLength);

    for (std::size_t i = 0, j = 0, k = 0; i < len; ++i, ++k) {
        if (i != 0 && i % sideLength == 0) {
            j++;
            k = 0;
        }

        array.at(j).at(k) = sentence[i];
    }

    for (std::size_t i = 0; i < sideLength; ++i)
        for (std::size_t j = 0; j < sideLength; ++j)
            newSentence += array.at(j).at(i);

    return newSentence;
}
