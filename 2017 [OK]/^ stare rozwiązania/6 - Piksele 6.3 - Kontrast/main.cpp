#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    int const szer = 322; // Uwaga! + 2 do podstawowych wartosci, aby pominac trudnosci ze zliczaniem pikseli brzegowych
    int const wys = 202;

    int liczby[wys][szer];

    int kontrastujace=0;

    fstream plik;

    plik.open("dane.txt", ios::in);

    if (plik.good() == true)
    {
        // wstawienie -1 w NOWE brzegi
        for (int i=0; i<wys; i++)
        {
            for (int k=0; k<szer; k++)
            {
                if (i==0 || k==0 || i==wys-1 || k==szer-1)
                {
                    liczby[i][k] = -1;
                }
            }
        }

        for (int i=1; i<wys-1; i++)
        {
            for (int k=1; k<szer-1; k++)
            {
                plik>>liczby[i][k]; // Wczytanie danych
            }
        }

        // 3. zadanie
        for (int i=1; i<ceil((wys-1)/2); i++)
        {
            for (int k=1; k<szer-1; k++)
            {
                if ((abs(liczby[i][k]-liczby[i-1][k]) > 128 && liczby[i-1][k] != -1) || (abs(liczby[i][k]-liczby[i+1][k]) > 128 && liczby[i+1][k] != -1) || (abs(liczby[i][k]-liczby[i][k-1]) > 128 && liczby[i][k-1] != -1) || (abs(liczby[i][k]-liczby[i][k+1]) > 128 && liczby[i][k+1] != -1)) kontrastujace++;
            }
        }
    }
    else
    {
        cout<<"Problem z plikiem";
    }
    plik.close();

    cout<<"Kontrastujace: "<<kontrastujace<<endl<<endl;

    return 0;
}
