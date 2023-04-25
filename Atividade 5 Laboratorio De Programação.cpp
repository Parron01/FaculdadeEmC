#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
//variaveis
typedef struct Tatleta {
int codigo;
char nome[50];
int quantvoltas;
float *tempos;
float tempototal;
float mediatempos;
int VoltasAbaixoDaMediaDoVencedor;	
} Tatleta;

bool achou=false;
int n,i,desempate=0,comparador=5000;
float somadostempos;
int voltamaisrapida=5000,maiorquantvoltas=0;
char vencedor[50];
int vencedores[n];
float mediavencedor;

	
//comandos
Tatleta *infos;
//LENDO A QUANTIDADE DE ATLETAS E ALOCANDO MEMORIA PARA O REGISTRO.
printf("Quantos atletas participaram da competicao?\n");
scanf(" %d",&n);
infos = (Tatleta * ) malloc(n * sizeof(Tatleta));
system("cls");
//LENDO TODAS AS INFORMACOES DOS ATLETAS.
	for(i=0; i<n; i++)
	{
	somadostempos=0;
		printf("Digite o codigo do atleta %d :\n",i+1);
		scanf(" %d",&infos[i].codigo);
		printf("Digite o nome do atleta %d :\n",i+1);
		scanf(" %[^\n]s", infos[i].nome);
		printf("Digite a quantidade de voltas realizadas:\n");
		scanf(" %d", &infos[i].quantvoltas);
		//DETERMINANDO A MAIOR QUANTIDADE DE VOLTAS REALIZADAS PARA DETERMINAR O VENCEDOR DEPOIS.
						if(maiorquantvoltas < infos[i].quantvoltas)
					{
						maiorquantvoltas = infos[i].quantvoltas;
					}
		//ALOCANDO MEMORIA PARA OS TEMPOS DE ACORDO COM A QUANTIDADE DE VOLTAS.
			infos[i].tempos = (float *) malloc (infos[i].quantvoltas * sizeof(float));
			for(int k=0; k < infos[i].quantvoltas; k++)
			{
				printf("Digite o tempo em segundos da volta %d\n",k+1);
				scanf("  %f", &infos[i].tempos[k]);
				somadostempos = somadostempos + infos[i].tempos[k];
		//DESCOBRINDO A VOLTA MAIS RAPIDA.
					if(voltamaisrapida > infos[i].tempos[k])
					{
						voltamaisrapida = infos[i].tempos[k];
					}
			}
		//CALCULANDO TEMPO TOTAL E MEDIA DOS TEMPOS DE CADA ATLETA.
		infos[i].tempototal = somadostempos;
		infos[i].mediatempos = somadostempos / infos[i].quantvoltas;
		system("cls");
	}
	
	
	//DEFININDO O VENCEDOR COM O CRITERIO DE DESEMPATE E REGISTRANDO SEU NOME COMO VENCEDOR.
	int j=0;
	for(i=0; i<n; i++)
	{
		if(infos[i].quantvoltas == maiorquantvoltas)
		{
	//DESCOBRINDO QUANTOS ATLETAS CORRERAM A MESMA QUANTIDADE DE VOLTAS.
			desempate++;
			vencedores[j] = i;	
			j++;
			
			if(desempate >= 2)
			{
				for(int x=0; x < desempate; x++)
				{
					if(comparador > infos[vencedores[x]].tempototal)
					{
						comparador = infos[vencedores[x]].tempototal;
						strcpy(vencedor,infos[vencedores[x]].nome);
						//DESCOBRINDO A MEDIA DE TEMPOS DO VENCEDOR
						mediavencedor = infos[vencedores[x]].mediatempos;
					}
				}
			}
	//SITUACAO NA QUAL SO TEVE 1 ATLETA QUE CORREU A MAIOR QUANTIDADE DE VOLTAS REGISTRADAS, AUTOMATICAMENTE VENCEDOR.
			else
			{
				strcpy(vencedor,infos[i].nome);
			}
		}
		
	}

//DETERMINANDO QUANTAS VOLTAS ABAIXO DO TEMPO MEDIO DO VENCEDOR CADA ATLETA TEVE.
	for(i=0; i<n; i++)
	{
	infos[i].VoltasAbaixoDaMediaDoVencedor=0;
		for(int k=0; k < infos[i].quantvoltas; k++)
		{
			if(infos[i].tempos[k] < mediavencedor)
			{
				infos[i].VoltasAbaixoDaMediaDoVencedor++;
			}
			
		}
	}
//EXIBINDO OS VALORES PARA O USUARIO, VENCEDOR, VOLTA MAIS RAPIDA E OS DADOS DE CADA ATLETA PARTICIPANTE.
	printf("O vencedor da competicao foi %s.\n\n",vencedor);
	printf("O tempo da volta mais rapida da competicao foi de %d.\n\n",voltamaisrapida);
	for(i=0; i<n; i++)
	{
		printf("O codigo do atleta [%d] e %d.\n",i+1,infos[i].codigo);
		printf("O nome do atleta [%d] foi de %s.\n",i+1,infos[i].nome);
		printf("A quantidade de voltas realizadas pelo atleta [%d] foi de %d.\n",i+1,infos[i].quantvoltas);
		printf("O tempo total do atleta [%d] foi de %.2f.\n",i+1,infos[i].tempototal);
		printf("O tempo medio das voltas do atleta [%d] foi de %.2f.\n",i+1,infos[i].mediatempos);
		printf("A quantidade de voltas com tempo abaixo da media do vencedor, do atleta [%d] foi de %d.\n",i+1,infos[i].VoltasAbaixoDaMediaDoVencedor);
		printf("\n");
	}



//LIBERANDO MEMORIA
for(i=0; i<n; i++)
{
	free(infos[i].tempos);
}

free(infos);
}




