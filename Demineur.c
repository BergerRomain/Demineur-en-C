#include<stdio.h>
#include<stdlib.h>

#define N 3

typedef struct plateau
{
    char o;
    char abs;
    char ord;
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
  	int i, j;
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

void conditionVictoire()
{
	printf("Vous avez gagne, bravo !!");
}

void conditionDefaite()
{
	printf("Vous avez perdu, dommage...");
}

void conditionFinal(plateau* p, int n)
{
	int i = 0;
	do
	{
	  	if (i == 7)
		{
			conditionVictoire();
			exit(5);
		}
		else
		{
			i = i +1;
			initPlateau(p, N);
			afficheGrillePlateau(p, N);
			saisieCoordonnees(p);
		}
	}
	while((*p).abs != 2 || (*p).ord != 2);
	conditionDefaite();
	exit(5);
}

int main()
{
	plateau* p;
	initPlateau(p, N);
	afficheGrillePlateau(p, N);
	saisieCoordonnees(p);
	conditionFinal(p, N);
	return 0;
}