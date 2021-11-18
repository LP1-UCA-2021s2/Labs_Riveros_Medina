/*
 ============================================================================
 Name        : Lab.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimetodoloscaminos(int *mat, int i, int j, int m, int n, int *caminos, int p)
{
	if (i==m-1)
	{
		for (int k=j;k<n;k++)
			caminos[p+k-j] = *((mat+i*n)+k);
		for (int l=0; l<p+n-j; l++)
			printf ("%d",caminos[l]);
		printf("\n");

		return;
	}
	if (j == n - 1)
	{
		for (int k=i; k<m; k++)
			caminos[p+k-i] = *((mat+k*n)+j);
		for (int l=0; l<p+m-i; l++)
			printf ("%d",caminos[l]);
		printf("\n");
		return;
	}
	caminos[p] = *((mat+i*n)+ j);
	imprimetodoloscaminos(mat, i+1, j, m, n, caminos, p+1);
	imprimetodoloscaminos(mat, i, j+1, m, n, caminos, p+1);
	imprimetodoloscaminos(mat, i+1, j+1, m, n, caminos, p+1);
}
void calculaloscaminos(int *mat, int m, int n)
{

	int *caminos = (int*)malloc(m+n);;
	imprimetodoloscaminos(mat, 0, 0, m, n, caminos, 0);
}
int main()
{
	int m = 3;
	int n = 3;
	int mat[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	calculaloscaminos(*mat, m, n);
	return 0;
}
