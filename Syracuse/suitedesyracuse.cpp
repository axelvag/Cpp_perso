#include <iostream>
using namespace std ;
int saisie_positive()
{
    int valeur;
    do
    {
        cout<<"donnez un entier strictement positif"<<endl;
        cin>>valeur;
    } while (valeur<=0);
    return valeur;
}

int syracuse(int n)
{
    int iter = 0;
    do
    {
        iter++;
        if (n%2 == 0)
        {
             n/=2;
             cout<<n<<" ";
        }
        else
        {
             n=3*n+1;
             cout<<n<<" ";
        }
    }
    while (n!=1);
    return iter ;
}

int main(void)
{
    int nb, iter;
    iter = syracuse(saisie_positive());
    cout<<"Il faut "<<iter<<" iterations pour trouver 1 !"<<endl;
    return 0;
}
