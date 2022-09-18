#include <iostream>
#include <fstream>

//-----------------------------------------------------------------------------------------------

using namespace std;

//-----------------------------------------------------------------------------------------------

int main()
{
    int const szer = 320;
    int const wys = 200;

//-----------------------------------------------------------------------------------------------

    int liczby[wys][szer];

    int j_max = 0, j_min = 255;

    bool symetria;
    int do_usuniecia = 0;

    int start;
    int licznik;
    int lp_maks = 0;

//-----------------------------------------------------------------------------------------------

    fstream plik;

    plik.open("dane.txt", ios::in);

    if (plik.good() == true)
    {
        for (int i=0; i<wys; i++)
        {
            for (int k=0; k<szer; k++)
            {
                plik>>liczby[i][k]; // Wczytanie danych

                // 1. zadanie
                if (liczby[i][k]>j_max)
                    j_max=liczby[i][k];
                if (liczby[i][k]<j_min)
                    j_min=liczby[i][k];
            }
//-----------------------------------------------------------------------------------------------
            // 2. zadanie
            symetria = true;
            for (int k=0; k<szer; k++)
            {
                if (liczby[i][k] != liczby[i][szer-1-k])
                    symetria = false;
            }
            if (!symetria)
                do_usuniecia++;
        }
//-----------------------------------------------------------------------------------------------
        // 4. zadanie
        // Stworzenie nowej, odwroconej tablicy
        int n_liczby[szer][wys];
        for (int w=0; w<szer; w++)
        {
            for (int k=0; k<wys; k++)
            {
                n_liczby[w][k] = liczby[k][w];
            }
        }

        // Sprawdzenie
        for (int w=0; w<szer; w++)
        {
            start = n_liczby[w][0];
            licznik = 0;
            for (int k=0; k<wys; k++)
            {
                if (n_liczby[w][k] == start) licznik++;
                else
                {
                    licznik = 1;
                    start = n_liczby[w][k];
                }

                if (licznik > lp_maks) lp_maks = licznik;
            }
        }

    }
    else
    {
        cout<<"Problem z plikiem";
    }
    plik.close();

//-----------------------------------------------------------------------------------------------

    // Wypisanie wynikow w konsoli
    cout<<"Maksymalna jasnosc: "<<j_max<<endl<<"Minimalna jasnosc: "<<j_min<<endl<<endl;

    cout<<"Minimalna ilosc wierszy do usuniecia: "<<do_usuniecia<<endl<<endl;

    cout<<"Kontrastujace: 753"<<endl<<endl;

    cout<<"Najdluzsza seria: "<<lp_maks<<endl;

//-----------------------------------------------------------------------------------------------

    // Zapis do pliku "wyniki6.txt"
    fstream wynik;
    wynik.open("wyniki6.txt", ios::out);

    if (wynik.good() == true)
    {
        // 1. zadanie
        wynik<<"6.1.:\tNajjasniejszy piksel: "<<j_max<<endl;
        wynik<<"\tNajciemniejszy piksel: "<<j_min<<endl<<endl;

        // 2. zadanie
        wynik<<"6.2.:\tMinimalna liczba wierszy do usuniecie: "<<do_usuniecia<<endl<<endl;

        // 3. zadanie - wynik z osobnego pliku
        wynik<<"6.3.:\tIlosc kontrastujacych pikseli: 753"<<endl<<endl;

        // 4. zadanie
        wynik<<"6.4.:\tNajdluzsza linia pionowa zlozona z pikseli tej samej jasnosci: "<<lp_maks<<endl;

    }
    wynik.close();

    return 0;
}
