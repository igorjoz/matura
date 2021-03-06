#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

struct Odczyt
{
    unsigned int godzina;
    int temp;
};

std::vector<Odczyt> wczytaj(std::string nazwaPliku, int podstawa);
int zSystemu(std::string str, int podstawa);
void zad1(std::vector<Odczyt> s1, std::vector<Odczyt> s2, std::vector<Odczyt> s3);
std::string naSystem(int num, int podstawa);
void zad2(std::vector<Odczyt> s1, std::vector<Odczyt> s2, std::vector<Odczyt> s3);
void zad3(std::vector<Odczyt> s1, std::vector<Odczyt> s2, std::vector<Odczyt> s3);
void zad4(std::vector<Odczyt> s1);

int main()
{
    auto s1 = wczytaj("dane_systemy1.txt", 2);
    auto s2 = wczytaj("dane_systemy2.txt", 4);
    auto s3 = wczytaj("dane_systemy3.txt", 8);

    zad1(s1, s2, s3);
    zad2(s1, s2, s3);
    zad3(s1, s2, s3);
    zad4(s1);

    return 0;
}

std::vector<Odczyt> wczytaj(std::string nazwaPliku, int podstawa)
{
    std::vector<Odczyt> vec;
    std::ifstream dane{nazwaPliku};
    std::string t1, t2;

    while (dane >> t1 >> t2)
        vec.push_back({zSystemu(t1, podstawa), zSystemu(t2, podstawa)});

    return vec;
}

int zSystemu(std::string str, int podstawa)
{
    if (str.front() == '-')
        return -1 * (std::strtol(str.substr(1, str.length() - 1).c_str(), nullptr, podstawa));
    else
        return std::strtol(str.c_str(), nullptr, podstawa);
}

void zad1(std::vector<Odczyt> s1, std::vector<Odczyt> s2, std::vector<Odczyt> s3)
{
    std::ofstream wyn("wyniki_systemy.txt", std::ios::app);
    int min1 = s1.front().temp;
    int min2 = s2.front().temp;
    int min3 = s3.front().temp;

    for (std::size_t i = 1; i < s1.size(); ++i) {
        if (s1.at(i).temp < min1)
            min1 = s1.at(i).temp;
        if (s2.at(i).temp < min2)
            min2 = s2.at(i).temp;
        if (s3.at(i).temp < min3)
            min3 = s3.at(i).temp;
    }

    wyn << "Podpunkt 1:\n";
    wyn << "Minimalna temperatrura w s1: " << naSystem(min1, 2) << '\n';
    wyn << "Minimalna temperatrura w s1: " << naSystem(min2, 2) << '\n';
    wyn << "Minimalna temperatrura w s1: " << naSystem(min3, 2) << '\n';
}

std::string naSystem(int num, int podstawa)
{
    std::string liczba;
    bool ujemna = false;

    if (num < 0) {
        ujemna = true;
        num *= -1;
    }

    while (num > 0) {
        char c = '0' + num % podstawa;
        if (c > '9')
            c += 7;
        liczba = c + liczba;
        num /= podstawa;
    }

    if (ujemna)
        liczba = '-' + liczba;

    return liczba;
}

void zad2(std::vector<Odczyt> s1, std::vector<Odczyt> s2, std::vector<Odczyt> s3)
{
    std::ofstream wyn("wyniki_systemy.txt", std::ios::app);
    unsigned licz = 0;
    unsigned godzina = 12;

    for (std::size_t i = 0; i < s1.size(); ++i) {
        if (s1.at(i).godzina != godzina && s2.at(i).godzina != godzina && s3.at(i).godzina != godzina)
            licz++;
        godzina += 24;
    }

    wyn << "Podpunkt 2:\n";
    wyn << "Liczba niepoprawnych pomiarow jednoczesnie: " << licz << '\n';
}

void zad3(std::vector<Odczyt> s1, std::vector<Odczyt> s2, std::vector<Odczyt> s3)
{
    std::ofstream wyn("wyniki_systemy.txt", std::ios::app);
    int max1 = s1.front().temp;
    int max2 = s2.front().temp;
    int max3 = s3.front().temp;
    unsigned licz = 1;
    bool rekord;

    for (std::size_t i = 1; i < s1.size(); ++i) {
        rekord = false;

        if (s1.at(i).temp > max1) {
            max1 = s1.at(i).temp;
            rekord = true;
        }

        if (s2.at(i).temp > max2) {
            max2 = s2.at(i).temp;
            rekord = true;
        }

        if (s3.at(i).temp > max3) {
            max3 = s3.at(i).temp;
            rekord = true;
        }

        if (rekord)
            licz++;
    }

    wyn << "Podpunkt 3:\n";
    wyn << "Liczba dni rekordowych: " << licz << '\n';
}

void zad4(std::vector<Odczyt> s1)
{
    std::ofstream wyn("wyniki_systemy.txt", std::ios::app);
    int najwiekszySkok = 0;

    for (std::size_t i = 0; i < s1.size(); ++i)
        for (std::size_t j = i + 1; j < s1.size(); ++j) {
            int kwadrat = (s1.at(i).temp - s1.at(j).temp) * (s1.at(i).temp - s1.at(j).temp);
            int skok = kwadrat / (j - i);

            if (skok * (j - i) < kwadrat)
                skok++;

            if (skok > najwiekszySkok)
                najwiekszySkok = skok;

        }

    wyn << "Podpunkt 4:\n";
    wyn << "Najwiekszy skok: " << najwiekszySkok << '\n';
}
