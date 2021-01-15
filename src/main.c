#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

  FILE *in = argc > 1 ? fopen(argv[1], "r") : NULL;
  ur_t ur;
  int i;
  double *x;
  if (in == NULL) {
    fprintf(stderr, "Nie udało się otworzyć podanego pliku\n");
    return -1;
  }

  ur = read(in);
  
  if(ur==NULL){
    fprintf(stderr, "Błedy w podanym pliku\n");
    return -1;
  }
  
  x = malloc(sizeof(double) * ur->n);
  solve(ur, x);
  printf("Rozwiązania podanego układu równań:\n");
  for (i = 0; i < ur->n; i++)
    printf("x%d = %lf\n", i+1, x[i]);

  return 0;
}