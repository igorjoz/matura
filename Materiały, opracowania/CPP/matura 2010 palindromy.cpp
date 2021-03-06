#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

bool palindrom(const std::string &str)
{
    std::string temp = str;
    std::reverse(temp.begin(), temp.end());
    return temp == str;
}
int main()
{
    std::ifstream dane("dane.txt", std::ios::in);
    std::ofstream odp("zadanie4.txt", std::ios::out);

    for (unsigned i = 0; i != 1000; ++i)
    {
        std::string slowo;
        dane >> slowo;

        if (palindrom(slowo))
        {
            std::cout << slowo << '\n';
            odp << slowo << '\n';
        }
    }

    return 0;
}
