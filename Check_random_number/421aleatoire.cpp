#include <iostream>
using namespace std;

void combinaison_des(int & de1,int & de2, int&de3)
{
    de1=rand()%6+1;
    de2=rand()%6+1;
    de3=rand()%6+1;
}

void tri_des(int &de1,int &de2,int &de3)
{
    int tampo;
    if (de1 < de2)
    {
        tampo=de1;
        de1=de2;
        de2=tampo;
    }
    if (de1 < de3)
    {
        tampo=de1;
        de1=de3;
        de3=tampo;
    }
    if (de2 < de3)
    {
        tampo=de2;
        de2=de3;
        de3=tampo;
    }
}

bool verifie_combinaison(int de1,int de2,int de3)
{
    return ((de1==4)&&(de2==2)&&(de3==1));
}

int main(void)
{
    int d1,d2,d3;
    int nbcoup = 0;
    srand(time(NULL));
    do
    {
        nbcoup++;
        combinaison_des(d1,d2,d3);
        tri_des(d1,d2,d3);
    }
    while(!verifie_combinaison(d1,d2,d3));
    cout << "Il a fallu "<<nbcoup<<" coups";
    return 0;
}
