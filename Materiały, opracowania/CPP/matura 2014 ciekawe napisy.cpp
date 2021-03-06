#include <iostream>
#include <fstream>
#include <unordered_map>

bool czyPierwsza(unsigned num)
{
    if (num < 2)
        return false;

    for (int i = 2; i * i <= num; ++i)
        if (num % i == 0)
            return false;

    return true;
}

bool czyRosnacy(std::string str)
{
    for (unsigned i = 0; i != str.size() - 1; ++i)
        if (str[i] > str[i+1])
            return false;
    return true;
}

void ppa()
{
    std::ifstream file("NAPIS.TXT", std::ios::in);
    std::ofstream file2("ZADANIE5.TXT", std::ios::out | std::ios::app);
    std::string str;
    int suma;
    int wierwszy = 0;

    for (unsigned i = 0; i != 1000; ++i)
    {
        suma = 0;
        file >> str;

        for (unsigned j = 0; j != str.size(); ++j)
            suma += (char)str[j];

        if (czyPierwsza(suma))
            wierwszy++;
    }

    file2 << "a\n" << wierwszy << "\n\n";
    std::cout << "a\n" << wierwszy << "\n\n";
}

void ppb()
{
    std::ifstream file("NAPIS.TXT", std::ios::in);
    std::ofstream file2("ZADANIE5.TXT", std::ios::out | std::ios::app);
    std::string str;

    std::cout << "b \n";
    file2 << "b \n";
    for (unsigned i = 0; i != 1000; ++i)
    {
        file >> str;

        if (czyRosnacy(str))
        {
            std::cout << str << '\n';
            file2 << str << '\n';
        }
    }

    std::cout << str << "\n\n";
    file2 << str << "\n\n";

}

void ppc()
{
    std::ifstream file("NAPIS.TXT", std::ios::in);
    std::ofstream file2("ZADANIE5.TXT", std::ios::out | std::ios::app);
    std::string str;
    std::unordered_map<std::string, int> mapa;

    for (unsigned i = 0; i != 1000; ++i)
    {
        file >> str;

        if (mapa.find(str) != mapa.end())
            mapa[str]++;
        else
            //mapa.insert(std::make_pair(str, 1));
            mapa[str] = 1;
    }

    std::cout << "c \n";
    file2 << "c \n";
    for (const auto &el: mapa)
        if (el.second > 1)
        {
            std::cout << el.first << '\n';
            file2 << el.first << '\n';
        }

    // ALBO ( i normalnie potrzeba <iterator>)
    /*
    for (auto it = mapa.begin(); it != mapa.end(); ++it)
        if (it->second > 1)
            std::cout << it->first << '\n'; */
    // nie da siê odwo³aæ przez liczbe, bo kluczem jest slowo, i potrzebaby tablicy slow (w tym przypdadku tych 1000 i  to po nich jechac)
}

int main()
{
    ppa();
    ppb();
    ppc();

    return 0;
}
