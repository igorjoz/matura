#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <set>
#include <utility>

bool symetria(std::vector<int>& v);
bool kontrastujace(int x, int y);
int wyznaczLiczbeKontrastrujacych(std::vector<std::vector<int>> v);
int wyznaczDlugoscNajdluzszejLiniiPionowej(std::vector<std::vector<int>> v);

int main()
{
    std::ifstream dane {"dane.txt"};
    //std::ifstream dane {"przyklad.txt"};
    std::ofstream wyniki {"wyniki6.txt"};
    std::vector<std::vector<int>> piksele(200);

    int najjasniejszy {-1};
    int najciemniejszy {256};
    int doUsuniecia {0};

    for (std::size_t i = 0; i < 200; ++i) {
        piksele.at(i).resize(320);
        int piksel;

        for (std::size_t j = 0; j < 320; ++j) {
            dane >> piksel;
            piksele.at(i).at(j) = piksel;

            if (piksel > najjasniejszy)
                najjasniejszy = piksel;

            if (piksel < najciemniejszy)
                najciemniejszy = piksel;
        }

        if (!symetria(piksele.at(i)))
            doUsuniecia++;
    }

    wyniki << najjasniejszy << '\n';
    wyniki << najciemniejszy << '\n';
    wyniki << doUsuniecia << '\n';
    wyniki << wyznaczLiczbeKontrastrujacych(piksele) << '\n';
    wyniki << wyznaczDlugoscNajdluzszejLiniiPionowej(piksele) << '\n';

    return 0;
}

bool symetria(std::vector<int>& v)
{
    for (std::size_t i = 0, j = 319; i < 320; ++i, --j)
        if (v.at(i) != v.at(j))
            return false;

    return true;
}

bool kontrastujace(int a, int b)
{
    if (a == -1 || b == -1)
        return false;

    if (std::abs(a - b) > 128)
        return true;
    else
        return false;
}

int wyznaczLiczbeKontrastrujacych(std::vector<std::vector<int>> v)
{
    int kontrastujacych {0};
    std::set<std::pair<std::size_t, std::size_t>> uwzglednione;

    for (std::size_t i = 0; i < 200; ++i) {
        for (std::size_t j = 1; j < 320; ++j) {
            if (std::abs(v.at(i).at(j - 1) -  v.at(i).at(j)) > 128) {
                if (uwzglednione.find(std::make_pair(i, j - 1)) == uwzglednione.end()) {
                    kontrastujacych++;
                    uwzglednione.insert(std::make_pair(i, j - 1));
                }

                if (uwzglednione.find(std::make_pair(i, j)) == uwzglednione.end()) {
                    kontrastujacych++;
                    uwzglednione.insert(std::make_pair(i, j));
                }
            }
        }
    }

    for (std::size_t i = 1; i < 200; ++i) {
        for (std::size_t j = 0; j < 320; ++j) {
            if (std::abs(v.at(i - 1).at(j) - v.at(i).at(j)) > 128) {
                if (uwzglednione.find(std::make_pair(i - 1, j)) == uwzglednione.end()) {
                    kontrastujacych++;
                    uwzglednione.insert(std::make_pair(i - 1, j));
                }

                if (uwzglednione.find(std::make_pair(i, j)) == uwzglednione.end()) {
                    kontrastujacych++;
                    uwzglednione.insert(std::make_pair(i, j));
                }
            }
        }
    }

    return kontrastujacych;
}

int wyznaczDlugoscNajdluzszejLiniiPionowej(std::vector<std::vector<int>> v)
{
    int najdluzszyCiag {0};
    int tymczasowa {1};
    int porownywana = v.at(0).at(0);

    for (std::size_t i = 1; i < 320; ++i)  {
        for (std::size_t j = 0; j < 200; ++j) {
            if (v.at(j).at(i) == porownywana) {
                tymczasowa++;
            } else {
                if (tymczasowa > najdluzszyCiag) {
                    najdluzszyCiag = tymczasowa;
                }

                tymczasowa = 1;
                porownywana = v.at(j).at(i);
            }
        }
    }

    return najdluzszyCiag;
}
