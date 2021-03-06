#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <algorithm>

bool takaSamaDlugosc(std::array<std::array<std::string, 5>, 200> &tab, unsigned i)
{
    for (unsigned j = 0; j != tab[i].size() - 1; ++j)
        if (tab[i][j].size() != tab[i][j + 1].size())
            return false;
    return true;
}

bool anagram(std::array<std::array<std::string, 5>, 200> tab, unsigned i)
{
    std::sort(tab[i].begin(), tab[i].end());

    for (unsigned j = 0; j != tab[i].size(); ++j)
        std::sort(tab[i][j].begin(), tab[i][j].end());

    for (unsigned j = 1; j != tab[i].size(); ++j)
        if (tab[i][0] != tab[i][j])
            return false;

    return true;
}

int main()
{
    std::ifstream dane("anagram.txt", std::ios::in);
    std::ofstream odpa("odp_4a.txt", std::ios::out);
    std::ofstream odpb("odp_4b.txt", std::ios::out);
    std::array<std::array<std::string, 5>, 200> tab;

    for (unsigned i = 0; i != 200; ++i)
        dane >> tab[i][0] >> tab[i][1] >> tab[i][2] >> tab[i][3] >> tab[i][4];

    for (unsigned i = 0; i != 200; ++i)
    {
        if (takaSamaDlugosc(tab, i))
            odpa << tab[i][0] << ' ' << tab[i][1] << ' ' << tab[i][2] << ' ' << tab[i][3] << ' ' << tab[i][4] << '\n';
        if (anagram(tab, i))
            odpb << tab[i][0] << ' ' << tab[i][1] << ' ' << tab[i][2] << ' ' << tab[i][3] << ' ' << tab[i][4] << '\n';

    }

    /*for (unsigned i = 0; i != 200; ++i)
        if (takaSamaDlugosc(tab, i))
            std::cout << tab[i][0] << ' ' << tab[i][1] << ' ' << tab[i][2] << ' ' << tab[i][3] << ' ' << tab[i][4] << '\n';

    std::cout << '\n';
    for (unsigned i = 0; i != 200; ++i)
        if (anagram(tab, i))
            std::cout << tab[i][0] << ' ' << tab[i][1] << ' ' << tab[i][2] << ' ' << tab[i][3] << ' ' << tab[i][4] << '\n';*/

    dane.close();
    odpa.close();
    odpb.close();

    return 0;
}
