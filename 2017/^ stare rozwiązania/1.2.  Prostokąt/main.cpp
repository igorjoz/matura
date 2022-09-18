#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream dane;
    dane.open("dane.txt");
    if (dane.good())
    {
        int ile;
        int liczby[ile];
        cin>>ile;
        for (int i=0; i<ile; i++)
        {
            cin>>liczby[i];
        }
    }
    else
    {
        cout<<"Problem z plikiem";
    }
    dane.close();
    return 0;
}
