#include <iostream>
using namespace std;

void som_prod_proc(int n,int &som,int &prod)
{
    int chiffre;
    som = 0;
    prod = 1;
    while(n!=0)
    {
        chiffre=n%10;
        if(chiffre%2==0)
            som+=chiffre;
        else
            prod*=chiffre;
        n/=10;
    }
}

int main(void)
{
    int val,s,p;
    cout<<"Choisissez un nombre"<<endl;
    cin>>val;
    som_prod_proc(val,s,p);
    cout<<"La somme est "<<s<<" et le produit est "<<p;
    return 0;
}
