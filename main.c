#include <stdio.h>	//Para entrada y salida de datos, salida de errores; creación, lectura, y escritura de archivos
#include <stdlib.h>	//Para alocar y realocar memoria con su respectivo puntero
#include <limits.h>	//Para cotas máximas y no revasar el uso de memoria
#include <ctype.h>	//Para detección de caracteres no alfanúmerico
#include <string.h>	//Para copia y concatenación de strings
#include <time.h>	//Para tener acceso al reloj del sistema

//Estructuras//
struct ciudad {		//Estructura de dato que simulara el concepto de ciudad
	char *c_nombre;		//Para almacenar el nombre de la ciudad
	int c_area;		//Para almacenar el área de la ciudad
};


//Funciones//
char* lectura_palabra() {	//Entrada y almacenamiento de datos recibidos del teclado a un arreglo de tipo char
	//RECORDATORIO: un array es sólo un puntero a un bloque de memoria de un mismo tipo//
	unsigned int i = 1;	//índice del array de caracteres -- Existe la intención de cambiarlo por un puntero tipo char y usar la aritmética de punteros para simular su comportamiento como índice y receptor de getchar() --

	char *palabra = malloc(sizeof(char) * i);	//Array de caracteres
	//El array es un puntero de la imagen de malloc para un arreglo de memoria tipo caracter de un elemento; ergo, un byte
	if(!palabra) { printf("Error: No se creo el puntero: palabra\n"); free(palabra); return NULL; } //Prueba de éxito en la creación

	char c;		//Variable auxiliar para recibir -- Existe la intención de cambiarlo por un puntero tipo char, como se explicó en el comentario del int i --
	
	while((c = getchar()) != '\n' && c != EOF) { //Bucle que comprueba la entrada con getchar(), la almacena en c, la comprueba con el salto linea (o sea, el enter), y la comprueba con la tecla escape
		c = (char)c;	//Casteo de c a tipo char
		if(!isalnum(c) && c != '_') { c = '_'; }	//Depuración de la entrada de teclado
	i++;	//Incremento del índice
		if(i >= UINT_MAX) { printf("Error: longitud de array insegura\n"); free(palabra); return NULL; }	//Comprobación de que la magnitud del índice no haya superado el tamaño máximo de su tipo de dato

		palabra = realloc(palabra, sizeof(char) * (i + 1));	//Realocación de la memoria para asignar más memoria al array de ser necesario, el incremento es acorde al índice
		if(!palabra) { printf("Error: No se creo el puntero: palabra\n");  free(palabra); return NULL; }	//Comprobación de errores en caso de que no se haya podido realocar la memoria

		palabra[i - 1] = (char)c;	//Asignación de c, el output de getchar(), a palabra, el array de caracteres
	}

	palabra[i] = '\0';	//Terminación del array en el caracter terminador
	printf("%s", palabra);	//Impresión por salida en consola del array de caracteres

	return palabra;	//Retorno del array, se regresa un puntero al bloque de memoria
}

char* depurar_palabra(char* palabra) {	//Segunda depuración -- Existe la intención de eliminar esta depuración al no considerarla necesaria --
	char* c = palabra;	//Puntero al "array" (es un puntero) recibido como argumento de la función, 
	while(*c){	//Bucle que comprueba como caso default que el c no apunte al caracter terminador
		if(!isalnum(*c) && *c != '_') {
			*c = '_';
		}	//Depuración
		c++;
	}
	return palabra;	//Retorno del "array"
}

int main() {
	struct ciudad city;	//Creando la variable ciudad

	printf("Ingresa el area de la ciudad\n");	//Indicando que se ingrese el area
	scanf("%d", &city.c_area);	//Guardando el area en el miembro de la ciudad
	printf("Ingresa el nombre de la ciudad\n");	//Indicando que se ingrese el nombre
	getchar();
	city.c_nombre = lectura_palabra();


	char* nombre_archivo = malloc(strlen(city.c_nombre) + 5);
	if(!nombre_archivo) { printf("Error: No se pudo asignar memoria para el nombre del archivo\n"); free(city.c_nombre); return -1; }

	strcpy(nombre_archivo, depurar_palabra(city.c_nombre));
	strcat(nombre_archivo, ".map");

	printf("%s", nombre_archivo);

	FILE *archivo = fopen(nombre_archivo, "wb");	//Creando el archivo para guardar la ciudad
	if(!archivo) { printf("Error: No se pudo crear el archivo\n"); free(city.c_nombre); return -1; }
	
	fwrite(&city, sizeof(struct ciudad), 1, archivo);	//Escribiendo la ciudad en el archivo
	fclose(archivo);	//Cerrando el archivo

	free(city.c_nombre);

	return 0;
}
