#include <iostream>
using namespace std;

const int TAILLE_LIGNE=3;
const int TAILLE_COLONNE=3;

void initialiseGrille(char grille[TAILLE_LIGNE][TAILLE_COLONNE])
{
    int i,j;
    for(i=0;i<TAILLE_LIGNE;i++)
        {
            for(j=0;j<TAILLE_COLONNE;j++)
            {
                    grille[i][j] = '_';
            }
        }
}

void afficheGrille(char grille[TAILLE_LIGNE][TAILLE_COLONNE])
{
    int i,j;
    for (i=0;i<TAILLE_LIGNE;i++)
        {
            for(j=0;j<TAILLE_COLONNE;j++)
            {
                    cout<<grille[i][j]<<"|";
            }
        cout<<endl;
        }
}

void  metUnPionSurLaGrille(char  grille[TAILLE_LIGNE][TAILLE_COLONNE], char &joueur)
{
    int gagne = 0;
    int L,C;
    while (gagne==0)
    {
        cout<<endl;
        cout<<"Joueur "<<joueur<<" a vous!"<<endl;
        cout<<"Quelle ligne?"<<endl;
        cin>>L;
        cout<<"Quelle colonne?"<<endl;
        cin>>C;
        while (L>=TAILLE_LIGNE || C>=TAILLE_COLONNE)        //pour avoir des num de ligne et colonne qui existes
        {
            cout<<"Pas dans la grille RECOMMENCEZ!"<<endl;
            cout<<"Quelle ligne?"<<endl;
            cin>>L;
            cout<<"Quelle colonne?"<<endl;
            cin>>C;
        }
        if (joueur == 'X')
            if (grille[L][C]=='X' || grille[L][C]=='O')
                cout<<"CASE DEJA PRISE!"<<endl;
            else
                grille[L][C]='X';      //met X si joueur 1
        else
            if (grille[L][C]=='X' || grille[L][C]=='O')
                cout<<"CASE DEJA PRISE!"<<endl;
            else
                grille[L][C]='O';      //met O si joueur 2


        afficheGrille(grille);

        if (grille[0][0]==joueur && grille[0][1]==joueur && grille[0][2]==joueur)
            gagne=1;
        if (grille[1][0]==joueur && grille[1][1]==joueur && grille[1][2]==joueur)
            gagne=1;
        if (grille[2][0]==joueur && grille[2][1]==joueur && grille[2][2]==joueur)
            gagne=1;
        if (grille[0][0]==joueur && grille[1][0]==joueur && grille[2][0]==joueur)
            gagne=1;
        if (grille[0][1]==joueur && grille[1][1]==joueur && grille[2][1]==joueur)
            gagne=1;
        if (grille[0][2]==joueur && grille[1][2]==joueur && grille[2][2]==joueur)
            gagne=1;
        if (grille[0][0]==joueur && grille[1][1]==joueur && grille[2][2]==joueur)
            gagne=1;
        if (grille[0][2]==joueur && grille[1][1]==joueur && grille[2][0]==joueur)
            gagne=1;

        if (joueur == 'X')         //modification du joueur
            joueur = 'O';
        else
            joueur = 'X';

    }
    cout<<"GAGNE!!!";
}

int main(void)
{
    char grille[TAILLE_LIGNE][TAILLE_COLONNE];

    initialiseGrille(grille);

    afficheGrille(grille);

    char joueur='X';
    metUnPionSurLaGrille(grille,joueur);

    return 0;
}
