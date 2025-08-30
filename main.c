#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/tp0.h"
#define ERROR -1

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Se necesita especificar un archivo.\n");
		return ERROR;
	}
	char *nombre_archivo = argv[1];
	FILE *archivo = fopen(nombre_archivo, "r");
	if (archivo == NULL) {
		printf("EL archivo %s no existe.\n", argv[1]);
		return ERROR;
	}

	int i = 0;
	char *linea = leer_linea(archivo);
	struct pokemon *pokemon;
	struct pokemon *pokes = malloc(sizeof(struct pokemon));
	if (pokes == NULL)
		return ERROR;

	while (linea != NULL) {
		pokemon = parsear_pokemon(linea);
		pokes[i] = *pokemon;
		free(linea);
		free(pokemon);
		i++;
		linea = leer_linea(archivo);
		struct pokemon *pokes_nuevos = realloc(
			pokes, sizeof(struct pokemon) * (size_t)(i + 1));
		if (pokes_nuevos == NULL)
			return ERROR;
		pokes = pokes_nuevos;
	}
	free(linea);

	ordenar_pokemon(pokes, i);

	for (int j = 0; j < i; j++)
		printf("%s\n", pokes[j].nombre);
	for (int j = 0; j < i; j++)
		free(pokes[j].nombre);
	free(pokes);
	fclose(archivo);
	return 0;
}
