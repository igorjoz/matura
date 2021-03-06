#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_map>
#include <map>

void zad41()
{
    std::fstream file("slowa.txt", std::ios::in);
    std::fstream file2("wynik4.txt", std::ios::out | std::ios::app);
    std::string str;
    unsigned rows = 0;

    for (unsigned i = 0; i != 1000; ++i)
    {
        file >> str;

        unsigned zero = std::count(str.begin(), str.end(), '0');
        unsigned one = std::count(str.begin(), str.end(), '1');

        if(zero > one)
            rows++;
    }

    std::cout << "4.1 " << rows << '\n';
    file2 << "4.1 " << rows << '\n';
}

bool niepustyBlok(std::string &str)
{
    if (str[0] == '1')
        return false;
    if (str[str.length() - 1] != '1')
        return false;

    unsigned zero = std::count(str.begin(), str.end(), '0');
    unsigned one = std::count(str.begin(), str.end(), '1');

    std::string newStr((std::string(zero, '0'))+(std::string(one, '1')));

    return newStr == str;
}

void zad42()
{
    std::fstream file("slowa.txt", std::ios::in);
    std::fstream file2("wynik4.txt", std::ios::out | std::ios::app);
    std::string str;
    unsigned rows = 0;

    for (unsigned i = 0; i != 1000; ++i)
    {
        file >> str;

        if(niepustyBlok(str))
            rows++;
    }

    std::cout << "4.2 " << rows << '\n';
    file2 << "4.2 " << rows << '\n';
}

unsigned najdluszyCiagZer(std::string &str)
{
    unsigned max = 0;
    unsigned tempMax = 0;

    for (unsigned i = 0; i < str.size(); ++i)
    {
        if (str[i] == '0')
            tempMax++;
        else
        {
            if (tempMax > max)
            {
                max = tempMax;
                tempMax = 0;
            }
            else tempMax = 0;
        }
    }

    if (tempMax > max)
        max = tempMax;

    return max;
}

void zad43()
{
    std::fstream file("slowa.txt", std::ios::in);
    std::fstream file2("wynik4.txt", std::ios::out | std::ios::app);
    std::string str;
    std::multimap<unsigned, std::string> map;
    unsigned max = 0;

    for (unsigned i = 0; i != 1000; ++i)
    {
        file >> str;
        if (najdluszyCiagZer(str) > max)
            max = najdluszyCiagZer(str);
        map.insert(std::pair<unsigned, std::string>(najdluszyCiagZer(str), str));
    }

    std::cout << "4.2 dlugosc: " << max << "\nslowa:\n";
    file2 << "4.2 dlugosc: " << max << "\nslowa:\n";
    for (auto it = map.rbegin(); it != map.rend(); ++it)
        if (it->first == max)
        {
            std::cout << it->second << '\n';
            file2 << it->second << '\n';
        }
        else
            break;
}

int main()
{
    zad41();
    zad42();
    zad43();
    return 0;
}
