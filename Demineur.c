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
	char* o;
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

int main()
{
	plateau* p;
	initPlateau(p, N);
	afficheGrillePlateau(p, N);
	return 0;
}