#include <stdio.h>

//Fonctions qui demande les deux operandes et affiche le resultat.
void DemandeAddition()
{
	int a, b;

	printf("Entrer a\n");
	scanf_s("%d", &a);
	printf("Entrer b\n");
	scanf_s("%d", &b);

	printf("a + b = %d\n", a + b);
	printf("\n");
}

void DemandeSoustraction()
{
	int a, b;
	
	printf("Entrer a\n");
	scanf_s("%d", &a);
	printf("Entrer b\n");
	scanf_s("%d", &b);

	printf("a - b = %d\n", a - b);
	printf("\n");
}

void DemandeDivision()
{
	int a, b;

	printf("Entrer a\n");
	scanf_s("%d", &a);
	printf("Entrer b\n");
	scanf_s("%d", &b);

	printf("a / b = %d\n", a / b);
	printf("\n");
}

void DemandeMultiplication()
{
	int a, b;

	printf("Entrer a\n");
	scanf_s("%d", &a);
	printf("Entrer b\n");
	scanf_s("%d", &b);

	printf("a x b = %d\n", a * b);
	printf("\n");
}

//Fin d'operations

//Fonction qui lance le menu de la calculatrice

void Calculatrice()
{
	int choix;

	do
	{
		printf("0 - Quitter\n1 - Addition\n2 - Soustraction\n3 - Division\n4 - Multiplication\n");
		scanf_s("%d", &choix);


		if (choix == 1)
		{
			DemandeAddition();
		}
		else if (choix == 2)
		{
			DemandeSoustraction();
		}
		else if (choix == 3)
		{
			DemandeDivision();
		}
		else if (choix == 4)
		{
			DemandeMultiplication();
		}
	} while (choix != 0);
}

int main()
{
	Calculatrice();
	return 0;
}