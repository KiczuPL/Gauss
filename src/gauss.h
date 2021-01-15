#ifndef _GAUSS_H_INCLUDED_
#define _GAUSS_H_INCLUDED_

#include <stdio.h>

typedef struct {
  double **a;
  double *b;
  int n;
} * ur_t;

void solve(ur_t, double *);
ur_t read(FILE *);

#endif