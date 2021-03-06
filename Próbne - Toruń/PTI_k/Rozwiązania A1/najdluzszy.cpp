#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int najdluzszy_od_1(int n, int *t){
       int wynik= 0;
    int kolejna= 1;
    for (int i = 0; i<n; ++i)
        if (t[i] == kolejna)
        {
            wynik = wynik + 1;
            kolejna = kolejna + 1;
        }
    return wynik;
}

int main()
{
  int n;
  cout << "Ile liczb losujesz? ";
  cin >> n;
  int tab[n];
  for (int i=0; i<n; ++i) cin>>t[i];
  cout << "\n"<<"Dlugosc najdluzszego ciagu od 1 jest rowna: "<<najdluzszy_od_1(n, tab);
  return 0;
}
