#include "gauss.h"
#include <math.h>
#include <stdio.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 * Zwraca 2 - macierz nie jest kwadratowa
 * Zwraca 3 - macierz b zawiera za malo rozwiazan
 */
int eliminate(Matrix *mat, Matrix *b){
	if(mat->c != mat->r){
		printf("gauss.c: blad, macierz A nie jest kwadratowa\n");
		return 2;
	}
	if(mat->r != b->r){
		printf("gauss.c: blad, macierz b ma mniej wierszy niz macierz A\n");
		return 3;
	}
	for (int k=0; k<=mat->c-1;k++)
	{
		/*Szukanie dominujacego*/
		int ielmax = k;
		double elmax = fabs(mat->data[k][k]);
		for(int m = k+1; m<mat->r ; m++)
			if(fabs(mat->data[m][k])>elmax)
			{
				elmax=fabs(mat->data[m][k]);
				ielmax=m;
			}
		if(elmax==0){
			printf("gauss.c: macierz osobliwa\n");
			return 1;
		}
		/*Zamiana*/
		if(ielmax != k)
		{
			double *rob = mat->data[k];
			mat->data[k] = mat->data[ielmax];
			mat->data[ielmax] = rob;
			rob = b->data[k];
			b->data[k]= b->data[ielmax];
			b->data[ielmax] = rob;
		}
		/*Odejmowanie*/
		for (int i = k+1; i<mat->r; i++)
		{
			double r = mat->data[i][k] / mat->data [k][k];
			b->data[i][0] = b->data[i][0] - r*b->data[k][0];
			for ( int j=k+1; j<mat->r; j++){
				mat->data[i][j] = mat->data[i][j] - r * mat->data[k][j];
			}
		}
		/*Zerowanie*/
		for (int i = k+1; i< mat->r; i++)
			mat->data[i][k] = 0;
	}
	if ( mat->data[mat->r-1][mat->r-1] == 0)
		return 1;
	return 0;
}
