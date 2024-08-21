#include <stdio.h> 
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main ( )
{
  int num, numaleatorio, cont = 0;
  srand(time(NULL));

  numaleatorio = rand()%11;

  //Tela Inicial
  printf("\n-*-*-FIND OUT THE RANDOM NUMBER-*-*-\n");
  printf("\nEnter a number from 0 to 10\n");
  do
  {     scanf("%i", &num);
    //Mostrar as chances
        if (cont == 0 && num != numaleatorio){
          printf ("You have 5 chances.\n");
        }
        if (cont == 1 && num != numaleatorio ){
          printf ("You have 4 chances.\n");
        }
        if (cont == 2 && num != numaleatorio ){
          printf ("You have 3 chances.\n");
        }
        if (cont == 3 && num != numaleatorio ){
          printf ("You have 2 chances.\n");
        }
        if (cont == 4 && num != numaleatorio ){
          printf ("You have 1 chances.\n");
        }
        if (cont == 5 && num != numaleatorio ){
          printf ("You lost. :(\n");
          break;
        }

     //Declarar se esta ganho ou repetir
        if ( num == numaleatorio){
          printf("Congratulations !!. You managed to find the number. :)\n");
        }
        else{
          printf("\nIt's not that, try again :( \n");
          cont ++;
        }
        if ( num < 0 || num > 10 ){
          printf("\nThis number is invalid.\n");
        }
  }
     while ( num != numaleatorio);
  


 return 0;

}
