#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include<string.h>
#include <locale.h>
#include<stdbool.h>
#include<conio2.h>

/*************************************************************************
Descrição do Algoritmo: Algoritmo com funcoes de uma locadora de filmes.
Nome da Disciplina: Algoritmos 2
Nome Professor: Leonair Neves Sousa
Nome Aluno: Andre Parron Aranda
Turma: CV
RGA: 202011310004
Data Entrega : 12/08/2022
*************************************************************************/

//REGISTROS//
/*#######################################################################################################################*/
typedef struct Tgenero{
	int codigo;
	char genero[30];
	int flag;	
}Tgenero;
/*#######################################################################################################################*/
typedef struct Tfilme{
	int codfilme;
	char nome[30];
	int codgenero;
	int ano;
	char classificacao[30];
	float valor;
	int flag;	
}Tfilme;
/*#######################################################################################################################*/
typedef struct Tcliente{
	int codcliente;
	char nome[30],rg[11],cpf[12],email[30],celular[12],endereco[50];
	int dia,mes,ano;	
	int flag;		
}Tcliente;
/*#######################################################################################################################*/
typedef struct Tfuncionario{
	int codfuncionario;
	char nome[30],rg[11],cpf[12],email[30],celular[12];
	int dia,mes,ano;
	int diaadm,mesadm,anoadm;
	int flag;	
}Tfuncionario;
/*#######################################################################################################################*/
typedef struct Tlocacao{
	int codlocacao;
	int dialoca,mesloca,anoloca;
	int diadevo,mesdevo,anodevo;
	float valortotal;
	int juros;
	float desconto;
	int codclie,codfunc;
	char pagamento[10];
	int flag;	
}Tlocacao;
/*#######################################################################################################################*/
typedef struct Tlocfilmes{
	int codloc,codfilme;
}Tlocfilmes;
/*#######################################################################################################################*/
typedef struct Tdevolucao{
	int codloc;
	int dialoca,mesloca,anoloca;
	int diadevo,mesdevo,anodevo;
	float valororiginal,valorpago;
	int diasatraso;
	int flag;	
}Tdevolucao;


//FUNÇÕES
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


int menuprincipal()
{
	setlocale(LC_ALL,"");
	int op;
	gotoxy(35,8);
	printf("1 - Cadastro e Listar Gênero. \n");
	gotoxy(35,9);
	printf("2 - Cadastro e Listar Filmes. \n");
	gotoxy(35,10);
	printf("3 - Cadastro e Listar Clientes. \n");
	gotoxy(35,11);
	printf("4 - Cadastro e Listar Funcionário. \n");
	gotoxy(35,12);
	printf("5 - Cadastro e Listar Locação. \n");
	gotoxy(35,13);
	printf("6 - Fazer Devolução. \n");
	gotoxy(35,14);
	printf("7 - Excluir Gênero. \n");
	gotoxy(35,15);
	printf("8 - Excluir Filmes. \n");
	gotoxy(35,16);
	printf("9 - Excluir Cliente. \n");
	gotoxy(35,17);
	printf("10 - Excluir Funcionário. \n");
	gotoxy(35,18);
	printf("11 - Excluir Locação. \n");
	gotoxy(35,19);
	printf("12 - Listar Locação data específica. \n");
	gotoxy(35,20);
	printf("13 - Listar filmes em atraso. \n");
	gotoxy(35,21);
	printf("14 - Listar Devolução. \n");
	gotoxy(35,22);
	printf("15 - Sair\n");
	gotoxy(35,23);
	scanf(" %d", &op);
	
	return op;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void enfeite()
{
	
	//system("cls");
	gotoxy(35,5);
	printf("---------------------------------------- \n");
	gotoxy(35,6);
	printf("----------- MENU - LOCADORA----------- \n");
	gotoxy(35,7);
	printf("---------------------------------------- \n");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Cadastrogenero()
{
setlocale(LC_ALL,"");
	FILE *arqgenero;
	Tgenero infosgenero,listagenero;
	arqgenero = fopen("Generos.txt","ab+");
	if(arqgenero != NULL)
	{
        printf("Digite o gênero a ser inserido: \n");
        scanf(" %[^\n]s", infosgenero.genero);
        fseek(arqgenero, 0, SEEK_END);
		if((ftell(arqgenero)) <= 0)
			infosgenero.codigo = 1;
		fseek(arqgenero, 0, SEEK_SET);
		while(fread(&listagenero, sizeof(Tgenero), 1, arqgenero))
			{
			infosgenero.codigo = listagenero.codigo + 1;	
			}
        infosgenero.flag = 1;
        fwrite(&infosgenero,sizeof(Tgenero), 1, arqgenero);
        fclose(arqgenero);
        system("cls");
	}
	else
		printf("Falha na abertura do arquivo GeneroC");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void listargenero()
{
int k=0;
//system("pause");
system("cls");
setlocale(LC_ALL,"");
	FILE *arqgenero;
	Tgenero listagenero;
	arqgenero = fopen("Generos.txt","rb+");
	if(arqgenero != NULL)
		{
		while(fread(&listagenero, sizeof(Tgenero), 1, arqgenero))
			{
			if(listagenero.flag==1)
				{	
					if(k%2==0)
						{
						textbackground(1);
						printf("%d - %s\n",listagenero.codigo,listagenero.genero);	
						}
					else
						{
						textbackground(2);
						printf("%d - %s\n",listagenero.codigo,listagenero.genero);
						}	
					k++;
				}
			}
			textbackground(0);
		fclose(arqgenero);
		}
	else
		printf("Falha na abertura do arquivo GeneroL");
system("pause");
system("cls");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Cadastrofilmes()
{
setlocale(LC_ALL,"");
	FILE *arqfilmes;
	Tfilme infosfilmes;
	Tfilme listafilmes;
//criando codigo automaticamente
	arqfilmes = fopen("Filmes.txt","ab+");
	if(arqfilmes != NULL)
	{
	fseek(arqfilmes, 0, SEEK_END);
	if((ftell(arqfilmes)) <= 0)
		infosfilmes.codfilme = 1;
	fseek(arqfilmes, 0, SEEK_SET);
	while(fread(&listafilmes, sizeof(Tfilme), 1, arqfilmes))
		{
			infosfilmes.codfilme = listafilmes.codfilme + 1;
				
		}
	fclose(arqfilmes);
	}
	else
		printf("Falha na abertura do arquivo FilmesC1");
//adquirindo as informacoes	
	arqfilmes = fopen("Filmes.txt","ab+");
	if(arqfilmes != NULL)
	{
        printf("Digite o nome do filme a ser inserido: \n");
        scanf(" %[^\n]s", infosfilmes.nome);
        printf("Digite o codigo do genero deste filme: \n");
        scanf(" %d", &infosfilmes.codgenero);
        printf("Digite o ano filme: \n");
        scanf(" %d", &infosfilmes.ano);
        printf("Digite a classificação de idade deste filme: \n");
        scanf(" %d", &infosfilmes.classificacao);
        printf("Digite o valor do filme: \n");
        scanf(" %f", &infosfilmes.valor);
        infosfilmes.flag = 1;
        fwrite(&infosfilmes,sizeof(Tfilme), 1, arqfilmes);
        fclose(arqfilmes);
        system("cls");
	}
	else
		printf("Falha na abertura do arquivo FilmesC");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////

void listarfilmes()
{
	int k=0;
//system("pause");
system("cls");
setlocale(LC_ALL,"");
	FILE *arqfilme;
	Tfilme listafilme;
	arqfilme = fopen("Filmes.txt","rb+");
	if(arqfilme != NULL)
		{
		while(fread(&listafilme, sizeof(Tfilme), 1, arqfilme))
			{
			if(listafilme.flag==1)
				{
				if( k%2==0)
						{
						textbackground(1);
						printf("%d - Nome: %s\nCódigo Gênero: %d\nAno de lançamento: %d\nClassificação de Idade: %d\nValor: %.2f\n",listafilme.codfilme,listafilme.nome,listafilme.codgenero,listafilme.ano,listafilme.classificacao,listafilme.valor);
						}
					else
						{
						textbackground(2);
						printf("%d - Nome: %s\nCódigo Gênero: %d\nAno de lançamento: %d\nClassificação de Idade: %d\nValor: %.2f\n",listafilme.codfilme,listafilme.nome,listafilme.codgenero,listafilme.ano,listafilme.classificacao,listafilme.valor);
						}	
					k++;
				}
				}
			textbackground(0);
			fclose(arqfilme);
			}
	else
		printf("Falha na abertura do arquivo FilmesL");
system("pause");
system("cls");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Cadastrocliente()
{
setlocale(LC_ALL,"");
	FILE *arqcliente;
	Tcliente infoscliente;
	Tcliente listacliente;
//criando codigo automaticamente
	arqcliente = fopen("Cliente.txt","ab+");
	if(arqcliente != NULL)
	{
	fseek(arqcliente, 0, SEEK_END);
	if((ftell(arqcliente)) <= 0)
		infoscliente.codcliente = 1;
	fseek(arqcliente, 0, SEEK_SET);
	while(fread(&listacliente, sizeof(Tcliente), 1, arqcliente))
		{
			infoscliente.codcliente = listacliente.codcliente + 1;
				
		}
	fclose(arqcliente);
	}
	else
		printf("Falha na abertura do arquivo clienteC1");
//adquirindo as informacoes		
	arqcliente = fopen("Cliente.txt","ab+");
	if(arqcliente != NULL)
	{
        printf("Digite o nome do cliente: \n");
        scanf(" %[^\n]s", infoscliente.nome);
        printf("Digite o rg deste cliente: \n");
        scanf(" %[^\n]s", infoscliente.rg);
        printf("Digite o cpf deste cliente: \n");
        scanf(" %[^\n]s", infoscliente.cpf);
        printf("Digite o celular deste cliente: \n");
        scanf(" %[^\n]s", infoscliente.celular);
        printf("Digite o email deste cliente: \n");
        scanf(" %[^\n]s", infoscliente.email);
        printf("Digite o endereço deste cliente: \n");
        scanf(" %[^\n]s", infoscliente.endereco);
        printf("Digite a data de nascimento deste cliente.\n");
        printf("[DIA] = ");
        scanf(" %d", &infoscliente.dia);
        printf("[MÊS] = ");
        scanf(" %d", &infoscliente.mes);
        printf("[ANO] = ");
        scanf(" %d", &infoscliente.ano);
        infoscliente.flag = 1;
        fwrite(&infoscliente,sizeof(Tcliente), 1, arqcliente);
        fclose(arqcliente);
        system("cls");
	}
	else
		printf("Falha na abertura do arquivo clienteC");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////

void listarcliente()
{
int k=0;
//system("pause");
system("cls");
setlocale(LC_ALL,"");
	FILE *arqcliente;
	Tcliente listacliente;
	arqcliente = fopen("Cliente.txt","rb+");
	if(arqcliente != NULL)
		{
		while(fread(&listacliente, sizeof(Tcliente), 1, arqcliente))
			{
			if(listacliente.flag==1)
				{
				if( k%2==0)
						{
						textbackground(1);
						printf("%d - Nome: %s\nRG: %s\nCPF: %s\nEmail: %s\nCelular: %s\nEndereço: %s\nData de nascimento: %d/%d/%d\n",listacliente.codcliente,listacliente.nome,listacliente.rg,listacliente.cpf,listacliente.email,listacliente.celular,listacliente.endereco,listacliente.dia,listacliente.mes,listacliente.ano);
						}
					else
						{
						textbackground(2);
						printf("%d - Nome: %s\nRG: %s\nCPF: %s\nEmail: %s\nCelular: %s\nEndereço: %s\nData de nascimento: %d/%d/%d\n",listacliente.codcliente,listacliente.nome,listacliente.rg,listacliente.cpf,listacliente.email,listacliente.celular,listacliente.endereco,listacliente.dia,listacliente.mes,listacliente.ano);
						}	
					k++;
				}
			textbackground(0);
			}
		fclose(arqcliente);
		}
	else
		printf("Falha na abertura do arquivo clienteL");
system("pause");
system("cls");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Cadastrofuncionario()
{
setlocale(LC_ALL,"");
	FILE *arqFuncionario;
	Tfuncionario infosfuncionario;
	Tfuncionario listafuncionario;
//criando codigo automaticamente
	arqFuncionario = fopen("Funcionarios.txt","ab+");
	if(arqFuncionario != NULL)
	{
	fseek(arqFuncionario, 0, SEEK_END);
	if((ftell(arqFuncionario)) <= 0)
		infosfuncionario.codfuncionario = 1;
	fseek(arqFuncionario, 0, SEEK_SET);
	while(fread(&listafuncionario, sizeof(Tfuncionario), 1, arqFuncionario))
		{
			infosfuncionario.codfuncionario = listafuncionario.codfuncionario + 1;
				
		}
	fclose(arqFuncionario);
	}
	else
		printf("Falha na abertura do arquivo funcionarioC1");
//adquirindo as informacoes		
	arqFuncionario = fopen("Funcionarios.txt","ab+");
	if(arqFuncionario != NULL)
	{
        printf("Digite o nome do funcionario: \n");
        scanf(" %[^\n]s", infosfuncionario.nome);
        printf("Digite o rg deste funcionario: \n");
        scanf(" %[^\n]s", infosfuncionario.rg);
        printf("Digite o cpf deste funcionario: \n");
        scanf(" %[^\n]s", infosfuncionario.cpf);
        printf("Digite o celular deste funcionario: \n");
        scanf(" %[^\n]s", infosfuncionario.celular);
        printf("Digite o email deste funcionario: \n");
        scanf(" %[^\n]s", infosfuncionario.email);
        printf("Digite a data de nascimento deste funcionario.\n");
        printf("[DIA] = ");
        scanf(" %d", &infosfuncionario.dia);
        printf("[MÊS] = ");
        scanf(" %d", &infosfuncionario.mes);
        printf("[ANO] = ");
        scanf(" %d", &infosfuncionario.ano);
        printf("Digite a data de admissão deste funcionario. \n");
        printf("[DIA] = ");
        scanf(" %d", &infosfuncionario.diaadm);
        printf("[MÊS] = ");
        scanf(" %d", &infosfuncionario.mesadm);
        printf("[ANO] = ");
        scanf(" %d", &infosfuncionario.anoadm);
        infosfuncionario.flag = 1;
        fwrite(&infosfuncionario,sizeof(Tfuncionario), 1, arqFuncionario);
        fclose(arqFuncionario);
        system("cls");
	}
	else
		printf("Falha na abertura do arquivo funcionarioC");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////

void listarfuncionario()
{
int k=0;
//system("pause");
system("cls");
setlocale(LC_ALL,"");
	FILE *arqFuncionario;
	Tfuncionario listafuncionario;
	arqFuncionario = fopen("Funcionarios.txt","rb+");
	if(arqFuncionario != NULL)
		{
		while(fread(&listafuncionario, sizeof(Tfuncionario), 1, arqFuncionario))
			{
			if(listafuncionario.flag==1)
				{
				if( k%2==0)
						{
						textbackground(1);
						printf("%d - Nome: %s\nRG: %s\nCPF: %s\nEmail: %s\nCelular: %s\nData de nascimento: %d/%d/%d\nData de Admissão: %d/%d/%d\n",listafuncionario.codfuncionario,listafuncionario.nome,listafuncionario.rg,listafuncionario.cpf,listafuncionario.email,listafuncionario.celular,listafuncionario.dia,listafuncionario.mes,listafuncionario.ano,listafuncionario.diaadm,listafuncionario.mesadm,listafuncionario.anoadm);
						}
					else
						{
						textbackground(2);
						printf("%d - Nome: %s\nRG: %s\nCPF: %s\nEmail: %s\nCelular: %s\nData de nascimento: %d/%d/%d\nData de Admissão: %d/%d/%d\n",listafuncionario.codfuncionario,listafuncionario.nome,listafuncionario.rg,listafuncionario.cpf,listafuncionario.email,listafuncionario.celular,listafuncionario.dia,listafuncionario.mes,listafuncionario.ano,listafuncionario.diaadm,listafuncionario.mesadm,listafuncionario.anoadm);
						}	
					k++;
				}
			textbackground(0);
			}
		fclose(arqFuncionario);
		}
	else
		printf("Falha na abertura do arquivo FuncionariosL");
system("pause");
system("cls");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Cadastrolocacao()
{
setlocale(LC_ALL,"");
	FILE *arqLocacao;
	Tlocacao infoslocacao;
	Tlocacao listalocacao;
	int auxPagamento;
//criando codigo automaticamente
	arqLocacao = fopen("Locações.txt","ab+");
	if(arqLocacao != NULL)
	{
	fseek(arqLocacao, 0, SEEK_END);
	if((ftell(arqLocacao)) <= 0)
		infoslocacao.codlocacao = 1;
	fseek(arqLocacao, 0, SEEK_SET);
	while(fread(&listalocacao, sizeof(Tlocacao), 1, arqLocacao))
		{
			infoslocacao.codlocacao = listalocacao.codlocacao + 1;
				
		}
	fclose(arqLocacao);
	}
	else
		printf("Falha na abertura do arquivo locacaoC1");
//adquirindo as informacoes		
	arqLocacao = fopen("Locações.txt","ab+");
	if(arqLocacao != NULL)
	{
	//informações simples a serem lidas
        printf("Digite o código do Cliente: \n");
        scanf(" %d", &infoslocacao.codclie);
        printf("Digite o código do Funcionário: \n");
        scanf(" %d", &infoslocacao.codfunc);
        printf("Digite a data que foi feita a locacao.\n");
        printf("[DIA] = ");
        scanf(" %d", &infoslocacao.dialoca);
        printf("[MÊS] = ");
        scanf(" %d", &infoslocacao.mesloca);
        printf("[ANO] = ");
        scanf(" %d", &infoslocacao.anoloca);
        printf("Digite a data de devolução desta locacao. \n");
        printf("[DIA] = ");
        scanf(" %d", &infoslocacao.diadevo);
        printf("[MÊS] = ");
        scanf(" %d", &infoslocacao.mesdevo);
        printf("[ANO] = ");
        scanf(" %d", &infoslocacao.anodevo);
        printf("Qual será o tipo de pagamento?\n1 = A vista.\n2 = A prazo.\n");
        scanf(" %d", &auxPagamento);
    	if(auxPagamento == 1)
    		{
    		strcpy(infoslocacao.pagamento,"A vista");
    		infoslocacao.desconto = 5;
    		infoslocacao.juros = 0;
			}
		else if(auxPagamento == 2)
    		{
    		strcpy(infoslocacao.pagamento,"A prazo");
    		infoslocacao.desconto = 0;
    		infoslocacao.juros = 0;
			}
        infoslocacao.flag = 1;
        infoslocacao.valortotal=0;
     //informações mais complexas a serem calculadas
     //valor total da locação
    FILE *arqfilmes;
	Tfilme infosfilmes;
	Tfilme listafilmes;
	int aux,chaveaux,x=0;
	bool fim=false;
	   arqfilmes = fopen("Filmes.txt","rb+");
	if(arqfilmes != NULL)
	{
	while(!fim)
		{
		printf("Digite o código do filme: \n");
		scanf(" %d", &aux);
		//guardando informacoes dos filmes locados
		FILE *arqlocfilmes;
		Tlocfilmes infoslocfilmes;
		arqlocfilmes = fopen("FilmesLocados.txt","ab+");
		if(arqlocfilmes != NULL)
			{
			infoslocfilmes.codfilme = aux;
			infoslocfilmes.codloc = infoslocacao.codlocacao;
				fwrite(&infoslocfilmes,sizeof(Tlocfilmes), 1, arqlocfilmes);
				fclose(arqlocfilmes);
			}
		else
			printf("Falha na abertura do arquivo FilmesLocadosC");
		//de volta a calcular o valor total da locacao
		fseek(arqfilmes, 0, SEEK_SET);
        while(fread(&listafilmes, sizeof(Tfilme), 1, arqfilmes))
        	{
        	if(aux == listafilmes.codfilme)
        		{
        		infoslocacao.valortotal += listafilmes.valor;
        		//se filme foi locado ele deve sair da lista de filmes pois nao esta mais disponivel
        		listafilmes.flag=0;
        		fseek(arqfilmes, x*sizeof(Tfilme), SEEK_SET);
        		fwrite(&listafilmes,sizeof(Tfilme), 1, arqfilmes);
        		break;
				}
			x++;
			}
		printf("Deseja locar mais algum filme?\n[1]= Sim\n[2]=Nao\n");
		scanf(" %d",&chaveaux);
			if(chaveaux == 2)
			{
				fim = true;	
			}	
		}	
	fclose(arqfilmes);
	}
	else
		printf("Falha na abertura do arquivo FilmesLocacao.");
        
        fwrite(&infoslocacao,sizeof(Tlocacao), 1, arqLocacao);
        fclose(arqLocacao);
        system("cls");
	}
	else
		printf("Falha na abertura do arquivo LocacaoC");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////

void listarlocacao()
{
int k=0;
//system("pause");
system("cls");
setlocale(LC_ALL,"");
	FILE *arqlocacao;
	FILE *arqcliente;
	Tlocacao listalocacao;
	Tcliente listacliente;
	arqlocacao = fopen("Locações.txt","rb+");
	if(arqlocacao != NULL)
		{
		arqcliente = fopen("Cliente.txt","rb+");
		if(arqcliente != NULL)
			{
			while(fread(&listalocacao, sizeof(Tlocacao), 1, arqlocacao))
				{
				fseek(arqcliente, 0, SEEK_SET);
				while(fread(&listacliente, sizeof(Tcliente), 1, arqcliente))
					{
					if(listalocacao.codclie==listacliente.codcliente)
						{
						if(listalocacao.flag==1)
							{
							if( k%2==0)
								{
								textbackground(1);
								printf("Locação %d - Data da Locação: %d/%d/%d\nData de Devolução: %d/%d/%d\nValor Total: %.2f\nJuros: %d\nDesconto: %.2f\nCódigo Cliente: %d\nCódigo Funcionário: %d\nForma de Pagamento: %s\n",listalocacao.codlocacao,listalocacao.dialoca,listalocacao.mesloca,listalocacao.anoloca,listalocacao.diadevo,listalocacao.mesdevo,listalocacao.anodevo,listalocacao.valortotal,listalocacao.juros,listalocacao.desconto,listalocacao.codclie,listalocacao.codfunc,listalocacao.pagamento);
								}
							else
								{
								textbackground(2);
								printf("Locação %d - Data da Locação: %d/%d/%d\nData de Devolução: %d/%d/%d\nValor Total: %.2f\nJuros: %d\nDesconto: %.2f\nCódigo Cliente: %d\nCódigo Funcionário: %d\nForma de Pagamento: %s\n",listalocacao.codlocacao,listalocacao.dialoca,listalocacao.mesloca,listalocacao.anoloca,listalocacao.diadevo,listalocacao.mesdevo,listalocacao.anodevo,listalocacao.valortotal,listalocacao.juros,listalocacao.desconto,listalocacao.codclie,listalocacao.codfunc,listalocacao.pagamento);
								}	
							k++;
							}
							textbackground(0);
						}
					}
				}
			fclose(arqcliente);
			}
		else
			printf("Falha na abertura do arquivo ClientesL");
		fclose(arqlocacao);
		}
	else
		printf("Falha na abertura do arquivo LocaçõesL");
system("pause");
system("cls");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void devolucao()
{
system("cls");
setlocale(LC_ALL,"");
	FILE *arqlocacao,*arqdevolucao;
	int auxLoc,x=0;
	Tlocacao listalocacao;
	Tdevolucao infosdevolucao;
	arqlocacao = fopen("Locações.txt","rb+");
	if(arqlocacao != NULL)
		{
		printf("Digite o codigo da sua Locação: \n");
		scanf(" %d",&auxLoc);
		arqdevolucao = fopen("Devoluções.txt","ab+");
		if(arqlocacao != NULL)
		{
		
		while(fread(&listalocacao, sizeof(Tlocacao), 1, arqlocacao))
			{	
			if(listalocacao.codlocacao == auxLoc)
				{
				listalocacao.flag=0;
				fseek(arqlocacao, x*sizeof(Tlocacao), SEEK_SET);
				fwrite(&listalocacao,sizeof(Tlocacao), 1, arqlocacao);
				printf("Devolução feita com sucesso.\n");
				//registrando devolucoes
				infosdevolucao.codloc = listalocacao.codlocacao;
				infosdevolucao.dialoca = listalocacao.dialoca;
				infosdevolucao.mesloca = listalocacao.mesloca;
				infosdevolucao.anoloca = listalocacao.anoloca;
				infosdevolucao.diadevo = listalocacao.diadevo;
				infosdevolucao.mesdevo = listalocacao.mesdevo;
				infosdevolucao.anodevo = listalocacao.anodevo;
				infosdevolucao.diasatraso = 0;
				infosdevolucao.valororiginal = listalocacao.valortotal;
				infosdevolucao.valorpago = listalocacao.valortotal;
				infosdevolucao.flag=1;
				fwrite(&infosdevolucao,sizeof(Tdevolucao), 1, arqdevolucao);
				break;
				}
			x++;
			}
		fclose(arqdevolucao);
		}
		else
			printf("Falha na abertura do arquivo DevolucoesL");
		fclose(arqlocacao);
		}
	else
		printf("Falha na abertura do arquivo locacoesL");
system("pause");
system("cls");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void excluirgenero()
{
system("cls");
setlocale(LC_ALL,"");
	FILE *arqgenero;
	int auxGen,x=0;
	Tgenero listagenero;
	arqgenero = fopen("Generos.txt","rb+");
	if(arqgenero != NULL)
		{
		printf("Digite o codigo do Gênero a ser excluído: \n");
		scanf(" %d",&auxGen);		
		while(fread(&listagenero, sizeof(Tgenero), 1, arqgenero))
			{
			
			if(listagenero.codigo == auxGen)
				{
				listagenero.flag=0;
				fseek(arqgenero, x*sizeof(Tgenero), SEEK_SET);
				fwrite(&listagenero,sizeof(Tgenero), 1, arqgenero);
				printf("Exclusão feita com sucesso.\n");
				break;
				}
			x++;
			}
		fclose(arqgenero);
		}
	else
		printf("Falha na abertura do arquivo generosE");
system("pause");
system("cls");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void excluirfilmes()
{
system("cls");
setlocale(LC_ALL,"");
	FILE *arqfilmes;
	int auxfilme,x=0;
	Tfilme listafilmes;
	arqfilmes = fopen("Filmes.txt","rb+");
	if(arqfilmes != NULL)
		{
		printf("Digite o codigo do Filme a ser excluído: \n");
		scanf(" %d",&auxfilme);		
		while(fread(&listafilmes, sizeof(Tfilme), 1, arqfilmes))
			{
			
			if(listafilmes.codfilme == auxfilme)
				{
				listafilmes.flag=0;
				fseek(arqfilmes, x*sizeof(Tfilme), SEEK_SET);
				fwrite(&listafilmes,sizeof(Tfilme), 1, arqfilmes);
				printf("Exclusão feita com sucesso.\n");
				break;
				}
			x++;
			}
		fclose(arqfilmes);
		}
	else
		printf("Falha na abertura do arquivo filmesE");
system("pause");
system("cls");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void excluircliente()
{
system("cls");
setlocale(LC_ALL,"");
	FILE *arqcliente;
	int auxcliente,x=0;
	Tcliente listacliente;
	arqcliente = fopen("Cliente.txt","rb+");
	if(arqcliente != NULL)
		{
		printf("Digite o codigo do Cliente a ser excluído: \n");
		scanf(" %d",&auxcliente);		
		while(fread(&listacliente, sizeof(Tcliente), 1, arqcliente))
			{
			
			if(listacliente.codcliente == auxcliente)
				{
				listacliente.flag=0;
				fseek(arqcliente, x*sizeof(Tcliente), SEEK_SET);
				fwrite(&listacliente,sizeof(Tcliente), 1, arqcliente);
				printf("Exclusão feita com sucesso.\n");
				break;
				}
			x++;
			}
		fclose(arqcliente);
		}
	else
		printf("Falha na abertura do arquivo ClientesE");
system("pause");
system("cls");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void excluirfuncionario()
{
system("cls");
setlocale(LC_ALL,"");
	FILE *arqfuncionario;
	int auxfuncionario,x=0;
	Tfuncionario listafuncionario;
	arqfuncionario = fopen("Funcionarios.txt","rb+");
	if(arqfuncionario != NULL)
		{
		printf("Digite o codigo do Funcionario a ser excluído: \n");
		scanf(" %d",&auxfuncionario);		
		while(fread(&listafuncionario, sizeof(Tfuncionario), 1, arqfuncionario))
			{
			
			if(listafuncionario.codfuncionario == auxfuncionario)
				{
				listafuncionario.flag=0;
				fseek(arqfuncionario, x*sizeof(Tfuncionario), SEEK_SET);
				fwrite(&listafuncionario,sizeof(Tfuncionario), 1, arqfuncionario);
				printf("Exclusão feita com sucesso.\n");
				break;
				}
			x++;
			}
		fclose(arqfuncionario);
		}
	else
		printf("Falha na abertura do arquivo funcionariosE");
system("pause");
system("cls");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void excluirlocacao()
{
system("cls");
setlocale(LC_ALL,"");
	FILE *arqlocacao;
	int auxlocacao,x=0;
	Tlocacao listalocacao;
	arqlocacao = fopen("Locações.txt","rb+");
	if(arqlocacao != NULL)
		{
		printf("Digite o codigo do locacao a ser excluído: \n");
		scanf(" %d",&auxlocacao);		
		while(fread(&listalocacao, sizeof(Tlocacao), 1, arqlocacao))
			{
			
			if(listalocacao.codlocacao == auxlocacao)
				{
				listalocacao.flag=0;
				fseek(arqlocacao, x*sizeof(Tlocacao), SEEK_SET);
				fwrite(&listalocacao,sizeof(Tlocacao), 1, arqlocacao);
				printf("Exclusão feita com sucesso.\n");
				break;
				}
			x++;
			}
		fclose(arqlocacao);
		}
	else
		printf("Falha na abertura do arquivo locacaosE");
system("pause");
system("cls");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void listarlocacaoespecifica()
{
int k=0;
//system("pause");
system("cls");
setlocale(LC_ALL,"");
	FILE *arqlocacao;
	FILE *arqcliente;
	Tlocacao listalocacao;
	Tcliente listacliente;
	int d,m,a;
	arqlocacao = fopen("Locações.txt","rb+");
	if(arqlocacao != NULL)
		{
		printf("Digite a data da locação que deseja procurar.\n");
        printf("[DIA] = ");
        scanf(" %d", &d);
        printf("[MÊS] = ");
        scanf(" %d", &m);
        printf("[ANO] = ");
        scanf(" %d", &a);
		arqcliente = fopen("Cliente.txt","rb+");
		if(arqcliente != NULL)
			{
			while(fread(&listalocacao, sizeof(Tlocacao), 1, arqlocacao))
				{
				fseek(arqcliente, 0, SEEK_SET);
				while(fread(&listacliente, sizeof(Tcliente), 1, arqcliente))
					{
					if((listalocacao.codclie==listacliente.codcliente)&&(d == listalocacao.dialoca)&&(m == listalocacao.mesloca)&&(a == listalocacao.anoloca))
						{
						if( k%2==0)
							{
							textbackground(1);
							printf("Locação %d - Data da Locação: %d/%d/%d\nData de Devolução: %d/%d/%d\nValor Total: %.2f\nJuros: %d\nDesconto: %.2f\nCódigo Cliente: %d\nCódigo Funcionário: %d\nForma de Pagamento: %s\n",listalocacao.codlocacao,listalocacao.dialoca,listalocacao.mesloca,listalocacao.anoloca,listalocacao.diadevo,listalocacao.mesdevo,listalocacao.anodevo,listalocacao.valortotal,listalocacao.juros,listalocacao.desconto,listalocacao.codclie,listalocacao.codfunc,listalocacao.pagamento);
							}
						else
							{
							textbackground(2);
							printf("Locação %d - Data da Locação: %d/%d/%d\nData de Devolução: %d/%d/%d\nValor Total: %.2f\nJuros: %d\nDesconto: %.2f\nCódigo Cliente: %d\nCódigo Funcionário: %d\nForma de Pagamento: %s\n",listalocacao.codlocacao,listalocacao.dialoca,listalocacao.mesloca,listalocacao.anoloca,listalocacao.diadevo,listalocacao.mesdevo,listalocacao.anodevo,listalocacao.valortotal,listalocacao.juros,listalocacao.desconto,listalocacao.codclie,listalocacao.codfunc,listalocacao.pagamento);
							}	
						k++;
						}
						textbackground(0);
					}
				}
			fclose(arqcliente);
			}
		else
			printf("Falha na abertura do arquivo ClientesL");
		fclose(arqlocacao);
		}
	else
		printf("Falha na abertura do arquivo LocaçõesL");
system("pause");
system("cls");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void listardevolucao()
{
int k=0;
//system("pause");
system("cls");
setlocale(LC_ALL,"");
	FILE *arqdevolucao;
	Tdevolucao listadevolucao;
	int x=1;
	arqdevolucao = fopen("Devoluções.txt","rb+");
	if(arqdevolucao != NULL)
		{
		while(fread(&listadevolucao, sizeof(Tdevolucao), 1, arqdevolucao))
			{
			if(listadevolucao.flag==1)
				{
				if( k%2==0)
					{
					textbackground(1);
					printf("Devolução %d - Data de locação = %d/%d/%d\nData de devolução = %d/%d/%d\nValor Original = %.2f\nValor Pago = %.2f\nCódigo Locação: %d\nDias de Atraso: %d\n",x,listadevolucao.dialoca,listadevolucao.mesloca,listadevolucao.anoloca,listadevolucao.diadevo,listadevolucao.mesdevo,listadevolucao.anodevo,listadevolucao.valororiginal,listadevolucao.valorpago,listadevolucao.codloc,listadevolucao.diasatraso);
					}
				else
					{
					textbackground(2);
					printf("Devolução %d - Data de locação = %d/%d/%d\nData de devolução = %d/%d/%d\nValor Original = %.2f\nValor Pago = %.2f\nCódigo Locação: %d\nDias de Atraso: %d\n",x,listadevolucao.dialoca,listadevolucao.mesloca,listadevolucao.anoloca,listadevolucao.diadevo,listadevolucao.mesdevo,listadevolucao.anodevo,listadevolucao.valororiginal,listadevolucao.valorpago,listadevolucao.codloc,listadevolucao.diasatraso);
					}	
					k++;
				}
				textbackground(0);
			x++;
			}
		fclose(arqdevolucao);
		}
	else
		printf("Falha na abertura do arquivo devolucaosL");
system("pause");
system("cls");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void listaratraso()
{
int k=0;
//system("pause");
system("cls");
setlocale(LC_ALL,"");
	FILE *arqfilmesatrasados,*arqfilmeslocados;
	Tlocacao listafilmesatrasados;
	Tlocfilmes listafilmeslocados;
	int d,m,a;
	arqfilmesatrasados = fopen("Locações.txt","rb+");
	if(arqfilmesatrasados != NULL)
		{
		arqfilmeslocados = fopen("FilmesLocados.txt","rb+");
		if(arqfilmesatrasados != NULL)
			{	
			printf("Digite a data de hoje.\n");
	        printf("[DIA] = ");
	        scanf(" %d", &d);
	        printf("[MÊS] = ");
	        scanf(" %d", &m);
	        printf("[ANO] = ");
	        scanf(" %d", &a);
			while(fread(&listafilmesatrasados, sizeof(Tlocacao), 1, arqfilmesatrasados))
				{
				
				if(listafilmesatrasados.diadevo<d)
					{
					if((listafilmesatrasados.mesdevo<=m)&&(listafilmesatrasados.anodevo<=a))
						{
						while(fread(&listafilmeslocados, sizeof(Tlocfilmes), 1, arqfilmeslocados))
							{
							if(listafilmesatrasados.codlocacao == listafilmeslocados.codloc)
								{
								if(k%2==0)
									{
									textbackground(1);
									printf("Filme de codigo [%d] está atrasado.\n",listafilmeslocados.codfilme);	
									}
								else
									{
									textbackground(2);
									printf("Filme de codigo [%d] está atrasado.\n",listafilmeslocados.codfilme);
									}	
								k++;
								}
							}
						}
					}
				}
			textbackground(0);
			fclose(arqfilmeslocados);
			}
			else
				printf("Falha na abertura do arquivo FilmesLocadosL");
		fclose(arqfilmesatrasados);
		}
	else
		printf("Falha na abertura do arquivo LocaçõesL");
system("pause");
system("cls");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////



//FUNCAO PRINCIPAL
int main(int argc, char const *argv[])
{
	int resp,x,y,z,k;
	bool Fim = false;
	
    while (!Fim)
    {
    	enfeite();
    	resp = menuprincipal();
        printf(" \n");
        switch(resp)
        {
        
        case 1:
        	system("cls");
        	printf("1 - Cadastrar \n");
        	printf("2 - Listar \n");
        	scanf(" %d",&x);
        	if(x==1)
        	Cadastrogenero();
        	else if(x==2)
        	listargenero();
        	break;
       
		case 2:
			system("cls");
			printf("1 - Cadastrar \n");
        	printf("2 - Listar \n");
        	scanf(" %d",&x);
        	if(x==1)
        	Cadastrofilmes();
        	else if(x==2)
        	listarfilmes();
        	break;
        	
		case 3:
			system("cls");
			printf("1 - Cadastrar \n");
        	printf("2 - Listar \n");
        	scanf(" %d",&x);
        	if(x==1)
        	Cadastrocliente();
        	else if(x==2)
        	listarcliente();
        	break;
		case 4:
			system("cls");
			printf("1 - Cadastrar \n");
        	printf("2 - Listar \n");
        	scanf(" %d",&x);
        	if(x==1)
        	Cadastrofuncionario();
        	else if(x==2)
        	listarfuncionario();
        	break;
        case 5:
        	system("cls");
        	printf("1 - Cadastrar \n");
        	printf("2 - Listar \n");
        	scanf(" %d",&x);
        	if(x==1)
        	Cadastrolocacao();
        	else if(x==2)
        	listarlocacao();
        	break;
        case 6:
        	devolucao();
        	break;
        case 7:
        	excluirgenero();
        	break;
        case 8:
        	excluirfilmes();
        	break;
        case 9:
        	excluircliente();
        	break;
        case 10:
        	excluirfuncionario();
        	break;
		case 11:
			excluirlocacao();
        	break;
        case 12:
        	listarlocacaoespecifica();
        	break;
        case 13:
        	listaratraso();
        	break;
        case 14:
        	listardevolucao();
        	break;
        case 15:
        	system("cls");
        	printf("Programa Finalizado.\n");
           	system("pause");
        	Fim=true;
        	break;
   		}
    }
return 0;
}
