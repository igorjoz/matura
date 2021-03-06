#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <fstream>
#include <vector>
#include <bitset>
#include <cstdlib>
#include <numeric>

bool jestParzysta(std::string str)
{
    return str[str.length() - 1] == '0';
}

bool dlRowna9(std::string str)
{
    return str.length() == 9;
}

unsigned doDec(std::string str)
{
    return strtol(str.c_str(), NULL, 2);
}

int main()
{
    std::ifstream plik("liczby.txt", std::ios::in);
    std::ofstream odp("zadanie6.txt", std::ios::out);
    std::array<unsigned, 1000> tab;
    unsigned parzystych = 0;
    std::vector<unsigned> oDl9;

    for (unsigned i = 0; i != 1000; ++i)
    {
        std::string temp;
        plik >> temp;

        tab[i] = doDec(temp);

        if (jestParzysta(temp))
            parzystych++;

        if (dlRowna9(temp))
            oDl9.push_back(doDec(temp));
    }

    // ODP A
    std::cout << "a " << parzystych << '\n';
    odp << "a " << parzystych << '\n';

    // ODP B
    unsigned max = *std::max_element(tab.begin(), tab.end());
    std::cout << "b najwieksza liczba w tym pliku to " << max << ", " << std::bitset<16>(max) << '\n'; // z arkusza wiemy, ze maksymalna dlugosc liczby w bin to 16, wiem spokojnie mozemy ustawic bitset na 16
    odp << "b najwieksza liczba w tym pliku to " << max << ", " << std::bitset<16>(max) << '\n';

    // ODP C
    unsigned suma = std::accumulate(oDl9.begin(), oDl9.end(), 0);
    std::cout << "c liczb o dlugosci jest " << oDl9.size() << ", a suma tych liczb to " << std::bitset<16>(suma) << '\n'; // tutaj zas sprawdzamy jaka jest dl, na poczatku zamiast 16 mozna dac np. 20 i sprawdzac czy sa wipsywane zera na poaczatku, jak tak to zmniejszamy
    odp << "c liczb o dlugosci jest " << oDl9.size() << ", a suma tych liczb to " << std::bitset<16>(suma) << '\n';

    plik.close();
    odp.close();

    return 0;
}
