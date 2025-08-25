#include "tp0.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define FACTOR 2
#define LETRAS_LEIDAS_POR_ITERACION 10

/* Retorna la posición de 'linea' en donde encuentra el primer '\n'.
 * 'linea' debe ser un string. 
 */
char *salto_encontrado(char *linea)
{
	return strstr(linea, "\n");
}

char *leer_linea(FILE *archivo)
{
	size_t celda_adicional = sizeof(char);
	size_t tamaño_lectura = LETRAS_LEIDAS_POR_ITERACION*sizeof(char);
	char *celda_salto;

	char *linea = malloc(tamaño_lectura + celda_adicional); //celda adicional para el \0
	int cantidad_c = fread(linea, sizeof(char), tamaño_lectura, archivo);
	linea[cantidad_c] = '\0';
	bool fin_encontrado = (cantidad_c != tamaño_lectura || salto_encontrado(linea) != NULL);
	while (!fin_encontrado) {
		tamaño_lectura *= 2;
		linea = realloc(linea, tamaño_lectura + celda_adicional);
		cantidad_c += fread(linea + cantidad_c, sizeof(char), tamaño_lectura - cantidad_c, archivo);
		linea[cantidad_c] = '\0';
		fin_encontrado = (cantidad_c != tamaño_lectura || salto_encontrado(linea) != NULL);
	}

	printf("cantidad de chars(sin el \\0): %i\n", cantidad_c);
	if ((celda_salto = salto_encontrado(linea)) != NULL)
		*celda_salto = '\0';
	printf("longitud de string final(si se cortó con \\n): %i\n", (int)strlen(linea));
	printf("%s\n", linea);
	
	free(linea);
	
	return NULL;
}

struct pokemon *parsear_pokemon(char *linea)
{
	return NULL;
}

void ordenar_pokemon(struct pokemon *pokemones, int cantidad_pokemones)
{
}
