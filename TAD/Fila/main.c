#include <stdio.h>
#include "fila.h"

int main()
{

  int Bread = 0, Jane = 1, Bill = 2, Kant = 3, Vitor = 4, Joao = 5;
  char *nomes[] = {"Bread", "Jane", "Bill", "Kant", "Vitor", "Joao"};

  Fila *minha_fila = Queue();

  enqueue(minha_fila, Bread);
  enqueue(minha_fila, Jane);
  enqueue(minha_fila, Bill);
  enqueue(minha_fila, Kant);
  enqueue(minha_fila, Vitor);
  enqueue(minha_fila, Joao);

  while (1)
  {
    int temp = front(minha_fila);

    dequeue(minha_fila);

    printf("%s\n", nomes[temp]);
    getchar();

    enqueue(minha_fila, temp);
  }

  return 0;
}