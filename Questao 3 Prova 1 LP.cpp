#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <stdbool.h>

int main()
{
//VARIAVEIS

int M[10][4];
int fila,coluna,livres=0,ocupadas=0, testador=0;
char condicao='S';

	
//COMANDOS	
	for ( int i = 0; i < 10 ; i++)
	{
		for (int j=0;j<4;j++)
		{
			M[i][j] = 0;
		}
	}
	//CONDIDATO WHILE QUE INCLUI TODO O PROGRAMA E SO PARA COM AS CONDIÇOES DETERMINADAS
	while(condicao == 'S')
	{
	
		//RESERVANDO POLTRONAS ATRAVES DO USUARIO
			printf("Entre com fila e posicao da poltrona respectivamente:\n");
			scanf(" %d%d",&fila,&coluna);
			
			if(M[fila-1][coluna-1] == 0)
			{
				M[fila-1][coluna-1] = 1;
				printf("Poltrona reservada com sucesso\n");
			}
			else
			{
				printf("Poltrona %d x %d Ocupada, Escolha Outra.\n",fila,coluna);
			}
		//CONFERINDO SE O USUARIO QUER CONTINUAR OU NAO
		printf("Digite [S] para continuar\nDigite [N] para encerrar\n");
		scanf(" %c",&condicao);
		//CONFIMAÇÃO DE QUE A MATRIZ AINDA NAO ESTA TOTALMENTE OCUPADA
			for ( int i = 0; i < 10 ; i++)
			{
				for (int j=0;j<4;j++)
				{
					if(M[i][j] == 1)
					{
						testador++;
					}
				}
			}
			if(testador==40)
			{
				condicao = 'N';
			}
			system("cls");
	}
	//CALCULANDO QUANTAS POLTRONAS ESTAO OCUPADAS E QUANTAS ESTAO LIVRES
	for ( int i = 0; i < 10 ; i++)
	{
		for (int j=0;j<4;j++)
		{
			if(M[i][j]==1)
			{
				ocupadas++;
			}
				
			else
			{
				livres++;
			}
		}
	}
	system("cls");
	printf("Poltronas livres: %d\nPoltronas Ocupadas: %d",livres,ocupadas);
return 0;
}
