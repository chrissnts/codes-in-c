#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
  int num_oculto = 0, num_pap, palpite = -1, numaleatorio, linf = 1, lsup = 99;
  srand(time(NULL));

  num_oculto = (rand() % 99) + 1;

  for (num_pap = 0; palpite != num_oculto; num_pap++)
  {
    printf("Digite o palpite %do entre [%d e %d] :", num_pap + 1, linf,lsup);
    scanf("%d", &palpite);

    if (palpite < num_oculto)
    {
      linf = (palpite < 1) ? 1 : palpite + 1;
    }
    else if (palpite > num_oculto)
    {
      lsup = (palpite > 99) ? 99 : palpite - 1;
    }
  }
  printf("Voce acertou com [%d] tentativa (s) - PARABENS!!", num_pap);
}
