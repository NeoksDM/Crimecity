#ifndef EJERCICIOS_H
#define EJERCICIOS_H

/*Ejercicio 2769 de leetcode, primer ejercicio de esta plataforma que yo hago:
 * Encuentra el máximo número lograble.		
 * Un entero x es llamado lograble si puede volverse igual a num después de aplicar la siguiente operación no más de t veces:
 * 	Incrementar o decrementar x por 1, y simultáneamente incrementar o decrementar num por 1.
 * 	Regresa el número máximo lograble. Se puede probar que  existe al menos un número lograble.
 *
 * Bien, mucha pena con leetcode, pero si van a decir que algo es demostrable, pues toca,
 * 	\emph{Demostraci\'on.} Sean $num$, $t$ enteros, sea adem\'as $S$ el conjunto definido tal que 
 *		$$S = \{x \in \mathbb{Z}: |x - num| \leq 2|t|\}$$
 *	entonces, dado que $S$ es la bola cerrada de centro $num$ y radio $2t$, sabemos que $S$ es no vac\'io debido a que $\mathbb{Z}$ es no vac\'io y $num \in \mathbb{Z}$,  esto nos lleva a concluir que, gracias al principio de buen orden, para $t = 0$, entonces $x = num$. Por lo tanto, $S = \{num\}$. Con lo que queda demostrado el teorema. Sin embargo, se pueden extraer m\'as cosas de este resultado, tales como
 *	$|x - num| \leq 2|t|$ es lo mismo que $-2|t| < x - num < 2|t|$ \\
 *	$-2|t| < x - num < 2|t|$  implica que $-2|t| + num < x < 2|t| + num$ \\
 *	$-2|t| + num < x < 2|t| + num$ implica que $\min{S} = num -2|t|$ y $\max{S} = num + 2|t|$.
 *La verdad sí es un ejercicio bastante fácil de matemáticas, sigamos, usemos esto para crear el programa que de el máximo de */
 int max_n_lograble(int num, int t);



 /*--------------------------------------------*/



 /* Ejercicio 2894 de LeetCode, segundo ejercicio que hago de esta plataforma:
  *
  * Diferencia de la suma de los numeros divisibles y no divisibles.
  * Te dan dos enteros, n y m.
  * Define dos enteros, num1 y num2 como sigue
  * num1: La suma de todos los enteros en el rango (1, n) que no son divisibles para m,
  * num2: La suma de todos los enteros en el rango (1,n) que son divisibles para m.
  * Regrese el entero num1 - num2.
  * Sean $n, m \in \mathbb{Z}^{+}$, definimos los conjuntos $S_{d}$ y $S_{nd}$ tales que
  * $$S_{d} = \{x \in \mathbb{Z}: 1 \leq x \leq n\text{ y } x = mq, q \in \mathbb{Z}\}$$
  * $$S_{nd} = \{x \in \mathbb{Z}: 1 \leq x \leq n\text{ y } x = mq +r/ q, r \in \mathbb{Z}: 0 < r \leq m\}$$*/
 int dif_sum_d_nd(int n, int m);

#endif
