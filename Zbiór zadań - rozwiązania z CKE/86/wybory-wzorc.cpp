#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;

#define nokr 20
#define nkom 5
#define nreg 4
ofstream out;

int tab[nokr][nkom],wyniki[nokr][nkom];
int wynReg[nreg][nkom],wynGlob[nkom];
string naz[nokr];

void fmandaty(int glosy[],int s[], int ilem, int ilek){
// glosy - liczba glosow
// s - tu bedzie liczba mandatow
// ilem - ile mandatow
// ilek - ile komitetow
 int i,j,indmax;
 double x[nkom];
 //int x[nkom];

 for(i=0;i<ilek;i++) {
        s[i]=0; x[i]=1.0*glosy[i];
        //cout << x[i]<<" ";
 }

 for(i=0;i<ilem;i++){
    indmax=0;
    for(j=1;j<ilek;j++){
        if (x[j]>x[indmax]) {indmax=j;
        /*cout << x[j] << endl;*/}
    }
    s[indmax]++;
    x[indmax]=glosy[indmax]/(2.0*s[indmax]+1);

 }

}

void zad1(){
 int i,j,tabsum[nokr];

 for(i=0;i<nokr;i++) tabsum[i]=0;
 for(i=0;i<nokr;i++)
    for(j=0;j<nkom;j++)
        tabsum[i]+= tab[i][j];

 out << "Zadanie 1: " << endl;
 for(i=0;i<nokr;i++)
    out << naz[i] << ": " << tabsum[i] << endl;


}

void zad2(){
 int i,j,maxnumer[nkom];
 double akt,sum,maxproc[nkom];

 for(i=0;i<nkom;i++) {
        maxproc[i]=0.0; maxnumer[i]=0;
 }
 for(i=0;i<nokr;i++){
    sum=0.0;
    for(j=0;j<nkom;j++) sum+=tab[i][j];
    for(j=0;j<nkom;j++){
        akt=tab[i][j]/sum;
        if (akt>maxproc[j]){
            maxproc[j]=akt;
            maxnumer[j]=i;
        }
    }
 }
 out << "Zadanie 2: " << endl;
 for(i=0;i<nkom;i++)
    out << "K" << i+1 << ": " << naz[maxnumer[i]] << endl;


}



void zad3(){
    int i,j;

    out << "Zadanie 3: " << endl;

    for(i=0;i<nokr;i++){
        fmandaty(tab[i],wyniki[i], 20, 5);
    }
 int maxo[nkom];
 for(i=0;i<nkom;i++) maxo[i]=0;
 for(i=0;i<nokr;i++) {
    for(j=0;j<nkom;j++){
        //cout << wyniki[i][j] << " ";
        if (wyniki[i][j]>maxo[j])
            maxo[j]=wyniki[i][j];
        //if (wyniki[i][j]>wyniki[maxo[j]][j])
        //    maxo[j]=i;
    }
    //cout << endl;
    //cout << s[i] << " ";
 }

 for(i=0;i<nkom;i++)
    out << "K" << i+1<< ": " << maxo[i]<< endl;

}

void zad4(){

    int i,j,k,pocz,tabR[nreg][nkom];

    out << "Zadanie 4: " << endl;

    for(i=0;i<nreg;i++){
        for(j=0;j<nkom;j++) tabR[i][j]=0;
        pocz=i*5;
        for(k=0;k<nkom;k++)
            for(j=pocz;j<pocz+5;j++)
                tabR[i][k]+=tab[j][k];
    }
    for(i=0;i<nreg;i++){
        fmandaty(tabR[i],wynReg[i], 100, 5);
        //for(int j=0;j<5;j++) cout << wynReg[i][j] << " ";
        //cout << endl;
    }

 int maxo[nkom];
 int sum[nkom], sumReg[nkom];
 for(i=0;i<nkom;i++) {
    sum[i]=sumReg[i]=0;
    for(j=0;j<nokr;j++){
        sum[i]+= wyniki[j][i];
        //cout << wyniki[j][i] << " ";
    }
    //cout << endl;
    for(j=0;j<nreg;j++){
        sumReg[i]+= wynReg[j][i];
    }

 }

 out << "Standardowy: " << endl;
 for(i=0;i<nkom;i++)
    out << "K" << i+1 <<": "<< sum[i]<<endl;
 out << "Regionalny: " << endl;
 for(i=0;i<nkom;i++)
    out << "K" << i+1 <<": "<< sumReg[i]<<endl;

//for(j=0;j<nreg;j++) cout << wynReg[0][j] << " ";
     //cout << endl;
    //cout << s[i] << " ";
 }


void zad5(){
    int testin[nkom], testout[nkom];
    int glosow=100000;
    int mandatow=20;
    int lmandatow[3]={20,40,100};
    int i,j;

    out << "Zadanie 5: " << endl;
    //testin[0]=1050;testin[1]=950;
    for(j=0;j<3;j++){
        mandatow=lmandatow[j];
        for(i=1;i<=glosow/2; i++){
            testin[0]=i;
            testin[1]=glosow-i;
            fmandaty(testin,testout, mandatow, 2);
            //cout << testout[0] << " " << testout[1] << endl;
            if (testout[0]==testout[1]){
                out << "Dla m="<< mandatow/2 <<": " << i << endl;
                break;
            }
        }
    }

}

int main()
{   int i,j,k;

    //srand (time(NULL));

	ifstream in;
    //in.open("przyklad_trojkaty.txt");
	in.open("dane_wybory.txt");
	out.open("wyniki_wybory.txt");

    int ile = nokr;
    for(i=0;i<ile;i++){
        in >> naz[i];
        //cout << naz[i];
        for(j=0;j<5; j++){
            in >> tab[i][j];
            //cout << tab[i][j];
        }
        cout << endl;
        //cout << licz[i] << " " << mian[i] << endl;
    }



    zad1();
    zad2();
    zad3();
    zad4();
    zad5();

    //int testin[nkom], testout[nkom];

    //testin[0]=810;testin[1]=300;testin[2]=540;

    //fmandaty(testin,testout, 6, 3);

    //testin[0]=1050;testin[1]=950;testin[2]=540;

    //fmandaty(testin,testout, 10, 2);

    //for(i=0;i<2;i++){
    //    cout << "K"<< i<<": " << testout[i] << endl;
    //}
    out.close();
    return 0;
}
