#include <iostream>
#include <math.h>
#include <cmath>
#include <cstdlib>
using namespace std;

struct Vecteur3D
{
	float x,y,z;
};

float Vecteur3DGetNorme(const Vecteur3D &v)
{
	float norme;
	norme = sqrt((v.x * v.x)+(v.y * v.y)+ (v.z * v.z));
	return norme;
}

void Vecteur3DNormaliser(Vecteur3D &v)
{
	float n = Vecteur3DGetNorme(v);
	if( n != 0)
	{
		v.x /= n;
		v.y /= n;
		v.z /= n;
	}
}

bool Vecteur3DEstNormalise(const Vecteur3D &v)
{
	float n = Vecteur3DGetNorme(v);
	if(fabs(n-1) < 1e-6)
		return 1;
	else
		return 0;
}

Vecteur3D Vecteur3DAdd(Vecteur3D &v1, Vecteur3D &v2)
{
	Vecteur3D v3;
	v3.x = v1.x + v2.x;
	v3.y = v1.y + v2.y;
	v3.z = v1.z + v2.z;
	return v3;
}

void Vecteur3DAfficher(Vecteur3D v)
{
	cout << "("<< v.x << "," << v.y <<"," << v.z << ")"<<endl;
}

void Vecteur3DRemplirTabVecteurs(Vecteur3D tab[], int taille)
{
	for(int i = 0; i < taille; i++)
	{
		tab[i].x = (rand()%201)/10.0-10.0;  //entre -10 et 10
		tab[i].y = (rand()%201)/10.0-10.0;
		tab[i].z = (rand()%201)/10.0-10.0;
	}
}

void Vecteur3DAfficherTabVecteurs(Vecteur3D tab[], int taille)
{
	for(int i = 0; i < taille; i++)
	{
		cout << "("<< tab[i].x << "," << tab[i].y <<"," << tab[i].z << ")"<<endl;
	}
}

int	Vecteur3DMaxTabVecteurs(Vecteur3D tab[], int taille)
{
	int i, max=0;
	for(i = 0; i < taille; i++)
	{
		if (Vecteur3DGetNorme(tab[i]) > Vecteur3DGetNorme(tab[max]))
		{
			max = i;
		}
	}
	return max;
}

void Vecteur3DConcatenationTabVecteurs(Vecteur3D tab1[], Vecteur3D tab2[], Vecteur3D tab3[], int taille1 , int taille2)
{
	cout << "Adresse de tab1[] : " << (long int) &tab1 << endl;
	cout << "Adresse de tab1[] : " << (long int) &tab2 << endl;
	cout << "Adresse de tab1[] : " << (long int) &tab3 << endl;


	for(int i = 0; i < taille1;i++)
	{
		tab3[i].x = tab1[i].x;
		tab3[i].y = tab1[i].y;
		tab3[i].z = tab1[i].z;
	}
	cout << "Adresse de tab3[0] : " << (long int) &tab3[0] << endl;
	cout << "Adresse de tab3[1] : " << (long int) &tab3[1] << endl;
	for(int j = 0;j< taille2; j++)
	{
		tab3[taille1+j].x = tab3[j].x;
		tab3[taille1+j].y = tab3[j].y;
		tab3[taille1+j].z = tab3[j].z;
	}
}

void Vecteur3DInverseTabVecteurs(Vecteur3D tab[],int taille)
{
	Vecteur3D temp;
	int i = 0;
	int j = taille -1;
	while(i<j)
	{
		temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;
		i++;
		j--;
	}
}

void procedureAvecPointeur (int * ptr)
{
	cout << ptr<<endl;
	cout << &ptr<<endl;
}

void procedureAvecReference (int & rf)
{
	cout << rf <<endl;
	cout << &rf <<endl;
}

void procedureAvecInt (int val)
{
	cout << val <<endl;
	cout << &val <<endl;
}

int main()
{
	Vecteur3D vec1;
	cout << "Taille occupée par Vecteur3D en mémoire : " << sizeof(vec1) <<endl;
	Vecteur3D vec2;
	cout << "Taille occupée par pointeur sur Vecteur3D : " << sizeof(vec2) <<endl;
	Vecteur3D tabVecteurPile [3];
	Vecteur3D * tabVecteurTas = new Vecteur3D [3];
	Vecteur3DRemplirTabVecteurs(tabVecteurPile, 3);
	tabVecteurTas[0].x = tabVecteurPile[0].x;
	tabVecteurTas[0].y = tabVecteurPile[0].y;
	tabVecteurTas[0].z = tabVecteurPile[0].z;
	tabVecteurTas[1].x = tabVecteurPile[1].x;
	tabVecteurTas[1].y = tabVecteurPile[1].y;
	tabVecteurTas[1].z = tabVecteurPile[1].z;
	tabVecteurTas[2].x = tabVecteurPile[2].x;
	tabVecteurTas[2].y = tabVecteurPile[2].y;
	tabVecteurTas[2].z = tabVecteurPile[2].z;
	cout << "Taille occupée par tabPile : " << sizeof(tabVecteurPile) << endl;
	cout << "Taille occupée par tabTas : " << sizeof(tabVecteurTas) << endl;
	cout << "Adresse de tabPile[0] : " << (long int) &tabVecteurPile[0] <<endl;
	cout << "Adresse de tabTas[0] : " << (long int) &tabVecteurTas[0] <<endl;
	Vecteur3DAfficher(*(tabVecteurPile+2));
	Vecteur3DAfficher(*(tabVecteurTas+2));

	int x = 1;
	int & rx = x;
	int * px = &x;

	cout << x<<endl;
	cout << rx<<endl;
	cout << px<<endl;
	cout << "Adresse de x : " << (long int) &x<<endl;
	cout << "Adresse de rx : " << (long int) &rx<<endl;
	cout << "Adresse de px : " << (long int) &px<<endl;

	procedureAvecPointeur(px);
	procedureAvecReference(x);
	procedureAvecInt(rx);
	return 0;
}

/*int main()
{
	srand(time(0));
	Vecteur3D tab1[10], tab2[10] ,tab3[20];
	Vecteur3DRemplirTabVecteurs(tab1, 10);
	Vecteur3DRemplirTabVecteurs(tab2, 10);
	cout<<"TAB 1"<<endl;
	Vecteur3DAfficherTabVecteurs(tab1, 10);
	cout<<"TAB 2"<<endl;
	Vecteur3DAfficherTabVecteurs(tab2, 10);
	Vecteur3DConcatenationTabVecteurs(tab1 ,tab2,tab3,10,10);
	cout<<"TAB 3"<<endl;
	Vecteur3DAfficherTabVecteurs(tab3,20);
	cout<<"TAB 3 reverse"<<endl;
	Vecteur3DInverseTabVecteurs(tab3,20);
	Vecteur3DAfficherTabVecteurs(tab3,20);
}*/
/*int main()
{
	Vecteur3D v = {5,5,5};

	cout << Vecteur3DGetNorme(v);
	return 0;
}*/

/*int main(int argc, char **argv)
{
	Vecteur3D v;
	if(argc == 4)
	{
		v.x = argv[1][0] - '0';
		v.y = argv[2][0] - '0';
		v.z = argv[3][0] - '0';
		cout << Vecteur3DEstNormalise(v) <<endl;
	}
	return 0;
}*/

/*int main () {
	Vecteur3D vecteur1 = {5,2,1};
	Vecteur3D vecteur2 = {0,3,2};
	cout << "vecteur1 non normalise: ";
	Vecteur3DAfficher(vecteur1);
	cout << endl;
	cout << "vecteur2 non normalise: ";
	Vecteur3DAfficher(vecteur2);
	cout << endl;
	cout << "somme: ";
	Vecteur3DAfficher(Vecteur3DAdd(vecteur1,vecteur2));
	cout << endl;
	Vecteur3DNormaliser(vecteur1);
	Vecteur3DNormaliser(vecteur2);
	cout << "vecteur1 normalise: ";
	Vecteur3DAfficher(vecteur1);
	cout << endl;
	cout << "vecteur2 normalise: ";
	Vecteur3DAfficher(vecteur2);
	cout << endl;
	cout << "somme: ";
	Vecteur3D somme = Vecteur3DAdd(vecteur1,vecteur2);
	Vecteur3DAfficher(somme);
	if (Vecteur3DEstNormalise(somme)) cout << " est normalise" << endl;
	else cout << " n'est pas normalise" << endl;
	return 0;
}*/
