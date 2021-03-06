#include <iostream>
#include <fstream>
#include <string>
#include <array>

class GraWZycie
{
public:

    GraWZycie()
    {
        std::fstream plikGry("gra.txt", std::ios::in);
        std::string str;

        for (unsigned i = 0; i != plansza.size(); ++i)
        {
            plikGry >> str;

            for (unsigned j = 0; j != plansza[i].size(); ++j)
                plansza[i][j] = str[j];
        }
        plikGry.close();
    }

    // X TO WIERSZE, Y TO KOLUMNY!!!
    unsigned liczbaSasiadow(int x, int y)
    {
        unsigned sasiedzi = 0;
        int px = x - 1;

        for(int i = 0; i < 3; ++i) //
        {
            if (px == 12)
                px = 0;
            if (px == - 1)
                px = 11;

            int py = y -1;

            for (int j = 0; j < 3; ++j)
            {

                if (py == 20)
                    py = 0;
                if (py == - 1)
                    py = 19;

                if (plansza[px][py] == 'X')
                    sasiedzi++;

                py++;
            }

            px++;
        }

        if (plansza[x][y] == 'X')
            return sasiedzi - 1; // bo sprawdza samego siebie
        else
            return sasiedzi;
    }

    unsigned liczbaZywych()
    {
        unsigned zywych = 0;

        for (const auto &pl: plansza)
            for (const auto &pole: pl)
                if (pole == 'X')
                    zywych++;
        return zywych;
    }

    unsigned liczbaMartwych()
    {
        unsigned martwych = 0;

        for (const auto &pl: plansza)
            for (const auto &pole: pl)
                if (pole == '.')
                    martwych++;
        return martwych;
    }

    void nastepnePokolenie()
    {
        std::array<std::array<char, 20>, 12> temp;

        for (unsigned i = 0; i != plansza.size(); ++i)
            for (unsigned j = 0; j != plansza[i].size(); ++j)
                if (ewolucja(plansza[i][j], i, j))
                    temp[i][j] = 'X';
                else
                    temp[i][j] = '.';

        plansza = temp;
    }

    void pokaz(int x, int y)
    {
        std::cout << plansza[x][y];
    }

    void rysujPlansze()
    {
        for (const auto &pl: plansza)
        {
            for (const auto &pole: pl)
                std::cout << pole;
            std::cout << '\n';
        }
    }

    std::array<std::array<char, 20>, 12> zwrocPlansze()
    {
        return plansza;
    }

private:
    std::array<std::array<char, 20>, 12> plansza;

    bool ewolucja(char c, unsigned x, unsigned y)
    {
        unsigned sasiadow = liczbaSasiadow(x, y);

        if (c == '.' && sasiadow == 3)
            return true;
        if (c == 'X' && (sasiadow == 2 || sasiadow == 3))
            return true;

        return false;
    }
};

int main()
{
    std::fstream wynik("wyniki5.txt", std::ios::out);

    // ZAD 5.1
    GraWZycie gra1;

    for (int i = 0; i < 36; ++i) // na poczatku gry jest pokolenie 1, a wiec zeby bylo pokolenie 37, trzeba przeprowadzic ewolucje 36 razy, nie 37!!!
        gra1.nastepnePokolenie();

    std::cout << "5.1 liczba sasiadow dla komorki(2, 19) w 37 pokoleniu: " <<  gra1.liczbaSasiadow(1, 18) << '\n'; // drugi wierwsz, dziewietnasta kolumna
    wynik << "5.1 liczba sasiadow dla komorki(2, 19): " <<  gra1.liczbaSasiadow(1, 18) << '\n';

    // ZAD 5.2
    GraWZycie gra2;
    gra2.nastepnePokolenie();

    std::cout << "5.2 liczba zywych w drugim pokoleniu: " << gra2.liczbaZywych() << '\n';
    wynik << "5.2 liczba zywych w drugim pokoleniu: " << gra2.liczbaZywych() << '\n';

    // ZAD 5.3
    GraWZycie gra3;

    unsigned pokolenie = 1;
    auto plansza = gra3.zwrocPlansze();

    for (unsigned i = 1; i != 100; ++i) // maks do 100 pokolenia, czyli masz 99 w przód
    {
        pokolenie++;
        gra3.nastepnePokolenie();

        if (plansza == gra3.zwrocPlansze())
            break;

        plansza = gra3.zwrocPlansze();
    }

    std::cout << "5.3 pokolenie: " << pokolenie << ", liczba zywych: " << gra3.liczbaZywych() << '\n';
    wynik << "5.3 pokolenie: " << pokolenie << ", liczba zywych: " << gra3.liczbaZywych() << '\n';

    return 0;
}
