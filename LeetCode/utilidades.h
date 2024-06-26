#ifndef UTILIDADES_H
#define UTILIDADES_H

/*Menú donde se presentan los ejercicios ya logrados, su identificación (numero de ejercicio en leetcode), mismo menú debe aceptar el ingreso de un entero que fungirá como opción ingresada, en lo cual se desplegará el script de ejecución del ejercicio correspondiente*/
void menu(void);
/*Script para la recepción de la opción ingresada por el usuario */
void menu_seleccion(int opcion);

/*Función main*/
int main(void);

/*Ecuación de división*/
void eq_div(int b, int a, int q);

/*Algoritmo de división*/
int alg_div(int b, int a);
#endif 
