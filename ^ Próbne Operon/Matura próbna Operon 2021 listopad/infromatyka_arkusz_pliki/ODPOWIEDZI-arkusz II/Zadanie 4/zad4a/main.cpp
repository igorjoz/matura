#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;
//funkcja sprawdzajaca czy liczba jest pierwsza
bool pierwsza(int k)
{if(k<2) return false;
  if (k%2==0)
     return (k==2);
 else
 {  int i=3;
    float p=sqrt(k);
    while ((k%i)&&i<p) i+=2;
    return (i>p);
 }

}


int main()
{const int n=10001;
int tab[n]={0},i;
// tab - tablica liczb szczesliwych
//***** tworzenie tablicy liczb szczêœliwych ********
tab[0]=1;
for(int i=2;i<n;i+=2)
    tab[i]++;
int aktualna=3,ktora=2,usun;
while(aktualna<n/5)
{usun=ktora;
 i=aktualna+1;
while(i<n)
 { if(!tab[i])
      {
          usun++;
          if(usun%aktualna==0) tab[i]++;
      }
      i++;
 }
 i=aktualna+1;
 while(tab[i]) i++;
 aktualna=i;
 ktora++;
}
//************** koniec tworzenia tablicy liczb szczesliwych

ifstream inplik;
ofstream ofplik;
inplik.open("dane.txt");
ofplik.open("wyniki4.txt");

vector <int> wejsciowe;

while(!inplik.eof())
     {inplik>>i;
      wejsciowe.push_back(i);}

inplik.close();

int ile=0,ile_pierwszych=0,max_ciag=0, ciag=0,pierwszy;
bool poprzednia=false;
for(i=0;i<wejsciowe.size();i++)
  {
      if(tab[wejsciowe[i]]==0)
        {ile++;    //rozwi¹zanie pkt 4.1
         if (poprzednia) ciag++;
            else
            {if (max_ciag<ciag) max_ciag=ciag,pierwszy=wejsciowe[i-ciag]; //4.2
             ciag=1;
             poprzednia=true;}
          if(pierwsza(wejsciowe[i])) ile_pierwszych++; //4,3
          }
       else
       {  if (max_ciag<ciag) max_ciag=ciag,pierwszy=wejsciowe[i-ciag];
           poprzednia=false;
       }
  }
if (max_ciag<ciag) max_ciag=ciag,pierwszy=wejsciowe[i-ciag];
ofplik<<"Rozwiazanie 4.1"<<endl;
ofplik<<ile<<endl;

ofplik<<"Rozwiazanie 4.2"<<endl;
ofplik<<pierwszy<<" "<<max_ciag<<endl;

ofplik<<"Rozwiazanie 4.3"<<endl;
ofplik<<ile_pierwszych<<endl;


ofplik.close();
    return 0;
}
