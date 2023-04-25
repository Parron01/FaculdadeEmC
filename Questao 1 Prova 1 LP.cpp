#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <stdbool.h>

int main()
{
//VARIAVEIS
	
float salario;
int x,y;
float imposto=0;
	
//COMANDOS	
	
		printf("Insira o valor do salario:\n");
		scanf(" %f",&salario);
	
	if(salario <= 2000.00)
	{
		imposto=0.00;
	}
	else if((salario > 2000.00)&&(salario <= 3000.00 ))
	{
		salario = salario - 2000;
		imposto = salario * 0.08;
	}
	else if((salario>3000.00)&&(salario<=4500.00))
	{
		x = salario;
		x = x - 3000;
		imposto = x * 0.18;
		x = salario - 2000 - x;
		imposto = imposto + x*0.08;
	}
	else if(salario > 4500.00)
	{
		x = salario;
		x = x - 4500.00;
		imposto = x*0.28;
		y = salario - 3000 - x;
		imposto = imposto + y*0.18;
		x = salario - 2000 - x - y;
		imposto = imposto + x*0.08;
	}
	
	printf("O imposto sobre o salario informado e de R$%.2f Rombus",imposto);
	
	
	
	return 0;
}
