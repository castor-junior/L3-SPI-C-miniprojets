#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Fonctions

//Boucle de jeu, renvoie int "essai" (le nombre d'essai du joueur), utilise paramètre "n" pour comparer avec la réponse "rep" du joueur
int Boucle_Jeu(int n)
{
	int essai = 0, rep;

	do
	{
		printf("\n");										//Sauter une ligne pour faire jolie
		printf("Donnez un entier\n"); scanf_s("%d", &rep);
		essai++;											//incrementer essai pour chaque réponse du joueur
		if (rep > n)
		{
			printf("Trop grand ! Recommencez !\n");
		}
		else if (rep < n)
		{
			printf("Trop petit ! Recommencez !\n");
		}

	} while (rep != n);

	printf("\n");
	printf("Bravo,vous avez trouve %d\n", n);
	return essai;
}

//Jeu niveau debutant, lancer avec int "n" entre 1 et 50 a deviner par le joueur
void Jeu_Debutant()
{
	srand((unsigned)time(NULL));
	//Générer un nombre dans [1,50] avec rand()
	int n = (rand() % 50) + 1;

	printf("\n");
	printf("Pour les tests, la reponse est %d\n", n);
	//Lancer la boucle de jeu, le nombre d'essai est affiché
	printf("Nombre d'essai : %d\n", Boucle_Jeu(n));
}

//Jeu niveau intermédiare, nombre à deviné choisi au hasard par rand(), le nombre d'essai est compter et affiché à la fin
void Jeu_Intermediaire()
{
	
	srand((unsigned)time(NULL));
	//Générer un nombre dans [1,100] avec rand()
	int n = (rand() % 100) + 1;

	printf("\n");
	printf("Pour les tests, la reponse est %d\n", n);	//On affiche ici la réponse just pour faciliter les tests
	
	printf("Nombre d'essai : %d\n", Boucle_Jeu(n));		//Ici, je ne sais pas si le fait de lancer Boucle_Jeu() dans le printf créerai d'éventuel problème,
}														//mais je trouve que c'est plutot élégant de faire comme ça.

void Jeu_Difficile()
{
	srand((unsigned)time(NULL));
	//Générer un nombre dans [1,100] avec rand()
	int n = (rand() % 500) + 1;

	printf("\n");
	printf("Pour les tests, la reponse est %d\n", n);	//On affiche ici la réponse juste pour faciliter les tests
	printf("Nombre d'essai : %d\n", Boucle_Jeu(n));
}

//Menu pour demander si le joueur veut rejouer, renvoie int 0 pour non, int 1 pour oui
int Rejouer()
{
	int rejouer;
	printf("\n");							//Sauter une ligne pour faire jolie
	printf("Voulez vous rejouer ?\n\n");
	printf("0 - Non\n");
	printf("1 - Oui\n");
	scanf_s("%d", &rejouer);

	return rejouer;

}

//Lance le menu principal et utilise Rejouer() et la varaiable "rejouer" pour déterminer si on quitte Lancer_Jeu() ou pas, si on ne quitte pas, relancer le menu principal
void Lancer_Jeu()
{
	int choix, rejouer = 0;
	do
	{
		printf("\n");								//Sauter une ligne pour faire jolie
		//Menu principal
		printf("0 - Quitter\n");				
		printf("1 - Niveau Facile (1-50)\n");
		printf("2 - Niveau Moyen (1-100)\n");
		printf("3 - Niveau Difficile (1-500)\n");
		scanf_s("%d", &choix);

		if (choix == 0)
		{
			rejouer = choix;
		}

		else if (choix == 1)
		{
			Jeu_Debutant();
			rejouer = Rejouer();
		}
		else if (choix == 2)
		{
			Jeu_Intermediaire();
			rejouer = Rejouer();
		}
		else if (choix == 3)
		{
			Jeu_Difficile();
			rejouer = Rejouer();
		}
	} while (rejouer != 0);

	printf("\n");
	printf("Au revoir !\n");
}


//Fin Fonctions

int main()
{
	Lancer_Jeu();
	return 0;
}

