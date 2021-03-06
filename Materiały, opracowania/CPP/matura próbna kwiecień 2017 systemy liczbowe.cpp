#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>

int main()
{
    std::ifstream dane{"liczby.txt"};
    std::vector<std::string> liczby;
    std::string linia;

    while (dane >> linia)
        liczby.push_back(linia);

    // zad 6.1.

    std::ofstream wyn1{"wyniki_6_1.txt"};
    unsigned licz = 0;

    for (const auto& liczba : liczby)
        if (liczba.back() == '8')
            licz++;

    wyn1 << licz;

    // zad 6.2.

    std::ofstream wyn2{"wyniki_6_2.txt"};
    licz = 0;

    for (const auto& liczba : liczby)
        if (liczba.back() == '4' && liczba.find('0') == std::string::npos)
            licz++;

    wyn2 << licz;

    // zad 6.3.

    std::ofstream wyn3{"wyniki_6_3.txt"};
    licz = 0;

    for (const auto& liczba : liczby) {
        auto dl = liczba.length();

        if (liczba.at(dl - 1) == '2' && liczba.at(dl - 2) == '0')
            licz++;
    }

    wyn3 << licz;

    // zad 6.4.

    std::ofstream wyn4{"wyniki_6_4.txt"};
    unsigned long long wynik = 0;

    for (const auto& liczba : liczby)
        if (liczba.back() == '8') {
            auto jako10 = std::strtol(liczba.c_str(), nullptr, 8);
            wynik += jako10;
        }

    wyn4 << wynik;

    // zad 6.5.

    std::ofstream wyn5{"wyniki_6_5.txt"};
    std::size_t indexMin = 0;
    std::size_t indexMax = 0;
    auto podstawa = static_cast<int>(liczby.front().back() - 48); // liczby.front().back() - ostatnia litera pierwszego elementu vectora
    auto jako10 = std::strtol(liczby.front().c_str(), nullptr, podstawa);

    long long min = jako10;
    long long max = jako10;

    for (std::size_t i = 1; i < liczby.size(); ++i) {
        podstawa = static_cast<int>(liczby.at(i).back() - 48); // .at(i) to prawie to samo co [i]
        jako10 = std::strtol(liczby.at(i).c_str(), nullptr, podstawa);

        if (jako10 > max) {
            max = jako10;
            indexMax = i;
        }

        if (jako10 < min) {
            min = jako10;
            indexMin = i;
        }
    }

    wyn5 << "Kod najmniejszej: " << liczby.at(indexMin) << '\n';
    wyn5 << "Wartosc w systemie 10: " << min << "\n\n";
    wyn5 << "Kod najwiekszej: " << liczby.at(indexMax) << '\n';
    wyn5 << "Wartosc w systemie 10: " << max << '\n';

    return 0;
}
