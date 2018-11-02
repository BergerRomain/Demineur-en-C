#include<stdio.h>
#include<stdlib.h>

#define N 3

typedef struct plateau
{
    char o;
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

void initPlateauV2(plateau* p, int n)
{
	int k;
	(*p).o = 'O';
	for(k = 1 ; k <= n ; k++)
	{
		if(abs = i && ord = j)
		{
			(*p).o = 'V';
			*(p + k) = nextPlateau(p + k - 1);
		}
		else
			*(p + k) = nextPlateau(p + k - 1);
	}
}

void saisieCoordonnees(plateau* p)
{
	int abs, ord;
	printf("Abscisse (entre 1 et 3) : ");
	scanf("%d", &abs);
	printf("Ordonee (entre 1 et 3) : ");
	scanf("%d", &ord);
	/*while ()
	{
		printf("\nVeuillez resaisir les valeurs.\n");
		saisieCoordonnees(p);
	}*/
	initPlateauV2(p, N);
}

void conditionVictoire()
{
	printf("Vous avez gagné, bravo !!");
}

void conditionDefaite()
{
	printf("Vous avez perdu, dommage...");
}

int main()
{
	plateau* p;
	initPlateau(p, N);
	afficheGrillePlateau(p, N);
	saisieCoordonnees(p);
	//while()
	//{
	//	if ()
	//	{
			//conditionDefaite();
			//exit(5);
	//	}
	//	else
			initPlateauV2(p, N);
			afficheGrillePlateau(p, N);
			saisieCoordonnees(p);
	//}
	//conditionVictoire();
	//exit(5);
	return 0;
}