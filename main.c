#include <stdio.h>
#include <stdlib.h>
#include "src/tp0.h"
#define ERROR -1

int main(int argc, char *argv[])
{
	char *nombre_archivo = argv[0];

	FILE *archivo = fopen(nombre_archivo, "r");
	if (archivo == NULL) {
		return ERROR;
	}

	// char *linea = leer_linea(archivo); //¿Cómo hacemos?

	// struct pokemon *pokemon = parsear_pokemon(linea);

	//Leer todas las líneas y luego mostrar todos los pokemon por pantalla en orden alfabético

	return 0;
}
