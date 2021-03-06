#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>

std::string arabicToRoman(unsigned val);

int main()
{
    std::cout << arabicToRoman(3338);

    return 0;
}

std::string arabicToRoman(unsigned val)
{
    std::unordered_map<unsigned, std::string> values{
        {1, "I"},
        {4, "IV"},
        {5, "V"},
        {9, "IX"},
        {10, "X"},
        {40, "XL"},
        {50, "L"},
        {90, "XC"},
        {100, "C"},
        {400, "CD"},
        {500, "D"},
        {900, "CM"},
        {1000, "M"}
    };

    std::string result;

    while (val > 0)
    {
        auto temp = val;
        auto count = 0;

        while (temp > 10)
        {
            temp /= 10;
            count++;
        }

        if (temp >= 1 && temp <= 3) // 1, 2, 3
        {
            auto num = std::pow(10, count);
            for (size_t i = 0; i < temp; ++i)
                result += values[num];
            val -= num * temp;
        }
        else if (temp >= 6 && temp <= 8) // 5, 6, 7, 8
        {
            auto num = 5 * std::pow(10, count);
            result += values[num];
            val -= num;
        }
        else // 4, 9, 10
        {
            auto num = temp * std::pow(10, count);
            result += values[num];
            val -= num;
        }
    }

    return result;
}
