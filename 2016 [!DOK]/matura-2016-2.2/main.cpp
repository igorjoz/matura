#include <iostream>

using namespace std;

int main()
{
    // Tablica jest numerowana od 1
    // klucz to wartosc pierwszego elemntu tablicy A
    // Po zamianie po lewej znajduja sie elementy mniejsze od klucza, a po prawej elementy wieksze LUB rowne kluczowi

    int n=8; // 8, bo tablice w zadaniu maja byc numerowane od 1 (zerowy element nie ma znaczenia - petla for zaczyna sie od 1)

    int A[8] = {0, 6, 7, 5, 4, 3, 2, 1};
    int klucz=A[1];

    // Wypisanie tablicy przed zamiana
    cout<<"Tablica przed zmianami: "<<endl;
    for (int k=1; k<n; k++)
    {
        cout<<A[k];
    }

    int w=1;

    int licznik=0;

    // Zamiana
    for (int k=2; k<n; k++)
    {
        if (A[k]<klucz)
        {
            int bufor=A[w];
            A[w]=A[k];
            A[k]=bufor;
            w++;
            licznik++;
        }
    }

    // Wypisanie tablicy po zamianie
    cout<<endl<<endl<<"Tablica po zamianach: "<<endl;
    for (int k=1; k<n; k++)
    {
        cout<<A[k];
    }

    cout<<endl<<"Licznik: "<<licznik;

    cout<<endl;
    return 0;
}
