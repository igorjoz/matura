#include <iostream>

using namespace std;

int n, p;
int q, s;

int main()
{
    //cin>>n;

    int ile=0;

    n=1000;

    p=1;
    q=n;

    while (p<q)
    {
        s=(p+q)/2;

        if ((s*s*s)<n)
        {
            p=s+1;
            ile+=1;
        }
        else
        {
            q=s;
        }
    }

    cout<<p;
    cout<<endl<<endl<<ile;
    //cout<<i<<". : "<<p<<endl;

    return 0;
}
