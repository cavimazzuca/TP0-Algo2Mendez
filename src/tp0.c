#include "tp0.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LETRAS_LEIDAS_POR_ITERACION 10
#define TEXTO_ELEC "ELEC"
#define TEXTO_FUEG "FUEG"
#define TEXTO_PLAN "PLAN"
#define TEXTO_AGUA "AGUA"
#define TEXTO_NORM "NORM"
#define TEXTO_FANT "FANT"
#define TEXTO_PSI "PSI"
#define TEXTO_LUCH "LUCH"
#define ERROR -1

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
	if (archivo == NULL)
		return NULL;
	size_t tmñ = LETRAS_LEIDAS_POR_ITERACION;
	char *linea = malloc(tmñ);
	if (linea == NULL)
		return NULL;
	if (fgets(linea, (int)tmñ, archivo) == NULL) {
		free(linea);
		return NULL;
	}
	while (strlen(linea) + 1 == tmñ && strstr(linea, "\n") == NULL) {
		tmñ *= 2;
		char *nueva_linea = realloc(linea, tmñ);
		if (nueva_linea == NULL) {
			free(linea);
			return NULL;
		}
		linea = nueva_linea;
		char *siguiente_linea = &linea[strlen(linea)];
		siguiente_linea = fgets(siguiente_linea,
					(int)tmñ - (int)strlen(linea), archivo);
	}
	char *ultimo_char = &linea[strlen(linea) - 1];
	if (*ultimo_char == '\n')
		linea[strlen(linea) - 1] = '\0';
	return linea;
}

/* 
 * Convierte a la primera coma en el string en '\0' y devuelve un puntero al
 * siguiente carácter.
 * Si no encuentra una coma, retorna NULL.
 */
char *desde_coma(char *string)
{
	char *coma = strstr(string, ",");
	if (coma == NULL)
		return NULL;
	*coma = '\0';
	return coma + 1;
}

/*
 * Devuelve el tipo del pokemon ingresado de formato string a formato int según
 * el enum que le corresponde definido en TP0_H_
 */
int texto_a_tipo(char *string)
{
	if (strcmp(string, TEXTO_ELEC) == 0)
		return TIPO_ELEC;
	if (strcmp(string, TEXTO_FUEG) == 0)
		return TIPO_FUEG;
	if (strcmp(string, TEXTO_PLAN) == 0)
		return TIPO_PLAN;
	if (strcmp(string, TEXTO_AGUA) == 0)
		return TIPO_AGUA;
	if (strcmp(string, TEXTO_FANT) == 0)
		return TIPO_FANT;
	if (strcmp(string, TEXTO_LUCH) == 0)
		return TIPO_LUCH;
	if (strcmp(string, TEXTO_NORM) == 0)
		return TIPO_NORM;
	if (strcmp(string, TEXTO_PSI) == 0)
		return TIPO_PSI;
	return ERROR;
}

struct pokemon *parsear_pokemon(char *linea)
{
	if (linea == NULL)
		return NULL;
	int longitud_linea = (int)strlen(linea) + 1;
	char linea_stack[longitud_linea];
	strcpy(linea_stack, linea);

	char *id = linea_stack;
	char *nombre = desde_coma(linea_stack);
	if (nombre == NULL)
		return NULL;
	char *tipo = desde_coma(nombre);
	if (tipo == NULL)
		return NULL;
	char *ataque = desde_coma(tipo);
	if (ataque == NULL)
		return NULL;
	char *defensa = desde_coma(ataque);
	if (defensa == NULL)
		return NULL;
	char *velocidad = desde_coma(defensa);
	if (velocidad == NULL)
		return NULL;
	int tipo_num = texto_a_tipo(tipo);
	if (tipo_num == ERROR)
		return NULL;

	struct pokemon *pokemon = malloc(sizeof(struct pokemon));
	if (pokemon == NULL)
		return NULL;
	pokemon->id = atoi(id);
	pokemon->nombre = malloc(sizeof(char) * (strlen(nombre) + 1));
	strcpy(pokemon->nombre, nombre);
	pokemon->tipo = tipo_num;
	pokemon->ataque = atoi(ataque);
	pokemon->defensa = atoi(defensa);
	pokemon->velocidad = atoi(velocidad);

	return pokemon;
}

/*
 * Dado dos strings, devuelve true si el primero viene primero en el alfabeto.
 * Si no, devuele false.
 */
bool primero_en_alfabeto(char *primero, char *segundo)
{
	if (strcmp(primero, segundo) < 0)
		return true;
	return false;
}

void ordenar_pokemon(struct pokemon *pokemones, int cantidad_pokemones)
{
	if (pokemones == NULL)
		return;
	for (int i = 0; i < cantidad_pokemones; i++) {
		for (int j = 0; j < cantidad_pokemones - 1; j++) {
			struct pokemon tmp;
			char *pokemon = pokemones[j].nombre;
			char *sig_pokemon = pokemones[j + 1].nombre;
			if (!primero_en_alfabeto(pokemon, sig_pokemon)) {
				tmp = pokemones[j];
				pokemones[j] = pokemones[j + 1];
				pokemones[j + 1] = tmp;
			}
		}
	}
}
