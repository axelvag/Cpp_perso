#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <unistd.h>
using namespace std;

class NbComplexe
{

    public:

        /*void setRe(float reel)
        {
            re = reel;
        }
        float getRe()
        {
            return re;
        }
        void setIm(float ima)
        {
            im = ima;
        }
        float getIm()
        {
            return im;
        }*/
        void saisir()
        {
            cout << "Saisir le reel:";
            cin >> re;
            cout << "Saisir l'imaginaire:";
            cin >> im;
        }
        void afficher() const
        {
            if(im >= 0)
            {
                cout << re <<"+"<<im<<"i"<<endl;
            }
            else
            {
                cout << re <<im<<"i"<<endl;
            }
        }
        ///////////////////////////premier constructeur
        NbComplexe()
        {
            re = 0;
            im = 0;
        }
        /*NbComplexe()                   //même chose
        {
            this->re = 0
            this->im = 0
        }*/
        //NbComplexe():re(0),im(0){}     //même chose
        ////////////////////////////deuxieme constructeur
        NbComplexe(float x, float y)
        {
            re = x;
            im = y;
        }
        /*NbComplexe::NbComplexe(float re, float im)
        {
            this->re = x;
            this->im = y;
        }*/
        ////////////////////////////troisieme constructeur
        NbComplexe(const NbComplexe &z)
        {
            re = z.re;
            im = z.im;
        }

        ~NbComplexe()
        {
        }

        void multiplier(const NbComplexe z2)
        {
            float retmp = re;
            re = re * z2.re - im * z2.im;
            im = im * z2.re + retmp * z2.im; //retmp car re est modifie
        }

        float module() const
        {
            return (sqrt(re*re+im*im));
        }

        bool estPlusPetit (const NbComplexe & z) const
        {
            return(module()<z.module());
        }

        NbComplexe& operator =(const NbComplexe z2)
        {
            re = z2.re;     //this->re = z2.re;  est pareil
            im = z2.im;
            return *this;
        }

        bool operator < (const NbComplexe & z) const                       //= estpluspetit
        {
            return(module()<z.module());
        }

        void operator * (const NbComplexe z2)                             //= multiplier
        {
            float retmp = re;
            re = re * z2.re - im * z2.im;
            im = im * z2.re + retmp * z2.im; //retmp car re est modifie
        }

        friend ostream& operator << (ostream &f, const NbComplexe& z)      //ostream le flux de sortie cout
        {
            if(z.im >= 0)
            {
                f << z.re <<"+"<<z.im<<"i";
            }
            else
            {
                f << z.re <<z.im<<"i";
            }
            return f;
        }

        friend istream& operator >> (istream &f, NbComplexe& z)         //istream le flux d'entre cin
        {
            string tmp;
            f >> z.re;
            f >> z.im;
            f >> tmp;
            return f;
        }

    private:

        float re;
        float im;
};

void remplirTab(NbComplexe *tab, int taille)
{
    for(int i = 0; i<taille;i++)
    {
        NbComplexe z((rand()%201)/10.0-10.0,(rand()%201)/10.0-10.0);
        tab[i] = z;
    }
}

void afficherTab(const NbComplexe *tab, int taille)
{
    int i = 0;
    while (i < taille)
    {
        tab[i].afficher();
        cout<<"module:"<<tab[i].module()<<endl;
        i++;
    }
}


void trierParSelection(NbComplexe * tab,int taille)
 {
    int maxi, i;
    NbComplexe tmp;
    while(taille>0)
    {
        maxi=0;               //on recherche la plus grande valeur du tableau non encore trie
        for(i=1;i<taille;i++)
        {
            //if(tab[i].module()>tab[maxi].module())
            if(tab[maxi]<(tab[i]))
                maxi=i;
        }
        //on echange le plus grand element avec le dernier
        tmp = tab[maxi];
        tab[maxi] = tab[taille-1];
        tab[taille - 1] = tmp;
        taille--;   //on traite le reste du tableau
    }
}

void trierParInsertion(NbComplexe * tab,int taille)
{
    int i, compt, marqueur;
    NbComplexe tmp;

    for(i=1;i<taille;i++)
    {
        tmp=tab[i];
        compt=i-1;
        do
        {
            marqueur=false;
            if (tmp<(tab[compt]))
            {
                tab[compt+1]=tab[compt];
                compt--;
                marqueur=true;
            }
            if (compt<0)
                marqueur=false;
        }
        while(marqueur);
        tab[compt+1]=tmp;
    }
}

/*int	atoi(char *str)
{
	int num;
	int i;

	i = 0;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return num;
}


void lireTabNbComplexeDepuisFichier (NbComplexe * &tab, int &taille, char * nom_fichier)
{
    char * recuptaille;
    int i = 0;      //colones
    int j = 1;      //lignes
    int neg = 0;        //negatif
    char * nb;          //nb reel ou imaginaire
    int n = 0;      //les char de nb
    ifstream f("random.txt");
    if (f)
    {
        tab = new NbComplexe[taille];
        while(nom_fichier[i] != '\0')
        {
            recuptaille[i] = nom_fichier[i];     //recup la taille
            i++;
        }
        taille = atoi(recuptaille);
        while(j < taille)
        {
            i = 0;
            neg = 0;
            nb[0] = '\0';
            if(nom_fichier[0] == '-')
            {
                neg = 1;
                i++;
            }
            while(nom_fichier[i] != '\0')
            {
                n = 0;
                while((nom_fichier[i] != '+') || (nom_fichier[i] != '-'))
                {
                    nb[n] = nom_fichier[i];
                    n++;
                    i++;
                }
                tab[j-1].re = atoi(nb);               //marche pas car re est private
                n = 0;
                while((nom_fichier[i] != 'i')
                {
                    nb[n] = nom_fichier[i];
                    n++;
                    i++;
                }
                tab[j-1].im = atoi(nb);                 //marche pas car im est private
                i++;
            }
            j++;
        }
    }
    else
    {
        cout << "La lecture n'as pas aboutit"<<endl;
    }
    return 0;
}*/

void lireTabNbComplexeDepuisFichier (NbComplexe * &tab, int &taille, string &nom_fichier)
{
    ifstream f(nom_fichier);
    if(!f.is_open())
    {
        cout <<"Erreur"<<endl;
        return;
    }
    f >> taille;
    tab = new NbComplexe [taille];
    for(int i = 0; i <taille;i++)
    {
        f >> tab[i];
    }
    f.close();
}

void ecrireTabNbComplexeDansFichier (NbComplexe * tab, int taille, string nom_fichier)
{
    ofstream f(nom_fichier);
    if(!f.is_open())
    {
        cout <<"Erreur"<<endl;
        return;
    }
    f << taille;
    for(int i = 0; i <taille;i++)
    {
        f << tab[i] <<endl;
    }
    f.close();
}

int main()
{
    srand(time(0));
    NbComplexe* tab = NULL;
    int taille;
    string nom_fichier = "random.txt";
    lireTabNbComplexeDepuisFichier(tab,taille,nom_fichier);
    /*for(int i=0; i < taille;i++)
    {
        cout <<tab[i]<<endl;
    }*/
    //ecrireTabNbComplexeDansFichier(tab,taille,nom_fichier);
    /*trierParSelection(tab,taille);
    for(int i=0; i < taille;i++)
    {
        cout <<tab[i]<<endl;
    }*/
    trierParInsertion(tab,taille);
    for(int i=0; i < taille;i++)
    {
        cout <<tab[i]<<endl;
    }
    delete [] tab;


    /*int taille;
    cout << "Taille du tab?"<<endl;
    cin>>taille;
    NbComplexe * tab = new NbComplexe[taille];
    remplirTab(tab,taille);
    afficherTab(tab,taille);

    cout<<"Trie par selection"<<endl;
    trierParSelection(tab,taille);
    afficherTab(tab,taille);

    cout<<"Trie par insertion"<<endl;
    trierParInsertion(tab,taille);
    afficherTab(tab,taille);
    return 0;*/


    /*int taille;
    NbComplexe z;
    z.afficher();
    z.saisir();
    z.afficher();

    NbComplexe z2(z);                  //constructeur par copie
    cout<<"Copie"<<endl;
    z2.afficher();
    NbComplexe * z3 = new NbComplexe;   //tas
    z2.multiplier(*z3);                //multiplie les 2
    cout<<"Multiplication"<<endl;
    z2.afficher();

    cout << "Taille du tab?"<<endl;
    cin>>taille;
    NbComplexe * tab = new NbComplexe[taille];
    remplirTab(tab,taille);
    afficherTab(tab,taille);

    cout<<"Trie par selection"<<endl;
    trierParSelection(tab,taille);
    afficherTab(tab,taille);

    cout<<"Trie par insertion"<<endl;
    trierParInsertion(tab,taille);
    afficherTab(tab,taille);

    delete z3;
    delete [] tab;
    return 0;*/
}
