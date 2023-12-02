#include <iostream>
#include <string.h>
using namespace std;

const int CHMAX=64;
const int MAX_MONTRES=8;

struct montre
{
    char proprietaire[CHMAX];
    char marque[CHMAX];
    int info[3][7];
};

struct famille
{
    int nb_montre;
    struct montre tab[MAX_MONTRES];
};

void remplir_montre(struct montre &M)
{
    cout<<"Nom?"<<endl;
    cin>>M.proprietaire;
    cout<<"Marque?"<<endl;
    cin>>M.marque;
    for(int i=0;i<7;i++)
    {
        do{
        cout<<"Nb etage?"<<endl;
        cin>>M.info[0][i];
        }while(M.info[0][i]<0);
    }
    for(int i=0;i<7;i++)
    {
        do{
        cout<<"Nb de pas?"<<endl;
        cin>>M.info[1][i];
        }while(M.info[1][i]<0);
    }
    for(int i=0;i<7;i++)
    {
        do{
        cout<<"Frequence cardiaque?"<<endl;
        cin>>M.info[2][i];
        }while(M.info[2][i]<0);
    }
}

void affiche_montre(struct montre M)
{
    cout<<"La montre "<<M.marque<<" de "<<M.proprietaire<<" :"<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<7;j++)
        {
            cout<<M.info[i][j]<<"   ";
        }
        cout<<endl;
    }
}

void ajoute_une_montre(struct famille &F)
{
    cout<<"Nb de montres?"<<endl;
    cin>>F.nb_montre;
    for(int i=0;i<F.nb_montre;i++)
    {
        remplir_montre(F.tab[i]);
    }
}

void moyenne(int T[7],float &moy_tot,float &moy_part)
{
    int mini=T[0], maxi=T[0];
    moy_tot=T[0];
    for(int i=0;i<7;i++)
    {
        if(mini>T[i])
            mini = T[i];
        if(maxi<T[i])
            maxi = T[i];
        moy_tot+=T[i];
    }
    moy_tot=moy_tot/7.0;
    moy_part=(moy_part-mini-maxi)/5.0;
}

void calcul_moyenne_montre(struct montre &M,float Tmoy[3][2])
{
    for(int i=0;i<3;i++)
    {
        moyenne(M.info[i],Tmoy[i][0],Tmoy[i][1]);
    }
}

void affiche_tab_moy(float Tmoy[3][2])
{
    cout<<"Tableau de moyenne :"<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<Tmoy[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void affiche_perf(struct famille F,char nom[CHMAX])
{
    float res[3][2];
    for(int i=0;i<F.nb_montre;i++)
    {
        if(strcmp(F.tab[i].proprietaire,nom)==0)
        {
            affiche_montre(F.tab[i]);
            cout<<endl;
            calcul_moyenne_montre(F.tab[i],res);
            affiche_tab_moy(res);
        }
    }
}

int main()
{
    char prenom[CHMAX];
    struct montre Montre;
    struct famille Famille;
    /*remplir_montre(Montre);
    affiche_montre(Montre);*/
    ajoute_une_montre(Famille);
    cout<<"Vous voulez les donnees de qui?"<<endl;
    cin>>prenom;
    affiche_perf(Famille,prenom);
    return 0;
}
