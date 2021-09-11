#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int liczby[320];
    int j_max = 0, j_min = 255;
    fstream plik;

    plik.open("dane.txt", ios::in);

    if (plik.good() == true)
    {
        for (int i=0; i<200; i++)
        {
            for (int k=0; k<320; k++)
            {
                plik>>liczby[k];

                if (liczby[k]>j_max) j_max=liczby[k];
                if (liczby[k]<j_min) j_min=liczby[k];
            }
        }
        //getline (plik, liczby[0]);
        plik.close();
    }
    else
    {
        cout<<"Problem z plikiem";
    }

    cout<<"Maksymalna jasnosc: "<<j_max<<endl<<endl<<"Minimalna jasnosc: "<<j_min;

    fstream wynik;
    wynik.open("wyniki6.txt", ios::out);

    if (wynik.good() == true)
    {
        wynik<<"6.1.:"<<endl<<"\tNajjasniejszy piksel: "<<j_max<<endl;
        wynik<<"\tNajciemniejszy piksel: "<<j_min<<endl<<"------------------------------------"<<endl<<endl;
    }
    wynik.close();


    return 0;
}
