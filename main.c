#include "funciones.h"
#include <stdio.h>

int main() {
	char *c_nombre = (char*)lctr_char();
	printf("El nombre de la ciudad ingresada es: %s\n", c_nombre);
	free(c_nombre);
	return 0;
}

