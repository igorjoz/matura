#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

bool czyArytemtyczny(const std::vector<unsigned>& vec);
unsigned wyznaczNajwiekszySzescian(const std::vector<unsigned>& vec);
bool czySzescianLiczbyNaturalnej(const unsigned& n);
unsigned wyznaczBlednyWyraz(const std::vector<unsigned>& vec);

int main()
{
    std::vector<unsigned> ciag;
    std::ifstream daneCiagi{"ciagi.txt"};
    std::ofstream wyn1{"wynik1.txt"};
    std::ofstream wyn2{"wynik2.txt"};
    unsigned rozmiar;
    unsigned liczba;
    unsigned r;
    unsigned arytmetycznych = 0;
    unsigned maxR = 0;
    std::vector<unsigned> szesciany;

    while (daneCiagi >> rozmiar) {
        ciag.clear();

        for (std::size_t i = 0; i < rozmiar; ++i) {
            daneCiagi >> liczba;
            ciag.push_back(liczba);
        }

        if (czyArytemtyczny(ciag)) {
            arytmetycznych++;

            r = ciag.at(1) - ciag.at(0);

            if (r > maxR)
                maxR = r;
        }

        unsigned najwiekszySzescian = wyznaczNajwiekszySzescian(ciag);

        if (najwiekszySzescian != 0)
            szesciany.push_back(najwiekszySzescian);

    }

    wyn1 << arytmetycznych << '\n';
    wyn1 << maxR << '\n';

    for (const auto& val : szesciany)
        wyn2 << val << '\n';

    std::ifstream daneBledne{"bledne.txt"};
    std::ofstream wyn3{"wynik3.txt"};
    std::vector<unsigned> bledneWyrazy;

    while (daneBledne >> rozmiar) {
        ciag.clear();

        for (std::size_t i = 0; i < rozmiar; ++i) {
            daneBledne >> liczba;
            ciag.push_back(liczba);
        }

        bledneWyrazy.push_back(wyznaczBlednyWyraz(ciag));
    }

    for (const auto& val : bledneWyrazy)
        wyn3 << val << '\n';

    return 0;
}

bool czyArytemtyczny(const std::vector<unsigned>& vec)
{
    unsigned r = vec.at(1) - vec.at(0);

    for (std::size_t i = 1; i < vec.size(); ++i)
        if (vec.at(i) - vec.at(i - 1) != r)
            return false;

    return true;
}

unsigned wyznaczNajwiekszySzescian(const std::vector<unsigned>& vec)
{
    unsigned najwiekszy = 0;

    for (const auto& val : vec)
        if (czySzescianLiczbyNaturalnej(val))
            if (val > najwiekszy)
                najwiekszy = val;

    return najwiekszy;
}

bool czySzescianLiczbyNaturalnej(const unsigned& n)
{
    auto cbrtN = std::cbrt(n);

    return std::floor(cbrtN) == cbrtN;
}

unsigned wyznaczBlednyWyraz(const std::vector<unsigned>& vec)
{
    for (std::size_t i = 2; i < vec.size() - 2; ++i) {
        bool w1 = vec.at(i - 1) * 2 != vec.at(i - 2) + vec.at(i);
        bool w2 = vec.at(i) * 2 != vec.at(i - 1) + vec.at(i + 1);
        bool w3 = vec.at(i + 1) * 2 != vec.at(i) + vec.at(i + 2);

        if (w1 && w2 && w3)
            return vec.at(i);

        if (w1 && !w2 && !w3)
            return vec.at(i - 2);

        if (!w1 && !w2 && w3)
            return vec.at(i + 2);
    }
}
