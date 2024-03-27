CC = gcc
CFLAGS = -std=c89 -pedantic -Wall -Werror -Wextra -Wconversion -Wfloat-equal -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wmissing-prototypes -Wnested-externs -Wold-style-definition -Wpointer-arith -Wredundant-decls -Wshadow -Wstrict-prototypes -Wswitch-default -Wundef -Wunreachable-code -Wwrite-strings -Wno-unused-parameter

compilao: funciones.c
	$(CC) $(CFLAGS) -o func funciones.c

Sean $x,y, z \in \mathbb{Z}$, es cierto que $xy + z \in \mathbb{Z}$, por tanto, definimos la funci\'on $\varphi: A \subseteq \mathbb{Z}^3 \longrightarrow B \subseteq \mathbb{Z}$, tal que $(x,y,z) \mapsto xy + z$.\\
	Como es evidente, $A = Z$ por la propiedad de cerradura de la suma y producto en los enteros, luego, suponiendo $t \in \mathbb{Z}$ tal que $t \notin B$ tenemos
	\emph{caso 1:} $t < \varphi(x,y,z)$ \\
		Por lo tanto, como $\vert \varphi(x,y,z) \vert$ puede ser tan grande como se necesite, $t$ es menor a todos $n \in \mathbb{Z}$ lo cual es un absurdo al ser los enteros un conjunto no acotado. \\
	\emph{caso 2:} $t > \varphi(x,y,z)$ \\
		An\'alogo a \emphi{caso 1}, $t$ debe ser m\'as grande que cualquier entero, por lo tanto incurrimos en el mismo absurdo por ser $\mathbb{Z}$ no acotado.
Deducimos de ambos casos que $B = Z$.\\
Por otro lado, sea $t = \varphi(x,y,z)$ un n\'umero positivo, si $\varphi_E$ es la restricci\'on biyectiva de $\varphi$, donde $E$ es el dominio de la restricci\'on. Dado que $\varphi$ es biyectiva en $E$, existe $\varphi^{-1}_{E}$ tal que $\varphi^{-1}_{E}\left(\varphi_{E}(x,y,z)\right) = (x,y,z)$
