#include <iostream>
#include <string.h>
using namespace std;

const char CHARMAX=50;

struct piste
{
    char nom[CHARMAX];
    char couleur[CHARMAX];
    int longueur;
    bool ouverte;
};

struct domaine
{
    char nom[CHARMAX];
    int prix;
    int nb_piste;
    piste P[100];
};

void affiche_piste(struct piste p)
{
    cout<<"La piste ce nomme "<<p.nom<<endl;
    cout<<"Difficulte : "<<p.couleur<<endl;
    cout<<"De "<<p.longueur<<"km"<<endl;
    if(p.ouverte==1)
        cout<<"Ouverte : Oui"<<endl;
    else
        cout<<"Ouverte : Non"<<endl;
}

void remplir_piste(struct piste &p)
{
    char tamp[10];
    cout<<"Nom de la piste?"<<endl;
    cin>>p.nom;
    cout<<"Difficulte de piste? (vert,bleu,rouge ou noir)"<<endl;
    cin>>p.couleur;
    cout<<"Longueur?"<<endl;
    cin>>p.longueur;
    cout<<"Ouverte (Oui/Non)"<<endl;
    cin>>tamp;
    if(strcmp(tamp,"Oui")==0)
        p.ouverte=true;
    else
        p.ouverte=false;
}

void remplir_domaine(struct domaine &d)
{
    cout<<"Nom du domaine"<<endl;
    cin>>d.nom;
    cout<<"Tarif?"<<endl;
    cin>>d.prix;
    cout<<"Combien de pistes dans le domaine?"<<endl;
    cin>>d.nb_piste;
    for(int i=0;i<d.nb_piste;i++)
    {
        remplir_piste(d.P[i]);
    }
}

void affiche_domaine(struct domaine d)
{
    cout<<endl;
    int i,j=1;
    cout<<"Domaine "<<d.nom<<endl;
    cout<<d.prix<<"$"<<endl;
    for(i=0;i<d.nb_piste;i++)
    {
        cout<<"PISTE "<<j<<endl;
        affiche_piste(d.P[i]);
        j++;
    }

}

void comparaison(struct domaine d)
{
    int longTotal=0,pourcentouvert,coutkm;
    for(int i=0;i<d.nb_piste;i++)
    {
        longTotal=longTotal+d.P[i].longueur;
        if(d.P[i].ouverte==1)
            pourcentouvert=pourcentouvert+1;

    }
    pourcentouvert=(pourcentouvert/d.nb_piste)*10;
    coutkm=d.prix/longTotal;

    cout<<"Longueur totale: "<<longTotal<<"km"<<endl;
    cout<<pourcentouvert<<"% de pistes pas ouvertes"<<endl;
    cout<<"Cout kilometrique : "<<coutkm<<endl;
}

int main()
{
    struct domaine Domaine;
    struct piste Piste;
    /*remplir_piste(Piste);
    affiche_piste(Piste);*/
    remplir_domaine(Domaine);
    affiche_domaine(Domaine);
    comparaison(Domaine);
    return 0;
}
