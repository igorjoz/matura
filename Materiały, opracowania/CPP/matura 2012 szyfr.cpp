#include <iostream>
#include <fstream>
#include <string>

std::string szyfruj(std::string slowo, std::string klucz)
{
    std::string szyfr;
    unsigned dlKlucza = klucz.length();

    for (unsigned i = 0; i != slowo.size(); ++i)
        if ((slowo[i] + klucz[(i + dlKlucza) % dlKlucza] - 64) > 90)
            szyfr += (char)(slowo[i] + klucz[(i + dlKlucza) % dlKlucza] - 64 - 26);
        else
            szyfr += (char)(slowo[i] + klucz[(i + dlKlucza) % dlKlucza] - 64);

    return szyfr;
}

std::string deszyfruj(std::string szyfr, std::string klucz)
{
    std::string slowo;
    unsigned dlKlucza = klucz.length();

    for (unsigned i = 0; i != szyfr.size(); ++i)
        if ((szyfr[i] - klucz[(i + dlKlucza) % dlKlucza] + 64) < 65)
            slowo += (char)(szyfr[i] - klucz[(i + dlKlucza) % dlKlucza] + 64 + 26);
        else
            slowo += (char)(szyfr[i] - klucz[(i + dlKlucza) % dlKlucza] + 64);

    return slowo;
}

int main()
{
    std::ifstream tj("tj.txt", std::ios::in);
    std::ifstream k1("klucze1.txt", std::ios::in);
    std::ofstream wa("wynik4a.txt", std::ios::out);
    std::string slowo;
    std::string klucz;

    // SZYFROWANIE
    while (tj >> slowo && k1 >> klucz)
    {
        wa << szyfruj(slowo, klucz);
        std::cout << szyfruj(slowo, klucz) << '\n';
    }

    tj.close();
    k1.close();
    wa.close();

    // DESZYFROWANIE
    std::cout << '\n';
    std::ifstream sz("sz.txt", std::ios::in);
    std::ifstream k2("klucze2.txt", std::ios::in);
    std::ofstream wb("wynik4b.txt", std::ios::out);

    while (sz >> slowo && k2 >> klucz)
    {
        wb << deszyfruj(slowo, klucz);
        std::cout << deszyfruj(slowo, klucz) << '\n';
    }

    sz.close();
    k2.close();
    wb.close();

    return 0;
}
