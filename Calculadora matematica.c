#include <stdio.h> 
#include <math.h>
#include <stdlib.h>
#include <time.h>
int main ( ) {

double v1, v2, op1, op2, op3, op4, op5, op52;
int op;
//Tela Inicial
printf("\n\t+--- Bem Vindo!!! :) ---+\t\n");
printf("\n[ Calculadora Matematica ] \n");
printf ("+----+----+----+----+----+\n ");
printf("Pressione ENTER para continuar...\n ");
getchar();
//Pedir valor
printf(" Digite o primeiro valor: ");
scanf(" %lf", &v1);

printf(" Digite o segundo valor: ");
scanf(" %lf", &v2);
//Escolha a operação que o usuario quer 
while (1)
{ printf("\nEscolha uma operacao:\n ");
  printf(" [1] Soma\n");
  printf("  [2] Subtracao\n");
  printf("  [3] Multiplicacao\n");
  printf("  [4] Divisao\n");
  printf("  [5] Raiz Quadrada\n");
  printf("  [0] Sair\n");
  scanf("%i", &op);

  op1 = v1 + v2 ;
  op2 = v1 - v2 ;
  op3 = v1 * v2 ;
  op4 = v1 / v2 ;
  op5 = sqrt (v1) ;
  op52 = sqrt (v2) ;

//Fazer a operação
  if ( op == 1) 
  { printf ("+----+----+----+----+----+\n ");
    printf (" Soma = %.2lf\n ", op1);
    printf ("+----+----+----+----+----+");
  } 

  if ( op == 2 )
  {
    printf ("+----+----+----+----+----+\n ");
    printf (" Subtracao = %.2lf\n ", op2);
    printf ("+----+----+----+----+----+");
  } 
  if ( op == 3 ) 
  {
    printf ("+----+----+----+----+----+\n ");
    printf (" Multiplicao = %.2lf\n", op3);
    printf ("+----+----+----+----+----+");
  } 
  if  ( op == 4 )
  {
    printf ("+----+----+----+----+----+\n ");
    printf (" Divisao = %.2lf\n ", op4);
    printf ("+----+----+----+----+----+");
  } 
   if  ( op == 5 )
  {
    printf ("+----+----+----+----+----+\n ");
    printf ("Raiz Valor 1 = %.2lf \n Raiz Valor 2 = %.2lf\n ", op5, op52);
    printf ("+----+----+----+----+----+");
  } 
  if  ( op == 0 )
  { 
    printf ("+----+----+----+----+----+\n ");
    printf ("Ate mais!! :) \n ");
    printf ("+----+----+----+----+----+");
                break;
  } 


}
     
return 0;

}
