#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>

int main()
{
    std::ifstream plik("napisy.txt", std::ios::in);
    std::ofstream odp("zadanie4.txt", std::ios::out);
    std::string napis;
    unsigned parzystych = 0;
    unsigned zerJedynek = 0;
    unsigned samychZer = 0;
    unsigned samychJedynek = 0;
    std::map<unsigned, unsigned> mapa;

    for (unsigned i = 0; i != 1000; ++i)
    {
        plik >> napis;

        if (napis.length() % 2 == 0)
            parzystych++;

        unsigned zer = std::count(napis.begin(), napis.end(), '0');
        unsigned jedynek = std::count(napis.begin(), napis.end(), '1');

        if (zer == jedynek)
            zerJedynek++;

        if (zer == napis.length())
            samychZer++;

        if (jedynek == napis.length())
            samychJedynek++;

        mapa[napis.length()]++;
    }

    std::cout << "a " << parzystych << '\n';
    odp << "a " << parzystych << '\n';
    std::cout << "b " << zerJedynek << '\n';
    odp << "b " << zerJedynek << '\n';
    std::cout << "c \n" << "samych zer " << samychZer << "\nsamych jedynek " << samychJedynek << '\n';
    odp << "c \n" << "samych zer " << samychZer << "\nsamych jedynek " << samychJedynek << '\n';
    std::cout << "d\n";
    odp << "d\n";

    for (unsigned i = 2; i != 17; ++i)
    {
        std::cout << "z " << i << " znakow: " << mapa[i] << '\n';
        odp << "z " << i << " znakow: " << mapa[i] << '\n';
    }

    plik.close();
    odp.close();
    return 0;
}
