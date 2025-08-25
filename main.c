#include <stdio.h>
#include <stdlib.h>
#include "src/tp0.h"
#define ERROR -1

int main(int argc, char *argv[])
{
	if (argc<2) {
		printf("Se necesita especificar un archivo.\n");
		return ERROR;
	}
	char *nombre_archivo = argv[1];

	FILE *archivo = fopen(nombre_archivo, "r");
	if (archivo == NULL) {
		printf("EL archivo %s no existe.\n", argv[1]);
		return ERROR;
	}

	//char* linea = 
	leer_linea(archivo);
	//printf("%s\n",linea);
	//free(linea);
	fclose(archivo);

	// struct pokemon *pokemon = parsear_pokemon(linea);

	//Leer todas las líneas y luego mostrar todos los pokemon por pantalla en orden alfabético

	return 0;
}
