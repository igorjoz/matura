#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
#include <algorithm>

void zad51()
{
    std::fstream file("slowa.txt", std::ios::in);
    std::fstream file2("wynik5.txt", std::ios::out | std::ios::app);
    std::string word;
    std::map<unsigned, unsigned> mapa;

    for (unsigned i = 0; i <= 12; ++i)
        mapa[i] = 0;

    for (unsigned i = 0; i != 1000; ++i)
    {
        file >> word;
        mapa[word.length()]++;
    }

    std::cout << "5.1\n";
    file2 << "5.1\n";
    for (const auto &el: mapa)
    {
        std::cout << el.first << ' ' << el.second << '\n';
        file2 << el.first << ' ' << el.second << '\n';
    }
}

void zad52()
{
    std::fstream slowa("slowa.txt", std::ios::in);
    std::fstream nowe("nowe.txt", std::ios::in);
    std::fstream wynik("wynik5.txt", std::ios::out | std::ios::app);
    std::string word;
    std::unordered_map<std::string, unsigned> ilosc;
    std::unordered_map<std::string, unsigned> lustrzanych;

    for (unsigned i = 0; i != 25; ++i)
    {
        nowe >> word;
        ilosc[word] = 0;
        std::reverse(word.begin(), word.end());
        lustrzanych[word] = 0;
    }

    for (unsigned i = 0; i != 1000; ++i)
    {
        slowa >> word;
        ilosc[word]++;
        lustrzanych[word]++;
    }

    nowe.seekg(0, std::ios::beg);
    std::cout << "5.2\n";
    wynik << "5.2\n";
    for (unsigned i = 0; i != 25; ++i)
    {
        nowe >> word;
        std::cout << word << ' ' << ilosc[word];
        wynik << word << ' ' << ilosc[word];
        std::reverse(word.begin(), word.end());
        std::cout << ' ' << lustrzanych[word] << '\n';
        wynik << ' ' << lustrzanych[word] << '\n';
    }
}

int main()
{
    zad51();
    zad52();

    return 0;
}
