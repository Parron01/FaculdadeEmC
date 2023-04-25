#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <stdbool.h>


int main()
{

//variaveis
int i=0,x,m=1,cont=0,j;
float valores[10];

//comandos
	for (int x=0; x < 10; x++)
	{
	printf("Digite o valor numero [%d]:\n",x);
	scanf(" %f",&valores[x]);
	}
	
	system("cls");

	for( x=1;x<11;x++)
	{
		if (valores[x-1] < valores[x])
		{
			m++;
		}
		else
		{
			cont++;
			
			printf("\nEntrada do segmento %d, i = %d \nTamanho do segmento %d, m = %d\n\n",cont,i,cont,m);
			i=x;
			m=1;
		}
		
	}
	


}
