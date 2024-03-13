#include <stdio.h>

struct ciudad {
	int area;
};

int main() {
	struct ciudad city;
	printf("Ingresa el area de la ciudad\n");
	scanf("%d", &city.area);

	FILE *archivo = fopen("ciudad.dat", "wb");
	
	fwrite(&city, sizeof(struct ciudad), 1, archivo);
	fclose(archivo);

	return 0;
}
