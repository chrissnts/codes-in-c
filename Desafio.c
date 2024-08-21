#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main ( ) 
{
    int res1, res2, res3, res4, v1, v2, soma, sub, div, mult;
    int escolha;
    int aux1 = 0, aux2 = 0, aux3 = 0, aux4 = 0;
    
    srand(time(NULL));
    printf("\n\t---+---+ Desafio da Matematica !! +---+--- ");
    printf("\n\t//--//-- Seja Bem Vindo :) --//--//\n");

    do
    {
        printf("\nEscolha uma operacao: ");
        printf("\n [1] Adicao ");
        printf("\n [2] Subtracao ");
        printf("\n [3] Divisao ");
        printf("\n [4] Multiplicacao");
        printf("\n [5] Sair\n");
        scanf("%i",&escolha);
        
          if (escolha < 1 || escolha > 5)
          { 
            printf("\nInvalido. Tente novamente !\n");
                
          }
          else if ((escolha == 1 && aux1 > 0) ||
                   (escolha == 2 && aux2 > 0) ||
                   (escolha == 3 && aux3 > 0) ||
                   (escolha == 4 && aux4 > 0)) 
          {
            printf("\nEssa operacao ja foi escolhida. Escolha outra.\n");
          }
       
          
          if (escolha == 1 && aux1 <= 0 ) 
            {
          
            aux1 ++ ;
            
            printf("\nVoce escolheu adicao!");

            v1 = rand () %251;
            v2 = rand () %251;
          
            printf("\nConta = [%i] + [%i] = ? \n", v1, v2);
            scanf ("%i", &res1);
            soma = v1 + v2;
            if (res1 == soma) 
            {
              
              printf("\nVoce acertou, parabens!! :)\n" ); 
            
            }
            else 
            {
              printf("\nResposta errada, recomece :(\n" );
                    
            }

            if (res1 == soma && res2 == sub && res3 == div &&  res4 == mult)
            {
              printf("\nParabens !!! Voce ganhou :)");
            }

            }
  

          if (escolha == 2 && aux2 <= 0) 
          {
            
            aux2 ++;
          printf("\nVoce escolheu Subtracao!");

          v1 = rand () %251;
          v2 = rand () %251;
          
          printf("\nConta = [%i] - [%i] = ? \n", v1, v2);
          scanf ("%i", &res2);
          sub = v1 - v2;
          if (res2 == sub) 
          {
              
              printf("\nVoce acertou, parabens!! :)\n" ); 
              
          }
          else 
          {
            printf("\nResposta errada, recomece :(\n");
          }

          if (res1 == soma && res2 == sub && res3 == div && res4 == mult)
          {
            printf("\nParabens !!! Voce ganhou :)");
          }

          }

          if ( escolha == 3 && aux3 <= 0)
          {  
            
            aux3 ++;
            printf("\nVoce escolheu Divisao!");

            v1 = rand () %21;
            v2 = rand () %21;
        
            printf("\nConta = [%i] / [%i] = ? \n", v1, v2);
            scanf ("%i", &res3);
            div = v1 / v2;
            if (res3 == div) 
          {
              
              printf("\nVoce acertou, parabens!! :)\n" ); 
              
          }
          else 
          {
            printf("\nResposta errada, recomece :(\n");
              
          }

          if (res1 == soma && res2 == sub && res3 == div && res4 == mult)
          {
            printf("\nParabens !!! Voce ganhou :)\n");
          }

          }
         
          if (escolha == 4 && aux4 <= 0 )
          {
            
            aux4 ++;  
          printf("\nVoce escolheu Multiplicacao!");

          v1 = rand () %13;
          v2 = rand () %13;

          printf("\nConta = [%i] x [%i] = ? \n", v1, v2);
          scanf ("%i", &res4);
          mult = v1 * v2;
          if (res4 == mult) 
          {   
            
              printf("Voce acertou, parabens!! :)\n" ); 
              
          }
          else 
          {
            printf("\nResposta errada, recomece :(\n");
              
          }

          }
          
          if (escolha == 5 )
          {  
          exit(0);
          
          }


          if (res1 == soma && res2 == sub && res3 == div && res4 == mult)
          {
            printf("\n+---+---+---+---+---+---+---+---+---+");
            printf("\nParabens !!! Voce ganhou :)\n");
            printf("+---+---+---+---+---+---+---+---+---+\n");
                  break ;
          }

          

        
          
    }
            while (res1 == soma || res2 == sub || res3 == div || res4 == mult || escolha < 1 || escolha > 5 || aux1 == 1 || aux2 == 1 || aux3 == 1 || aux4 == 1);
                  
                  
            return 0; 

}
