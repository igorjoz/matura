#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

bool palindrom(std::string str)
{
    std::string temp = str;
    std::reverse(str.begin(), str.end());

    return str == temp;
}

bool sumaKodow(std::string str)
{
    for (unsigned i = 0; i != str.size() - 1; ++i)
        if ((str[i] + str[i + 1]) == 220)
            return true;

    return false;
}

int main()
{
    std::ifstream hasla("hasla.txt", std::ios::in);
    std::ofstream wa("wynik4a.txt", std::ios::out);
    std::ofstream wb("wynik4b.txt", std::ios::out);
    std::ofstream wc("wynik4c.txt", std::ios::out);
    std::string haslo;
    unsigned parzystych = 0;
    std::vector<std::string> palindromy;
    std::vector<std::string> zSumaKodow;

    for (unsigned i = 0; i != 200; ++i)
    {
        hasla >> haslo;

        if (haslo.length() % 2 == 0)
            parzystych++;

        if (palindrom(haslo))
            palindromy.push_back(haslo);

        if (sumaKodow(haslo))
            zSumaKodow.push_back(haslo);

    }

    std::cout << "a parzystych: " << parzystych << ", nieparzystych: " << 200 - parzystych << '\n';
    wa << "parzystych: " << parzystych << ", nieparzystych: " << 200 - parzystych << '\n';

    std::cout << "\nb\n";
    for (const auto &el: palindromy)
    {
        std::cout << el << '\n';
        wb << el << '\n';
    }

    std::cout << "\nc\n";
    for (const auto &el: zSumaKodow)
    {
        std::cout << el << '\n';
        wc << el << '\n';
    }

    hasla.close();
    wa.close();
    wb.close();
    wc.close();

    return 0;
}
