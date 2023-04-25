#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
//variaveis//////////////////////////////////////

float soma[100];
int b,i=0,a=1,testador=0;
int j,reprovacoes[100];
int semestreatual[100];
int quantidadealunos=0;
float maiorCRE;
char nomedomaiorCRE[25];
	
/////////////////////////////////////////////////REGISTRO COM AS INFORMAÇOES GERAIS DO ALUNO
	typedef struct Aluno						 
{
	char nome[100];
	char rga[50];
	
} Aluno;
/////////////////////////////////////////////////REGISTRO COM OS RESULTADOS FINAIS DE CADA ALUNO
typedef struct result
{
	float CRE;
	char disciplinareprovada[26];
} result;
/////////////////////////////////////////////////REGISTRO COM AS INFORMAÇOES DETALHADAS DE CADA ALUNO

	typedef struct materias
{
	char nomedisciplina[25];
	int semestredisciplina;
	float notadisciplina;
	float cargahoraria;
} materias;
	
//comandos///////////////////////////////////////
	
	Aluno infos[100];
	materias disciplinas[100];
	result resultados[100];
	
	while(a==1)
	{
		printf("Para Se Candidatar A Bolsa, Insira As Informacoes Necessarias:\n\n");
			//LENDO INFORMAÇOES BASICAS
			printf("Nome da pessoa: ");
        	scanf(" %[^\n]s", infos[i].nome);
        	printf("RGA: ");
        	scanf(" %[^\n]s",infos[i].rga);
        	system("cls");
        	//LENDO AS INFORMAÇOES DE TODAS AS DISCIPLINAS CURSADAS PELO ALUNO
        	printf("Quantidade de disciplinas cursadas: ");
        	scanf(" %d",&b);
        		for(j=0;j<b;j++)
        		{
        			printf("Nome da disciplina[%d]: ",j);
        			scanf(" %[^\n]s",disciplinas[j].nomedisciplina);
        			printf("Semestre que pertence essa disciplina[%d]: ",j);
        			scanf(" %d",&disciplinas[j].semestredisciplina);
        			printf("Nota final da disciplina[%d]: ",j);
        			scanf(" %f",&disciplinas[j].notadisciplina);
        			printf("Carga horaria da disciplina[%d]: ",j);
        			scanf(" %f",&disciplinas[j].cargahoraria);
        			//RECEBENDO VALORES PARA CALCULAR O CRE DEPOIS
        			soma[i] = soma[i] + disciplinas[j].notadisciplina;
        			//ANALISANDO QUANTAS SAO AS MATERIAS QUE O ALUNO REPROVOU
        				if(disciplinas[j].notadisciplina < 5)
						{
							reprovacoes[i]++;
							
						}
					//DEFININDO O SEMESTRE ATUAL DO ALUNO E A ULTIMA MATERIA QUE REPROVOU
						if(testador < disciplinas[j].semestredisciplina)
						{
							testador = disciplinas[j].semestredisciplina;
							semestreatual[i] = testador;
							if(disciplinas[j].notadisciplina < 5)
							{
								strcpy(resultados[i].disciplinareprovada, " ");
								strcat(resultados[i].disciplinareprovada,disciplinas[j].nomedisciplina);
							}
						
							
						}
					system("cls");
					//ATENDENDO O CASO DE NAO TER NENHUMA MATERIA ABAIXO DA MEDIA
					if(reprovacoes[i]==0)
					{
						strcpy(resultados[i].disciplinareprovada, "Nenhuma materia reprovada");
					}
				}
	//CONDIÇÃO DE PARADA DO WHILE, DEFINIDA PELO USUARIO
	printf("Digite [1] para cadastrar mais um aluno:\nDigite [0] para concluir:\n ");
	scanf(" %d",&a);
	i++;
	quantidadealunos++;
	testador=0;
	system("cls");
	}
//CALCULANDO O CRE DE CADA ALUNO	
		for(int cont=0;cont<quantidadealunos;cont++)
		{
			resultados[cont].CRE = soma[cont]/b;
		}
//DESCOBRINDO O ALUNO COM O MAIOR CRE E SEU NOME
for(i=0; i < quantidadealunos; i++)
   {
   				testador=0;
				if(testador < resultados[i].CRE)
						{
							maiorCRE = resultados[i].CRE;
							strcpy(nomedomaiorCRE, " ");
							strcat(nomedomaiorCRE,infos[i].nome);
						}
   }
 //EXIBINDO OS VALORES FINAIS DE CADA ALUNO  
   for(i=0; i < quantidadealunos; i++)
   {
   		printf("\nO aluno %s de RGA %s\nCursa o semestre %d\nPossui um CRE de %.2f.\n",infos[i].nome,infos[i].rga,semestreatual[i],resultados[i].CRE);
   		printf("Um total de %d reprovacoes, sendo a ultima materia a ser reprovada : %s.\n",reprovacoes[i],resultados[i].disciplinareprovada);
   }
   	printf("\n\nO aluno %s possui o maior CRE de valor %.2f e tambem a menor quantidade de reprovacoes.",nomedomaiorCRE,maiorCRE);
}
