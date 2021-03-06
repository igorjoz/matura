#include <iostream>
#include <set>
#include <fstream>
#include <vector>
#include <iterator>
#include <cmath>
#include <utility>
#include <string>

struct Okrag
{
    int x;
    int y;
    unsigned r;
};

bool zawieraPunkt(const Okrag &okr1, const Okrag &okr2)
{
    // nierownosc okregu (x - a)^2 + (y - b)^2 <= r^2
    double rDoKwadratu = okr1.r * okr1.r;
    double pierwszyNawias = (okr1.x - okr2.x) * (okr1.x - okr2.x);
    double drugiNawias = (okr1.y - okr2.y) * (okr1.y - okr2.y);

    if (pierwszyNawias + drugiNawias <= rDoKwadratu)
    {
        return true;
    }

    return false;

}

bool saStyczne(const Okrag &okr1, const Okrag &okr2)
{
    double odlegoscSrodkow = std::sqrt((okr2.x - okr1.x) * (okr2.x - okr1.x) + (okr2.y - okr1.y) * (okr2.y - okr1.y));
    double sumaPromieni = okr1.r + okr2.r;
    double roznicaPromieni1 = std::abs(okr1.r - okr2.r);
    double roznicaPromieni2 = std::abs(okr2.r - okr1.r);

    if (odlegoscSrodkow == sumaPromieni || odlegoscSrodkow == roznicaPromieni1 || odlegoscSrodkow == roznicaPromieni2)
    {
        return true;
    }

    return false;
}

int main()
{

    std::ifstream dane("dane.txt");

    // zadanie 4.1

    std::ofstream wyn1("wynik1.txt");
    std::set<unsigned> promienie;
    std::vector<Okrag> okregi;

    Okrag okrag;

    while(dane >> okrag.x >> okrag.y >> okrag.r)
    {
        promienie.insert(okrag.r);
        okregi.push_back(okrag);
    }

    unsigned minR = *promienie.begin();
    unsigned ilosc = 0;

    for (auto const &el: okregi)
    {
        if (el.r == minR)
        {
            ilosc++;
            std::cout << el.x << ' ' << el.y << ' ' << el.r << '\n';
            wyn1 << el.x << ' ' << el.y << ' ' << el.r << '\n';
        }
    }

    std::cout << ilosc << '\n';
    wyn1 << ilosc << '\n';

    wyn1.close();

    // zadanie 4.2

    std::ofstream wyn2("wynik2.txt");

    std::pair<std::vector<Okrag>::iterator, unsigned> zNajIloscia;
    unsigned iloscPunktow = 0;

    for (auto it = okregi.begin(); it != okregi.end(); ++it)
    {
        iloscPunktow = 0;

        for (auto sIt = okregi.begin(); sIt != okregi.end(); ++sIt)
        {
            if (it == sIt)
            {
                continue;
            }

            if (zawieraPunkt(*it, *sIt))
            {
                iloscPunktow++;
            }
        }

        if (it == okregi.begin() || iloscPunktow > zNajIloscia.second)
        {
            zNajIloscia.first = it;
            zNajIloscia.second = iloscPunktow;
        }
    }

    std::cout << '\n';

    std::cout << zNajIloscia.first->x << ' ' << zNajIloscia.first->y << ' ' << zNajIloscia.first->r << '\n';
    wyn2 << zNajIloscia.first->x << ' ' << zNajIloscia.first->y << ' ' << zNajIloscia.first->r << '\n';

    std::cout << zNajIloscia.second << '\n';
    wyn2 << zNajIloscia.second << '\n';

    wyn2.close();

    // zadanie 4.3

    std::ofstream wyn3("wynik3.txt");
    std::ofstream temp("temp.txt");

    std::cout << '\n';

    unsigned iloscPar = 0;

    for (auto it = okregi.begin(); it != okregi.end(); ++it)
    {
        for (auto sIt = okregi.begin(); sIt != okregi.end(); ++sIt)
        {
            if (it == sIt)
            {
                continue;
            }

            if (saStyczne(*it, *sIt))
            {
                iloscPar++;
                std::cout << it->x << ' ' << it->y << ' ' << it->r << ' ' << sIt->x << ' ' << sIt->y << ' ' << sIt->r << '\n';
                temp << it->x << ' ' << it->y << ' ' << it->r << ' ' << sIt->x << ' ' << sIt->y << ' ' << sIt->r << '\n';
            }
        }
    }

    std::cout << iloscPar << '\n';
    wyn3 << iloscPar << '\n';

    temp.close();
    std::ifstream temp2("temp.txt");
    std::string line;

    while (getline(temp2, line))
    {
        wyn3 << line << '\n';
    }


    return 0;
}
