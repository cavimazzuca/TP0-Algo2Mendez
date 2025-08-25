#include "tp0.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define FACTOR 2
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
	size_t tmñ_adicional = sizeof(char); //para el \0
	char *celda_salto;
	size_t tamaño = LETRAS_LEIDAS_POR_ITERACION*sizeof(char);
	
	
	char *linea = malloc(tamaño + tmñ_adicional); 
	int i = fread(linea, sizeof(char), tamaño, archivo);
	linea[i] = '\0';
	bool fin_ln = (i != tamaño || salto_encontrado(linea) != NULL);
	while (!fin_ln) {
		tamaño *= 2;
		linea = realloc(linea, tamaño + tmñ_adicional);
		i += fread(linea + i, sizeof(char), tamaño - i, archivo);
		linea[i] = '\0';
		fin_ln = (i != tamaño || salto_encontrado(linea) != NULL);
	}

	if ((celda_salto = salto_encontrado(linea)) != NULL)
		*celda_salto = '\0';

	return NULL;
}

struct pokemon *parsear_pokemon(char *linea)
{
	return NULL;
}

void ordenar_pokemon(struct pokemon *pokemones, int cantidad_pokemones)
{
}
