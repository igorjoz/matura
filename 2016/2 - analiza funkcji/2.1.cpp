#include <iostream>

using namespace std;

int main()
{
    // Tablica jest numerowana od 1
    // klucz to wartosc pierwszego elemntu tablicy A
    /* Po zamianie po lewej znajduja sie elementy mniejsze od klucza,
    a po prawej elementy wieksze LUB rowne od klucza */

    int n=7;

    int A[7] = {0, 4, 6, 3, 5, 2, 1};
    int klucz=A[1];

    // Wypisanie tablicy przed zamiana
    cout<<"Tablica przed zmianami: "<<endl;
    for (int k=1; k<n; k++)
    {
        cout<<A[k];
    }

    int w=1;

    // Zamiana
    for (int k=2; k<n; k++)
    {
        if (A[k]<klucz)
        {
            int bufor=A[w];
            A[w]=A[k];
            A[k]=bufor;
            w++;
        }
    }

    // Wypisanie tablicy po zamianie
    cout<<endl<<endl<<"Tablica po zamianach: "<<endl;
    for (int k=1; k<n; k++)
    {
        cout<<A[k];
    }

    cout<<endl<<endl;
    return 0;
}
