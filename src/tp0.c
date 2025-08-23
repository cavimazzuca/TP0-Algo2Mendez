#include "tp0.h"
#include <stdlib.h>
#define FORMATO_LINEA "%[^\n]\n"

char *leer_linea(FILE *archivo)
{
	char* linea;
	int leido = fscanf(archivo, FORMATO_LINEA, linea);
	if (leido != EOF)
		return linea;
	return NULL;
}

struct pokemon *parsear_pokemon(char *linea)
{
	return NULL;
}

void ordenar_pokemon(struct pokemon *pokemones, int cantidad_pokemones)
{
}
