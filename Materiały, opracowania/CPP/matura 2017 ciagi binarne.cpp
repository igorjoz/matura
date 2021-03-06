#include <iostream>
#include <fstream>
#include <bitset>
#include <string>

bool dwucykliczny(std::string str);
struct CiagDwucykliczny
{
    std::string napis;
    int dlugosc;
};
bool poprawny(std::string str);
int naDziesietny(std::string str);
bool zaDuza(std::string str);

int main()
{
    std::ifstream dane {"binarne.txt"};
    std::string napis;
    int dwucyklicznych {0};
    CiagDwucykliczny CD {std::string(""), 0};
    int niepoprawnych {0};
    int najkrotszy {32767};
    std::string najwiekszaBIN {0};
    unsigned long long najwiekszaDEC {0};
    std::ofstream wyniki {"zadanie4.txt"};

    while (dane >> napis) {

        if (dwucykliczny(napis)) {
            dwucyklicznych++;

            if (napis.size() > CD.dlugosc) {
                CD.dlugosc = napis.size();
                CD.napis = napis;
            }
        }

        if (!poprawny(napis)) {
            niepoprawnych++;

            if (napis.size() < najkrotszy)
                najkrotszy = napis.size();
        }

        if (!zaDuza(napis))
            if (naDziesietny(napis) <= 65535)
                if (naDziesietny(napis) > najwiekszaDEC) {
                    najwiekszaDEC = naDziesietny(napis);
                    najwiekszaBIN = napis;
                }

    }

    wyniki << "4.1. liczba dwucyklicznych " << dwucyklicznych << '\n';
    wyniki << "najdluzszy napis " << CD.napis << '\n';
    wyniki << "jego dlugosc " << CD.dlugosc << '\n';
    wyniki << "\n4.2 liczba niepoprwanych " << niepoprawnych << '\n';
    wyniki << "dlugosc najkrotszego " << najkrotszy << '\n';
    wyniki << "\n4.3 najwieksza liczba " << najwiekszaDEC << '\n';
    wyniki << "jej postac w zapisie binarnym " << najwiekszaBIN << '\n';

    return 0;
}

bool dwucykliczny(std::string str)
{
    auto pierwszaPolowa = str.substr(0, str.size() / 2);
    auto drugaPolowa = str.substr(str.size() / 2, str.size() / 2);

    return pierwszaPolowa == drugaPolowa;
}

bool poprawny(std::string str)
{
    for (std::size_t i = 0; i < str.size(); i += 4)
        if (naDziesietny(str.substr(i,4)) > 9)
            return false;

    return true;
}

int naDziesietny(std::string str)
{
    return std::bitset<16>(str).to_ulong();
}

bool zaDuza(std::string str)
{
    return str.size() > 16;
}
