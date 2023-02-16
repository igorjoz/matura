#include <cmath>
#include<cstdio>
#include<algorithm>
using namespace std;

const double a = 0.02, b = 0.0005, c = 0.05;

void zadanie1()
{
    double Z = 100.0, W = 30.0;
    for (int n=1; n<=5*12; n++)
    {
        double nZ = Z + a*Z - b*Z*W;
        double nW = W + b*Z*W - c*W;
        Z = nZ;
        W = nW;
    }
    printf("Zadanie 1:\nPo uplywie 5 lat\nZ=%.2f,  W=%.2f\n", Z, W);
}

void zadanie2()
{
    printf("Zadanie 2:\n");
    double Z = 100.0, W = 30.0;
    int k=1, odpZ=0, odpW=0;
    while (odpZ==0 || odpW==0)
    {
        double nZ = Z + a*Z - b*Z*W;
        double nW = W + b*Z*W - c*W;
        if ( nZ < Z && odpZ == 0 ) odpZ = k;
        if ( nW < W && odpW == 0 ) odpW = k;
        Z = nZ;
        W = nW;
        k++;
    }
    printf("Z_n < Z_(n-1) dla n=%d\n", odpZ);
    printf("W_n < W_(n-1) dla n=%d\n", odpW);
}

void zadanie3()
{
    double Z = 100.0, W = 30.0;
    printf("0 %f %f\n", Z, W);
    for (int n=1; n<=20*12; n++)
    {
        double nZ = Z + a*Z - b*Z*W;
        double nW = W + b*Z*W - c*W;
        Z = nZ;
        W = nW;
        printf("%d %f %f\n", n, Z, W);
    }
}

void zadanie4()
{
    printf("Zadanie 4:\n");
    double Z = 100.0, W = 30.0;
    double minZ, maxZ, minW, maxW;
    minZ = maxZ = Z; minW = maxW = W;
    for (int n=1; n<=40*12; n++)
    {
        double nZ = Z + a*Z - b*Z*W;
        double nW = W + b*Z*W - c*W;
        Z = nZ;
        W = nW;
        minZ = min( minZ, Z ); maxZ = max( maxZ, Z );
        minW = min( minW, W ); maxW = max( maxW, W );
    }
    printf("MIN : %8.2f | %8.5f\n", minZ, minW);
    printf("MAX : %8.2f | %8.2f\n", maxZ, maxW);
}

int main()
{
    zadanie1();
    zadanie2();
    // zadanie3();
    zadanie4();
    return 0;
}
