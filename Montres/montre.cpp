#include <iostream>

using namespace std;

const int CHMAX = 64;
const int MAXMONTRES= 8;

struct montre
{
    char proprietaire[CHMAX];
    char marque[CHMAX];
    int info[3][7];
};

struct famille
{
    int nb_montres;
    struct montre tab[MAXMONTRES];
};

struct montre remplir_montre(struct montre&M)
{
    cout<<"Personne?"<<endl;
    cin>>M.proprietaire;
    cout<<"Marque?"<<endl;
    cin>>M.marque;
    for(int i=0;i<7;i++)
    {
        do{
        cout<<"Nb etages monte?"<<endl;
        cin>> M.info[0][i];
        }while(M.info[0][i]<0);
    }
    for(int i=0;i<7;i++)
    {
        do{
        cout<<"Nb de pas?"<<endl;
        cin>> M.info[1][i];
        }while(M.info[1][i]<0);
    }
    for(int i=0;i<7;i++)
    {
        do{
        cout<<"Frequence cardiaque?"<<endl;
        cin>> M.info[2][i];
        }while(M.info[2][i]<0);
    }
    return M;
}

void affiche_montre(struct montre M)
{
    cout<<"La montre "<<M.marque<<" a "<<M.proprietaire<<endl;
    for(int i=0;i<7;i++)
    {
        cout<<M.info[0][i]<<"    ";
    }
    cout<<endl;
    for(int i=0;i<7;i++)
    {
        cout<<M.info[1][i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<7;i++)
    {
        cout<<M.info[2][i]<<"    ";
    }
    cout<<endl;

}

void ajoute_montre(struct famille&f)
{
    cout<<"Combien de montres dans la famille?"<<endl;
    cin>>f.nb_montres;
    for(int i=0;i<f.nb_montres;i++)
    {
        remplir_montre(f.tab[i]);
        affiche_montre(f.tab[i]);
    }
}

int main()
{
    struct montre Montre;
    struct famille Famille;
    /*Montre=remplir_montre();
    affiche_montre(Montre);*/
    ajoute_montre(Famille);
    return 0;
}
