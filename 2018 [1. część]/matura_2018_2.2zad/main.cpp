#include <iostream>

using namespace std;

int n;

int main()
{
    // Pobranie ilosci wierzcholkow
    cout<<"Podaj n: ";
    cin>>n;

    int n_kopia=n;

    // Stworzenie tablic wspolrzednych
    float X[n];
    float Y[n];

    float podzielenie[n][2];

    cout<<endl;

    // Pobieranie danych wierzcholkow
    for (int i=0; i<n; i++)
    {
        cout<<endl<<i+1<<". wierzcholek:"<<endl;
        cout<<"Os x: ";
        cin>>X[i];

        cout<<"Os y: ";
        cin>>Y[i];

        podzielenie[i][0] = X[i] / Y[i];
        podzielenie[i][1] = i+1;

        cout<<"Podzielenie (x/y): "<<podzielenie[i][0]<<endl;
    }

    // Sortowanie babelkowe (od najmniejszej do najwiekszej)
    cout<<endl<<endl<<"*Sortowanie babelkowe (od najmniejszej do najwiekszej)*"<<endl;

    float bufor=0;
    int bufor2=0;

    for (int i=0; i<n; i++)
    {
        for (int k=1; k<n-i; k++)
        {
            if (podzielenie[k-1][0] > podzielenie[k][0])
            {
                bufor=podzielenie[k][0];

                podzielenie[k][0]=podzielenie[k-1][0];
                podzielenie[k-1][0]=bufor;


                bufor2=podzielenie[k][1];
                podzielenie[k][1]=podzielenie[k-1][1];
                podzielenie[k-1][1]=bufor2;
            }
        }
    }

    // Wypisanie posortowanego wynikow podzielenia
    cout<<endl<<"Wartosci wierzcholkow kolejno widocznych od lewej dla obserwatora:"<<endl;
    for (int i=0; i<n; i++)
    {
        cout<<i+1<<". wierzcholek: "<<podzielenie[i][0]<<endl;
    }
    // Dodanie 1, poniewaz wierzcholki w tablicy sa ulozone od 0, a na ukladzie kartezjanskim numerowane od 1

    cout<<endl<<endl;

    // Wypisanie posortowanego wynikow podzielenia
    cout<<endl<<"Wierzcholki (numery) kolejno widoczne od lewej dla obserwatora:"<<endl;
    for (int i=0; i<n; i++)
    {
        cout<<i+1<<". wierzcholek (wartosc podzielenia): "<<podzielenie[i][1]<<endl;
    }
    // Dodanie 1, poniewaz wierzcholki w tablicy sa ulozone od 0, a na ukladzie kartezjanskim numerowane od 1

    cout<<endl<<endl;
    return 0;
}
