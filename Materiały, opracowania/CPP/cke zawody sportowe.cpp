#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

void zadanie51(std::vector<unsigned>& vec, std::ofstream& plik);
void zadanie52(std::vector<unsigned>& vec, std::ofstream& plik);
void zadanie53(std::vector<unsigned>& vec, std::ofstream& plik);

int main()
{
    std::ifstream dane{"dziennik.txt"};
    std::ofstream odp{"wynik5.txt"};
    std::vector<unsigned> wyniki;
    unsigned wynik;

    while(dane >> wynik)
        wyniki.emplace_back(wynik);

    zadanie51(wyniki, odp);
    zadanie52(wyniki, odp);
    zadanie53(wyniki, odp);

    return 0;
}

void zadanie51(std::vector<unsigned>& vec, std::ofstream& plik)
{
    unsigned licz = 0;
    unsigned dlNiz3Dni = 0;

    for (std::size_t i = 1; i < vec.size(); ++i)
        if (vec.at(i) > vec.at(i - 1))
            licz++;
        else {
            if (licz > 3)
                dlNiz3Dni++;
            licz = 1;
        }

    plik << "5.1.\n";
    plik << dlNiz3Dni << '\n';
}

void zadanie52(std::vector<unsigned>& vec, std::ofstream& plik)
{
    unsigned min = vec.front();
    unsigned max = vec.front();
    std::size_t indexMin = 0;
    std::size_t indexMax = 0;

    for (std::size_t i = 2; i < vec.size(); i += 2)
        if (vec.at(i) > vec.at(i - 1)) {
            if (vec.at(i) > max) {
                max = vec.at(i);
                indexMax = i;
            }
            if (vec.at(i - 1) < min) {
                min = vec.at(i - 1);
                indexMin = i - 1;
            }
        } else {
            if (vec.at(i - 1) > max) {
                max = vec.at(i - 1);
                indexMax = i - 1;
            }
            if (vec.at(i) < min) {
                min = vec.at(i);
                indexMin = i ;
            }
        }

    plik << "\n5.2.\n";
    plik << "najdluzszy: " << max << '\n';
    plik << "dzien: " << indexMax + 1 << '\n';
    plik << "najkrotszy: " << min << '\n';
    plik << "dzien: " << indexMin + 1 << '\n';
}

void zadanie53(std::vector<unsigned>& vec, std::ofstream& plik)
{
    unsigned licz = 1;
    unsigned najdluzsza = 0;
    std::size_t index;

    for (std::size_t i = 1; i < vec.size(); ++i)
        if (vec.at(i) > vec.at(i - 1))
            licz++;
        else {
            if (licz > najdluzsza) {
                najdluzsza = licz;
                index = i - 1;
            }

            licz = 1;
        }

    plik << "\n5.3.\n";
    plik << "ilosc dni: " << najdluzsza << '\n';
    plik << "centymetrow:  " << vec.at(index) - vec.at(index - najdluzsza + 1) << '\n';
}
