#include<stdio.h>
#include<stdlib.h>

#define N 3

typedef struct plateau
{
    char o;
    int abs;
    int ord;
}plateau;

plateau nextPlateau(plateau* previous)
{
  	plateau result;
  	result.o = (*previous).o;
  	return result;
}

void initPlateau(plateau* p, int n)
{
	int i;
	(*p).o = 'O';
	for(i = 1 ; i <= n ; i++)
	{
		*(p + i) = nextPlateau(p + i - 1);
	}
}

void affichePlateau(plateau* p)
{
  	printf(" %c", (*p).o);
}

void afficheGrillePlateau(plateau* p, int n)
{
  	int i, j, k;
 	for(i = 1 ; i <= n ; i++)
    {
    	for(j = 1 ; j <= n ; j++)
      	{
      		affichePlateau(p + i);
      	}
      	printf("\n");
    }  
}

void saisieCoordonnees(plateau* p)
{
	printf("Abscisse (entre 1 et 3) : ");
	scanf("%d", &(*p).abs);
	while((*p).abs < 1 || (*p).abs > 3)
	{
		printf("Veuillez saisir une valeur entre 1 et 3.\n");
		scanf("%d", &(*p).abs);		
	}
	printf("Ordonee (entre 1 et 3) : ");
	scanf("%d", &(*p).ord);
	while((*p).ord < 1 || (*p).ord > 3)
	{
		printf("Veuillez saisir une valeur entre 1 et 3.\n");
		scanf("%d", &(*p).ord);
	}
}

void conditionFinal(plateau* p, int n)
{
	int i = 0;
	while((*p).abs != 2 || (*p).ord != 2)
	{
	  	if (i == 7)
		{
			printf("Vous avez gagne, bravo !!");
			exit(5);
		}
		else
		{
			i = i + 1;
			initPlateau(p, N);
			afficheGrillePlateau(p, N);
			saisieCoordonnees(p);
		}
	}
	printf("Vous avez perdu, dommage...");
	fflush(stdin);
}

void recommencer(plateau* p, int n)
{
	char rep;
	printf("Voulez vous recommencer ? (y/n) :\n");
	scanf("%c", &rep);
	if (rep == 'y')
	{
		initPlateau(p, N);
		afficheGrillePlateau(p, N);
		saisieCoordonnees(p);
		conditionFinal(p, N);
	}
	else
	{
		printf("A bientot !");
		exit(5);
	}
}

int main()
{
	plateau* p;
	initPlateau(p, N);
	afficheGrillePlateau(p, N);
	saisieCoordonnees(p);
	conditionFinal(p, N);
	recommencer(p, N);
	return 0;
}