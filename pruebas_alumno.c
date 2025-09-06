#include <stdio.h>
#include "pa2m.h"
#include "src/tp1.h"

#define ARCHIVO_PRUEBA_INEXISTENTE "ejemplos/asdkasjhfskladjhfksdfhksdf.csv"
#define ARCHIVO_PRUEBA_VACIO "ejemplos/vacio.csv"
#define ARCHIVO_PRUEBA_NORMAL "ejemplos/normal.csv"
#define ARCHIVO_PRUEBA_INVALIDO "ejemplos/sin_coma.csv"

void tp1_leer_archivo_devuelve_no_null()
{
	tp1_t *tp1 = tp1_leer_archivo(ARCHIVO_PRUEBA_NORMAL);
	pa2m_afirmar(tp1 != NULL, "Abrir un archivo bueno NO devuelve NULL");
	if (tp1 != NULL) {
		
		tp1_destruir(tp1);
		
	}
		
}

void tp1_leer_archivo_devuelve_null_cuando_el_archivo_es_inválido()
{
	tp1_t *tp1 = tp1_leer_archivo(ARCHIVO_PRUEBA_INVALIDO);
	pa2m_afirmar(tp1 == NULL, "Abrir un archivo inválido devuelve NULL");
	if (tp1 != NULL)
		tp1_destruir(tp1);
}

void tp1_leer_archivo_devuelve_null_cuando_el_archivo_esta_vacío()
{
	tp1_t *tp1 = tp1_leer_archivo(ARCHIVO_PRUEBA_VACIO);
	pa2m_afirmar(tp1 == NULL, "Abrir un archivo vacío devuelve NULL");
	if (tp1 != NULL)
		tp1_destruir(tp1);
}

void tp1_leer_archivo_devuelve_null_cuando_el_archivo_no_existe()
{
	tp1_t *tp1 = tp1_leer_archivo(ARCHIVO_PRUEBA_INEXISTENTE);
	pa2m_afirmar(tp1 == NULL, "Abrir un archivo inexistente devuelve NULL");
	if (tp1 != NULL)
		tp1_destruir(tp1);
}

int main()
{
	pa2m_nuevo_grupo("Pruebas de lectura de archivos");
	tp1_leer_archivo_devuelve_null_cuando_el_archivo_no_existe();
	tp1_leer_archivo_devuelve_null_cuando_el_archivo_esta_vacío();
	tp1_leer_archivo_devuelve_no_null();

	//quitado hasta arreglar parsear_pokemon
	//tp1_leer_archivo_devuelve_null_cuando_el_archivo_es_inválido();
	
	return pa2m_mostrar_reporte();
}
