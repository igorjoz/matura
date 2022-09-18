#include <iostream>
#include<cstdlib>
#include <ctime>
#include <vector>
#include <fstream>

using namespace std;
const int n=20, m=1000;

void plansza(vector<vector<int> > &t)
{
    int x, y, punkty;
    ofstream p("plansza1.txt");
    for (int i=0; i<10*n; ++i)
    {
        x=rand()%n;
        y=rand()%n;
        punkty=rand()%9+1;
        t[x][y]=punkty;
        t[y][x]=punkty;
    }
    for (int i=0; i<n; ++i)
        {
            for (int j=0; j<n; ++j) if (j!=n-1) p<<t[i][j]<<" "; else p<<t[i][j];
            if (i!=n-1) p<<endl;
        }
    p.close();
}
void robot()
{
    ofstream r("robot1.txt");
    for (int i=0; i<m; ++i)
    {
        int ile=rand()%(5*n)+1;
        for (int j=0; j<ile; ++j)
        {
            int k=rand()%4;
            if (k==0) r<<'N';
            if (k==1) r<<'E';
            if (k==2) r<<'S';
            if (k==3) r<<'W';
        }
        if (i!=m-1) r<<endl;
    }
    r.close();
}
int main()
{
    srand(time(NULL));
    vector<int> w(n);
    vector<vector<int> > t(n,w);
    plansza(t);
    robot();
    for (int i=0; i<n; ++i)
        {
           for (int j=0; j<n; ++j) cout<<t[i][j];
           cout<<endl;
        }


     return 0;
}
