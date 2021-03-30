#include <iostream>
using namespace std;

bool liczba_odkryta(int liczba)
{
  int pom = liczba, cyfra;
  while (pom > 0)
  {
    cyfra = pom % 10;
    pom /= 10;
    if (cyfra != 0 && liczba % cyfra != 0)
      return false;
  }
  return true;
}

int main()
{
  int n;
  cout << "Podaj liczbe do sprawdzenia: ";
  cin >> n;
  cout << n << (liczba_odkryta(n) ? "" : " nie") << " jest liczba odkryta";
  return 0;
}
