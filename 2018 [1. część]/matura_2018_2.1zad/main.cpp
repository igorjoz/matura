#include <iostream>
#include <cstdlib>

using namespace std;

int n;
int naj_lewo=0;

bool blad; // Zmienna do walidacji wprowadzanych danych

void walidacja_wprowadzanych_danych (int n, int y);

int main()
{
    // Pobranie ilosci wierzcholkow
    cout<<"Podaj n: ";
    cin>>n;

    walidacja_wprowadzanych_danych (n, 1);

    // Stworzenie tablic wspolrzednych
    float X[n];
    float Y[n];

    cout<<endl;

    // Pobieranie danych wierzcholkow
    for (int i=0; i<n; i++)
    {
        cout<<endl<<i+1<<". wierzcholek:"<<endl;
        cout<<"Os x: ";
        cin>>X[i];

        cout<<"Os y: ";
        cin>>Y[i];

        walidacja_wprowadzanych_danych (1, Y[i]);
    }

    cout<<endl<<endl<<"Znalezienie liczby najbardziej na lewo:"<<endl;
    // Znalezienie najmniejszej liczby - czyli wierzcholka najbardziej na lewo
    for (int i=0; i<n; i++)
    {
        cout<<endl<<i+1<<". wierzcholek:"<<endl;
        cout<<"Os x: ";
        cout<<X[i]<<endl;

        cout<<"Os y: ";
        cout<<Y[i]<<endl;

        cout<<"PODZIELENIE: "<<X[i] / Y[i]<<endl;
        if (i+1!=n)
        {
            cout<<"(Podzielenie kolejnego wierzchoka: "<<X[i+1] / Y[i+1]<<")"<<endl;
        }

        if ((X[i] / Y[i]) < (X[i+1] / Y[i+1]) && ((X[i] / Y[i]) <= (X[naj_lewo] / Y[naj_lewo])))
        {
            naj_lewo=i;
        }
    }

    cout<<endl<<endl<<"Wierzcholek najbardziej na lewo: "<<naj_lewo+1;
    // Dodanie 1, poniewaz wierzchalki w tablicy sa sortowane od 0, a wyswietlane od 1

    cout<<endl<<endl;
    return 0;
}

void walidacja_wprowadzanych_danych (int n, int y)
{
    if (n<0)
    {
        cout<<"Blad! Zmienna n nie moze byc ujemna!";
        exit(0);
    }

    if (y<=0)
    {
        cout<<"Blad! Wspolrzedna y nie moze byc mniejsza lub rowna 0!";
        exit(0);
    }
}
