#include "backsubst.h"
#include <stdio.h>
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
/*int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	double l;
	int i, j;
	if (mat->c != mat->r){
	       	printf("backsubst.c: blad, macierz nie jest kwadratowa");
		return 2;
	}
	for (i=mat->r-1; i>=0; i--){
		for(j=i+1; j<mat->c; j++)
			l+=mat->data[i][j] * x->data[j][0];
		if (mat->data[i][i]==0){
			printf("backsubst.c: blad, dzielenie przez zero - element %d %d\n",i, i);
			return 1;
		}
		x->data[i][0] = (b->data[i][0]-l)/mat->data[i][i];
	}
	return 0;
}*/
int backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	int n = mat->r;
	if( mat->data[n-1][n-1] == 0){
		printf("backsubst.c: blad, dzielenie przez zero - element %d %d  \n", n-1, n-1);
		return 1;
	}
	x->data[n-1][0] = b->data[n-1][0] / mat->data[n-1][n-1];
	int i, j;
	double l;
	for(i=n-2; i>=0; i--){
		for(j = i+1; j<n; j++)
			l+=mat->data[i][j] * x-> data[j][0];
		if (mat->data[i][i] == 0){
			printf("backsubst.c: blad, dzielenie przez zero - element %d %d  \n", i, i);
			return 1;
		}
		x->data[i][0] = (b->data[i][0] - l) / mat->data[i][i];
		l=0;
	}
	return 0;
}
