#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>


struct ciudad {
	char *c_nombre;	//Para almacenar el nombre de la ciudad
	int c_area;	//Para almacenar el area de la ciudad
};

int gen_dunit() {
	


char* lectura_palabra() {
	unsigned int i = 1;

	char *palabra = malloc(sizeof(char) * i);
	if(!palabra) { printf("Error: No se creo el puntero: palabra\n"); free(palabra); return NULL; }

	char c;
	
	while((c = getchar()) != '\n' && c != EOF) {
		if(!isalnum(c) && c != '_') { c = '_'; }
		i++;
		if(i >= UINT_MAX) { printf("Error: longitud de array insegura\n"); free(palabra); return NULL; }

		palabra = realloc(palabra, sizeof(char) * (i + 1));
		if(!palabra) { printf("Error: No se creo el puntero: palabra\n");  free(palabra); return NULL; }

		palabra[i - 1] = (char)c;
	}

	palabra[i] = '\0';
	printf("%s", palabra);

	return palabra;
}

char* depurar_palabra(char* palabra) {
	char* c = palabra;
	while(*c){
		if(!isalnum(*c) && *c != '_') {
			*c = '_';
		}
		c++;
	}
	return palabra;
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
