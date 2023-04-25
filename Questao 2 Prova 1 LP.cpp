#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <stdbool.h>

int main()
{
//VARIAVEIS

int notas[100],i=0,porcentagens[3],x=1;
float contador=0;

	
//COMANDOS	
	while (i < 100)
	{
		printf("Insira a nota do Candidato[%d]:\n",i);
		scanf( "%d",&notas[i]);
			if((notas[i] < 0)||(notas[i] > 20))
			{
				printf("Nota invalida. Permitido apenas notas de [0 a 20]:\n");
				while((notas[i] < 0)||(notas[i] > 20))
					{
					scanf( "%d",&notas[i]);	
					}
			}
		i++;
	}
	system("cls");
	for(i=1; i < 21; i++)
	{
		for(int j=0; j < 100;j++)
		{
			if(notas[j] == i)
			{		
				contador++;
				
			}
		}
		printf("Nota[%d]: %.2f %%\n",i,contador);
		contador=0;
	}

return 0;
}
