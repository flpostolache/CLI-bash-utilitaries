#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cmpfunc(const void *pa, const void *pb){
	const float *a = *(const float **)pa;
    const float *b = *(const float **)pb;
	if(a[0] > b[0])
		return -1;
	if(a[0] < b[0])
		return 1;
	return -1;
}

int main()
{
	int nr_linii;
	scanf("%d\n", &nr_linii);
	float **matrice = (float **)malloc(nr_linii * sizeof(float *));
	for (int i = 0; i < nr_linii; i++){
		matrice[i] = (float *)calloc(200, sizeof(float));
		int nr, contor = 1, suma = 0;
		scanf("%d", &nr);
		while(nr != 0){
			suma += nr;
			matrice[i][contor] = nr;
			contor++;
			scanf("%d", &nr);
		}
		matrice[i][0] = ((float)suma / (float)(contor - 1));
	}

	qsort(matrice, nr_linii, sizeof(matrice[0]), cmpfunc);
	
	for (int i = 0; i < nr_linii; i++){
		printf("%-10.3f", matrice[i][0]);
		for(int j = 1; matrice[i][j] != 0; j++){
			if(matrice[i][j+1] == 0)
				printf("%.0f", matrice[i][j]);
			else
				printf("%.0f ", matrice[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < nr_linii; i++)
	{
		free(matrice[i]);
	}
	free(matrice);
	return 0;
}