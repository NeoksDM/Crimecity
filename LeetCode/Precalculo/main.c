#include <stdio.h>

int main(void);

int main(void) {
	float vels[3];
	vels[0] = 30.0, vels[1] = 60.0,	vels[2] = (vels[0] + vels[1]) / 2;
	printf("La velocidad promedio es: %f \n", vels[2]);
	return 0;
}
