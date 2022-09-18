#include <iostream>
#include <set>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int licz(int a)
{int wynik=0;
while(a>0)
{  wynik+=(a%10)*(a%10);
   a/=10;
}
return wynik;
}

bool pierwsza(int a)
{
    if (a<2) return 0;
    if(a==2) return 1;
    if(a%2==0) return 0;
    int k=3;
    while(k*k<=a)
        if(a%k==0) return 0;
         else k+=2;
    return 1;
}


int main()
{ ifstream wejscie;
 ofstream  wynik,pomoc;

 wynik.open("wyniki4.txt");
 pomoc.open("pomoc.txt");
int tab[1001]={0};
tab[0]=-1;

set <int> cykl;
set <int>::iterator it;
int pom,suma,ile,maxx;
//przygotowanie tabliczy liczb weso³ych (1) i smutnych(-1) poniewa¿ max. liczba jest równa 2000000000 to maksymalna
//suma bêdzie 729. Jeœli sumê odnajdziemy w tablicy liczb weso³ych i smutnych to bêdzie odpowiednio weso³a lub smutna,
//w zale¿noœci od wartoœci przechowywanej przez tablicê.

for(int i=1;i<1001;i++)
    if(tab[i]==0)
           {cykl.clear();
            suma=i;
           do
           {pom=cykl.size();
            suma=licz(suma);

            cykl.insert(suma);
           }while(suma!=1 && pom!=cykl.size()&&tab[suma]==0);

           if(suma==1 || tab[suma]==1) suma=1; else suma=-1;

              tab[i]=suma;
                for(it=cykl.begin();it!=cykl.end();++it)
                    tab[*it]=suma;
           }


// rozwiazanie 4.1
maxx=0;
cykl.clear();
for(int i=1;i<1001;i++)
 if (tab[i]==1)
      {  suma=i;
         ile=1;
         do
         {suma=licz(suma);
          ile++;}
          while(suma!=1);
        if (maxx<ile)
                     {maxx=ile;
                      cykl.clear();cykl.insert(i);}
        else if(maxx==ile)
               cykl.insert(i);

      }
wynik<<"zad 4.1."<<endl;
wynik<<maxx<<endl;
for(it=cykl.begin();it!=cykl.end();++it)
    wynik<<*it<<" ";
wynik<<endl;

wejscie.open("liczby.txt");
int wejsciowe[2001];
bool wesole[2001]={0};
ile=0;
for(int i=0;i<2000;i++)
{
    wejscie>>suma;
    wejsciowe[i]=suma;
    if(tab[licz(suma)]==1) wesole[i]=1,ile++;

    pomoc<<wesole[i]<<" "<<suma<<endl;
}
wynik<<endl<<"zad. 4.2"<<endl;
wynik<<ile<<endl<<endl;

ile=0;
maxx=0;
int pierwszy, ostatni, p_pierwszy,pol;
for(int i=0;i<2001;i++)
    if(wesole[i])
           if(ile==0)
                 ile++,p_pierwszy=i;
           else
           {if(wejsciowe[i]>wejsciowe[i-1])
                      ile++;
            else
            {if(maxx<ile) maxx=ile,pierwszy=p_pierwszy,ostatni=i-1;
                  ile=1;
                  p_pierwszy=i;
                      }
           }
    else
    {if(maxx<ile) maxx=ile,pierwszy=p_pierwszy,ostatni=i-1;
                  ile=0;

           }
if(maxx<ile) maxx=ile,pierwszy=p_pierwszy,ostatni=1999;

wynik<<endl<<"zad. 4.3"<<endl;
wynik<<maxx<<" "<<wejsciowe[pierwszy]<<" "<<wejsciowe[ostatni]<<endl;

ile=0;
for(int i=0;i<2001;i++)
{if(wesole[i])
     if(pierwsza(wejsciowe[i])) ile++;

}
wynik<<endl<<"zad. 4.4"<<endl;
wynik<<ile<<endl;



wynik.close();
    return 0;
}
