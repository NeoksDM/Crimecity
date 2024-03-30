#include <stddef.h>
#include <stdlib.h>
#include "funciones.h"
#include <stdio.h>

ptrdiff_t m_bloque;	/*Definiendo variable para la medida del bloque*/

void compr_aloj(void* ptr) { /*Comprobación de alojamiento o realojamiento exitosos*/
	if(ptr == NULL) {	
		printf("ERROR FATAL: No se pudo alojar memoria para palabra\n");
		abort();
	}
}

void *lctr_char() {		
	/*Definición de punteros y creación del bloque*/
	void *palabra = malloc(sizeof(char) + sizeof(void*)), *fin_bloque = palabra + sizeof(char);
	compr_aloj(palabra);	/*Verificación de errores*/
	/*Colocando fin_bloque al final del bloque*/
	*(void**)((char*)palabra + sizeof(char)) = fin_bloque;
	do {	
		/*Almacenando la medida del bloque de memoria*/
		m_bloque = (ptrdiff_t)((char*) fin_bloque - (char*)palabra);
		/*Redimensionando el bloque de memoria*/
		palabra = realloc(palabra, m_bloque + 1 + sizeof(void*)); 
		compr_aloj(palabra);
		/*Actualizando el puntero de fin de bloque*/
		fin_bloque = (char*)palabra + m_bloque + 1 + sizeof(void*);
		/*Reposicionando el puntero de fin de bloque*/
		*(void**)((char*)palabra + m_bloque  + 1 + sizeof(void*)) = fin_bloque;
		/*Recibiendo y colocando caracter por entrada estandar*/
		*((char*)palabra + m_bloque) = getc(stdin);
	} while(*((char*)palabra + m_bloque - 1) != '\n' && *((char*)palabra + m_bloque - 1) != EOF); /*Comprobación de condición*/
	/*Colocando caracter de finalización de cadena de caracteres*/
	*((char*)palabra + m_bloque - 2) = '\0';
	/*Retornando puntero palabra*/
	return palabra;		
}
