#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

bool palindorm(const std::string &str)
{
    std::string temp = str;
    std::reverse(temp.begin(), temp.end());
    return str == temp;
}

bool zawieraSie(std::string str1, std::string str2)
{
    if (str1.find(str2) != std::string::npos)
        return true;
    return false;
}

bool czyTylkoDoSklejenia(std::string str1, std::string str2)
{
    if (zawieraSie(str1, str2))
        return false;

    unsigned len1 = str1.length();
    unsigned len2 = str2.length();

    for (int i = 1; i != len2; ++i)
    {
        if (str1.compare(0, len2 - i, str2.substr(i, len2 - i)) == 0)
            return false;
        if (str1.compare(len1 - len2 + i, len2 - i, str2.substr(0, len2 - i)) == 0)
            return false;
    }

    return true;
}

std::string sklej(std::string str1, std::string str2)
{
    unsigned len1 = str1.length();
    unsigned len2 = str2.length();

    for (int i = 1; i != len2; i++)
    {
        if (str1.compare(0, len2 - i, str2.substr(i, len2 - i)) == 0)
            return str2.substr(0, i) + str1;
        if (str1.compare(len1 - len2 + i, len2 - i, str2.substr(0, len2 - i)) == 0)
            return str1 + str2.substr(len2 - i, i);
    }
}

int main()
{
    std::ifstream dane("dane.txt", std::ios::in);
    std::ofstream odp("zad_5.txt", std::ios::out);
    std::ofstream slowa("slowa.txt", std::ios::out);
    std::string str1;
    std::string str2;
    unsigned iloscPalindromow = 0;
    unsigned parZawartych = 0;
    unsigned tylkoDoSklejenia = 0;

    while (dane >> str1 >> str2)
    {
        if (palindorm(str1))
            iloscPalindromow++;

        if (palindorm(str2))
            iloscPalindromow++;

        if (zawieraSie(str1, str2))
        {
            parZawartych++;
            //std::cout << "C = " << str1 << '\n';
            slowa << "C = " << str1 << '\n';
        }
        else if (czyTylkoDoSklejenia(str1, str2))
        {
            tylkoDoSklejenia++;
            //std::cout << "C = " << str1 + str2 << " lub " << str2 + str1 << '\n';
            slowa << "C = " << str1 + str2 << " lub " << str2 + str1 << '\n';
        }
        else
        {
         //std::cout << "C = " << sklej(str1, str2) << '\n';
         slowa << "C = " << sklej(str1, str2) << '\n';
        }
    }

    std::cout << "ilosc palindromow: " << iloscPalindromow << '\n';
    odp << "ilosc palindromow: " << iloscPalindromow << '\n';

    std::cout << "\nilosc par zwierajacych B w A: " << parZawartych << '\n';
    odp << "ilosc par zwierajacych B w A: " << parZawartych << '\n';

    std::cout << "\nilosc par, gdzie mozna tylko skleic slowo A i B: " << tylkoDoSklejenia << '\n';
    odp << "ilosc par, gdzie mozna tylko skleic slowo A i B: " << tylkoDoSklejenia << '\n';

    // TESTY
    //std::cout << "\nC= " << sklej("10011101", "1100");
    //std::cout << "\nC= " << sklej("10011101","1010");

    dane.close();
    odp.close();
    slowa.close();
    return 0;
}
