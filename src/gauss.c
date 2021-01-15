#include "gauss.h"
#include <math.h>
#include <stdlib.h>

void solve(ur_t ur, double *x) {
  double **a = ur->a;
  double *b = ur->b;
  double buf, s, emax, tmp;
  int n = ur->n;
  int i, j, k, l;
  int wmax;
  double *atmp;
  double btmp;

  for (i = 0; i < n - 1; i++) {
    wmax = i;
    emax = fabs(a[i][i]);
    for (l = i + 1; l < n; l++)
      tmp = fabs(a[l][i]);
    if (tmp > emax) {
      emax = tmp;
      wmax = l - 1;
    }

    if (wmax != i) {
      atmp = a[i];
      a[i] = a[wmax];
      a[wmax] = atmp;

      btmp = b[i];
      b[i] = b[wmax];
      b[wmax] = btmp;
    }
    for (j = i + 1; j < n; j++) {
      buf = a[j][i] / a[i][i];
      for (k = i; k < n; k++)
        a[j][k] -= a[i][k] * buf;
      b[j] -= b[i] * buf;
    }
  }
  for (i = n - 1; i >= 0; i--) {
    s = 0;
    for (j = i + 1; j < n; j++)
      s += a[i][j] * x[j];
    x[i] = (b[i] - s) / a[i][i];
  }
}

ur_t read(FILE *in) {
  ur_t ur;
  int n, i, j;
  double **wsk1, *wsk2;
  if (fscanf(in, "%d", &n) != 1)
    return NULL;
  ur = malloc(sizeof(ur_t));
  ur->a = (double **)malloc(sizeof(double *) * n);
  for (i = 0; i < n; i++)
    ur->a[i] = (double *)malloc(sizeof(double) * n);
  ur->b = malloc(sizeof(double) * n);
  ur->n = n;
  wsk1 = ur->a;
  wsk2 = ur->b;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (fscanf(in, "%lf", &(ur->a[i][j])) != 1)
        return NULL;
    }
  }
  for (i = 0; i < n; i++)
    if (fscanf(in, "%lf", &(ur->b[i])) != 1)
      return NULL;

  return ur;
}