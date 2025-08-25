#include "tp0.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LETRAS_LEIDAS_POR_ITERACION 10

/*
 * Retorna la posición de 'linea' en donde encuentra el primer '\n'.
 * 'linea' debe ser un string. 
 */
char *salto_encontrado(char *linea)
{
	return strstr(linea, "\n");
}

char *leer_linea(FILE *archivo)
{
	size_t tmñ = LETRAS_LEIDAS_POR_ITERACION;
	char* linea = malloc(tmñ);
	if (linea == NULL)
		return NULL;
	if (fgets(linea, tmñ, archivo) == NULL) {
		free(linea);
		return NULL;
	}
	while (strlen(linea)+1 == tmñ && strstr(linea, "\n") == NULL) {
		tmñ *= 2;
		char* nueva_linea = realloc(linea, tmñ);
		if (nueva_linea == NULL) {
			free(linea);
			return NULL;
		}
		linea = nueva_linea;
		fgets(&linea[strlen(linea)], tmñ-strlen(linea), archivo);
	}
	char *ultimo_char = &linea[strlen(linea)-1];
	if (*ultimo_char == '\n')
		linea[strlen(linea)-1] = '\0';
	return linea;
}

struct pokemon *parsear_pokemon(char *linea)
{
	return NULL;
}

void ordenar_pokemon(struct pokemon *pokemones, int cantidad_pokemones)
{
}
