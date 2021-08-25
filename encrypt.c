#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_number(char *de_verificat){
	for(int i = 0; de_verificat[i]; i++)
		if(de_verificat[i] < 48 || de_verificat[i] > 57)
			return 0;
	return 1;
}

char *codificare(char *text){
	char *da = (char *)calloc(strlen(text) + 3, sizeof(char));
	da[0] = text[0];
	for(int i = 1; text[i]; i++)
	{
		char c = (da[0] + text[i]) % 256;
		da[i] = c;
	}
	
	return da;
}

int main()
{
	int nr_linii;
	scanf("%d\n", &nr_linii);
	char **matrice_propozitii = (char **)malloc(nr_linii * sizeof(char *));
	for(int i = 0; i < nr_linii; i++){
		char o_prop[201];
		fgets(o_prop, 201, stdin);
		o_prop[strlen(o_prop) - 1] = '\0';
		matrice_propozitii[i] = (char *)calloc(500, sizeof(char));
		char *cuvant;
		cuvant = strtok(o_prop," \n");

		while(cuvant != NULL){
			if(check_number(cuvant) == 0)
			{
				char *de_copiat = codificare(cuvant);
				strncat(matrice_propozitii[i], de_copiat, strlen(de_copiat));
				strcat(matrice_propozitii[i], " ");
				free(de_copiat);
				//strcat(matrice_propozitii[i], "NU ");
			}
			else
			{
				//strcat(matrice_propozitii[i], "DA ");
				strncat(matrice_propozitii[i], cuvant, strlen(cuvant));
				strcat(matrice_propozitii[i], " ");
			}
			cuvant = strtok(NULL," \n");
		}
		matrice_propozitii[i][strlen(matrice_propozitii[i]) - 1] = '\0';
		strcat(matrice_propozitii[i],"\n");
	}

	for (int i = 0; i < nr_linii; i++)
	{
		printf("%s", matrice_propozitii[i]);
	}

	for (int i = 0; i < nr_linii; i++)
	{
		free(matrice_propozitii[i]);
	}
	free(matrice_propozitii);
	return 0;
}