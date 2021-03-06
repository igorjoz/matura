#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

void dlNajdluzszegoBlokuTrojkowego(std::string wejscie, std::string wyjscie);

int main()
{
    dlNajdluzszegoBlokuTrojkowego("bloki1.txt", "wyniki1.txt");
    dlNajdluzszegoBlokuTrojkowego("bloki2.txt", "wyniki2.txt");
    dlNajdluzszegoBlokuTrojkowego("bloki3.txt", "wyniki3.txt");

    return 0;
}

void dlNajdluzszegoBlokuTrojkowego(std::string wejscie, std::string wyjscie)
{
    std::ifstream dane{wejscie};
    std::ofstream wynik{wyjscie};
    std::vector<unsigned> pierwszePozycje{0, -1, -1};
    unsigned liczba;
    unsigned sumaMod3 = 0;
    unsigned liczbaWczytanych = 0;
    unsigned najdluzszy = 0;

    while (dane >> liczba) {
        liczbaWczytanych++;
        sumaMod3 = (sumaMod3 + liczba) % 3;

        if (pierwszePozycje.at(sumaMod3) == -1)
            pierwszePozycje.at(sumaMod3) = liczbaWczytanych;
        else
            najdluzszy = std::max(najdluzszy, liczbaWczytanych - pierwszePozycje.at(sumaMod3));
    }

    wynik << najdluzszy << '\n';
}
