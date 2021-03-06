#include <iostream>
#include <string>
#include <unordered_map>

unsigned romanToArabic(const std::string &roman);

int main()
{
    std::cout << romanToArabic("MMMCCCXXXVIII");

    return 0;
}

unsigned romanToArabic(const std::string &roman)
{
    std::unordered_map<char, unsigned> values{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    auto it = roman.rbegin();
    unsigned result = 0;
    unsigned last = 0;

    do
    {
        auto temp = values.at(*it);

        if (temp >= last)
        {
            result += temp;
            last = temp;
        }
        else
            result -= temp;

    } while (++it != roman.rend());

    return result;
}