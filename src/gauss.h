#ifndef _GAUSS_H
#define _GAUSS_H

#include "mat_io.h"
#include <stdlib.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b);
void wyniki(double *r, int liczba);
void spr(Matrix*mat, Matrix *b,  int r, int c);
void zamien(Matrix *mat, Matrix *b, int m, int r);
#endif
