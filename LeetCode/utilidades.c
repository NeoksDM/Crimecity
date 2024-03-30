#include "utilidades.h"
#include <string.h>
#include "ejercicios.h"

/*Cadenas de caracteres para el menú*/
char *tabla[] = {
	"1. Ejercicio 2769, maximo lograble",
	"E. Salida",
	"S. Avanzar",
	"I. Retroceder",
	"Ingrese la opcion deseada"
};

/*Presentanción de las opciones del menú --5 opciones como máximo--*/
void tabla_menu(char* table){
	int n_opciones = sizeof(table) / sizeof(table[0]);
	for(int 1 = 0; i < n_opciones; i++) {
		printf("%d, %s\n", i + 1, tabla[i]);
	}
}
void menu() {
	tabla_menu(menu);
	char opcion = getc(stdin);
	menu_seleccion(opcion);
}
void menu_seleccion(char opcion) {
	while(opcion != 'E') {
		switch((int)opcion){
			case 1: {
					int centro, radio;
					printf("%s", menu[0]);
					printf("Ingresa el centro\n");
					scanf("%d", &centro);
					printf("Ingresa el radio\n");
					scanf("%d", &radio);
					printf("El maximo numero lograble es, %d", max_n_lograble(centro, radio));
					
				}
			default: {
					 printf("No ingresaste algo valido\n");
				 }
		}
	}
}

