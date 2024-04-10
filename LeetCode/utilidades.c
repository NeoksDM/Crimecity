#include "utilidades.h"
#include <string.h>
#include "ejercicios.h"

/*Cadenas de caracteres para el menú*/
char *tabla[7] = {
	"1. Ejercicio 2769, maximo lograble",
	"2. Ejercicio 2894, diferencia del sumatorio de los divisores",
	"E. Salida",
	"S. Avanzar",
	"I. Retroceder",
	"Ingrese la opcion deseada"
};

/*Presentanción de las opciones del menú --5 opciones como máximo--*/
void tabla_menu(char* tabla, int pg){
	for(int 1 = (pg - 1); i < ; i++) {
		printf("%d, %s\n", i + 1, tabla[i]);
	}
}

/*Menú con su número de página*/
void menu(int pagina) {
	pagina = 1;
	tabla_menu(menu);
	char opcion = getc(stdin);
	menu_seleccion(opcion);
}

/*Funcíon para seleccionar en el menú*/
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

/*Ecuación de división*/
void eq_div(int b, int a, int q) {
	b - (a * q);
}

/*Algoritmo de división*/
void alg_div(int b, int a) {
	int i = 0;
	while(i < a) {
		eq_div(b, a, i);
		i++;
	}
}

