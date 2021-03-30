#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
const int n=20, m=1000;

void czytaj_plansza(vector<vector<int> > &t)
{
    ifstream p("plansza.txt");
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j) p>>t[i][j];
    p.close();
}

int naj(string x)
{
    int ile=0;
    int maks=0;
    int dl=x.size();
    for (int i=0; i<dl; ++i)
    {
        if (x[i]=='E' || x[i]=='W') ile++;
        else
        {
            if (ile>maks) maks=ile;
            ile=0;
        }
       if (ile>maks) maks=ile;
    }
    return (maks);
}

void zawodnicy(vector<vector<int> > t, int &liczba_dys, int &maks_zawodnik, int &maks_wynik, vector<int> &a)
{
    string zawodnik;
    int x, y, wynik;
    ifstream r("robot.txt");
    for (int i=0; i<m; ++i)
    {
        r>>zawodnik;
        x=0;
        y=0;
        wynik=t[x][y];
        for (int j=0; j<zawodnik.size(); ++j)
        {
          switch (zawodnik[j])
            {
            case 'N': x--; break;
            case 'E': y++; break;
            case 'S': x++; break;
            case 'W': y--; break;
            }
            if (x<0 || x>n-1 || y<0 || y>n-1)
            {
               wynik=-1;
               liczba_dys+=1;
               break;
            }
            else wynik+=t[x][y];
        }
        if (maks_wynik<wynik)
            {
                maks_zawodnik=i+1;
                maks_wynik=wynik;
            }
        a[i]=naj(zawodnik);
    }
    r.close();
}

int main()
{
    int liczba_dys=0, maks_zawodnik=1, maks_wynik=0;
    vector<int> w(n), dlugosc(m);
    vector<vector<int> > t(n,w);
    czytaj_plansza(t);
    zawodnicy(t, liczba_dys, maks_zawodnik, maks_wynik, dlugosc);
    cout<<endl<<"Liczba dyskwalifikacji jest rowna "<<liczba_dys<<endl;
    cout<<"Maksymalny wynik osiagnal zawodnik numer "<<maks_zawodnik<<" i wynik ten jest rowny "<<maks_wynik<<endl;
    int maks_EW=dlugosc[0];
    for (int i=1; i<m; ++i)
        if (dlugosc[i]>maks_EW) maks_EW=dlugosc[i];
    cout<<"Maksymalny ciag EW ma dlugosc "<<maks_EW<<endl;
    cout<<"Zawodnicy z maksymalnym ciagiem EW: ";
    for (int i=0; i<m; ++i)
            if (dlugosc[i]==maks_EW) cout<<i+1<<" ";
    return 0;
}
