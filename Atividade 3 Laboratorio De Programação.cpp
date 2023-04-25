#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <stdbool.h>


int main()
{

//variaveis
int M[5][5];
int N[25][3];
int x=0,y=0,linha;

//comandos

	printf("Lendo a Matriz esparsada M=5x5:\n");
	for ( int i = 0; i < 5 ; i++)
	{
		for (int j=0;j<5;j++)
		{
			printf("M[%d][%d] = ",i,j);
			scanf(" %d", &M[i][j]);
		}
		printf("\n");
	}
	system("cls");
///////////////////////////////////////////////////////////////

		
	for ( int i = 0; i < 5 ; i++)
	{
		for (int j=0;j<5;j++)
		{
			if(M[i][j] != 0)
			{
				int a,b;
				a=i;
				b=j;
				while((a!=6)&&(b!=6))
				{
				N[x][y] = M[i][j];
				y++;
				N[x][y] = i;
				y++;
				N[x][y] = j;
				y=0;
				x++;
				linha++;
				a=6;
				b=6;
				}
			}
		}
	}
/////////////////////////////////////////////////////
printf("Matriz Condensada N=%dx3",linha);

for ( int i = 0; i < linha; i++)
	{
		printf("\n");
		for (int j=0;j<3;j++)
		{
			printf(" %d\t",N[i][j]);
			
		}
	}

	


}








