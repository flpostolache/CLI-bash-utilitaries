#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char lookup_string[30];
	fgets(lookup_string, 30, stdin);
	lookup_string[strlen(lookup_string) - 1] = '\0';
	int nr_linii, contor = 0;
	scanf("%d\n", &nr_linii);
	char **matrice_propozitii = (char **)malloc(nr_linii * sizeof(char *));

	for (int i = 0; i < nr_linii; i++)
	{
		char propozitie[201];
		fgets(propozitie, 201, stdin);
		propozitie[strlen(propozitie) - 1] = '\0';
		if (strstr(propozitie, lookup_string) != NULL)
		{
			matrice_propozitii[contor] = (char *)calloc(500, sizeof(char));
			char *token;
			token = strstr(propozitie, lookup_string);
			int last_pointer = 0;
			while (token != NULL)
			{
				int dif = token - propozitie + strlen(lookup_string);
				strncat(matrice_propozitii[contor], propozitie + last_pointer, token - propozitie - last_pointer);
				strcat(matrice_propozitii[contor], "\e[0;31m");
				strcat(matrice_propozitii[contor], lookup_string);
				strcat(matrice_propozitii[contor], "\e[m");
				last_pointer = token - propozitie + strlen(lookup_string);
				token = strstr(propozitie + dif, lookup_string);
			}

			strcat(matrice_propozitii[contor], propozitie + last_pointer);
			strcat(matrice_propozitii[contor], "\n");
			contor++;
		}
	}

	for (int i = 0; i < contor; i++)
	{
		printf("%s", matrice_propozitii[i]);
	}
	for (int i = 0; i < contor; i++)
	{
		free(matrice_propozitii[i]);
	}
	free(matrice_propozitii);
	return 0;
}
