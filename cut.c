#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int main()
{
	char del[11];
	int n, m, contor = 0;
	char fields[201];
	int fields_int[111];
	char out_del[11];

	fgets(del, 11, stdin);
	del[strlen(del) - 1] = '\0';

	scanf("%d\n", &n);
	fgets(fields, 201, stdin);
	fields[strlen(fields) - 1] = '\0';
	char *token = (char *)strtok(fields, ",\n");
	while (token != NULL)
	{
		fields_int[contor] = atoi(token);
		contor++;
		token = strtok(NULL, ",\n");
	}
	qsort(fields_int, n, sizeof(int), cmpfunc);

	fgets(out_del, 11, stdin);
	out_del[strlen(out_del) - 1] = '\0';

	scanf("%d\n", &m);
	char **matr_rasp = (char **)malloc(m * sizeof(char *));

	for (int i = 0; i < m; i++)
	{
		contor = 1;
		int contor_indice = 0;
		char propozitie[201];
		matr_rasp[i] = (char *)calloc(500, sizeof(char));
		fgets(propozitie, 201, stdin);
		propozitie[strlen(propozitie) - 1] = '\0';

		char *token = strtok(propozitie, del);
		while (token != NULL)
		{
			if (contor_indice < n && fields_int[contor_indice] == contor)
			{
				strcat(matr_rasp[i], token);
				strcat(matr_rasp[i], out_del);
				contor_indice++;
				while (contor_indice < n && fields_int[contor_indice] == fields_int[contor_indice - 1])
					contor_indice++;
			}
			contor++;
			token = strtok(NULL, del);
		}
		if (matr_rasp[i][0] != '\0')
		{
			for (int j = strlen(matr_rasp[i]) - strlen(out_del); matr_rasp[i][j]; j++)
			{
				matr_rasp[i][j] = '\0';
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		printf("%s\n", matr_rasp[i]);
	}
	for (int i = 0; i < m; i++)
	{
		free(matr_rasp[i]);
	}
	free(matr_rasp);

	return 0;
}
