// un codigo que permita guardar todo tipo de informacion, variables, estructuras, arrays, etc
#include <stdio.h>

// Prototipo de la función menu
void menu();

int main() {
    // Llama a la función menu
    menu();
    return 0;
}

// Definición de la función menu
void menu() {
    int opcion;

    do {
        printf("\n*** Menú ***\n");
        printf("1. Iniciar\n");
        printf("2. Continuar\n");
        printf("3. Salir\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("Iniciando...\n");
                // Aquí puedes agregar el código correspondiente para la opción "Iniciar"
                break;
            case 2:
                printf("Continuando...\n");
                // Aquí puedes agregar el código correspondiente para la opción "Continuar"
                break;
            case 3:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Por favor, ingrese una opción válida.\n");
        }
    } while(opcion != 3);
}
