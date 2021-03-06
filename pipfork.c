/*
 * Javier Abellán. 31 de Marzo de 2003
 *
 * Programa de ejemplo de fork()
 */
#include <sys/types.h>
#include <wait.h>
#include <unistd.h>
#include <stdio.h>

/*
 * Programa principal.
 * Crea un proceso hijo. 
 * El proceso hijo escribe su id en pantalla, espera 5 segundos y sale con un
 * exit (33).
 * El proceso padre espera un segundo, escribe su id, el de su hijo y espera
 * que el hijo termine. Escribe en pantalla el valor de exit del hijo.
 */
main()
{
	/* Identificador del proceso creado */
	pid_t idProceso;

	/* Variable para comprobar que se copia inicialmente en cada proceso y que
	 * luego puede cambiarse independientemente en cada uno de ellos. */
	int variable = 1;

	/* Estado devuelto por el hijo */
	int estadoHijo;

	/* Se crea el proceso hijo. En algún sitio dentro del fork(), nuestro
	 * programa se duplica en dos procesos. Cada proceso obtendrá una salida
	 * distinta. */
	idProceso = fork();

	/* Si fork() devuelve -1, es que hay un error y no se ha podido crear el
	 * proceso hijo. */
	if (idProceso == -1)
	{
		perror ("No se puede crear proceso");
		exit (-1);
	}

	/* fork() devuelve 0 al proceso hijo.*/
	if (idProceso == 0)
	{
		/* El hijo escribe su pid en pantalla y el valor de variable 
		 printf ("Hijo  : Mi pid es %d. El pid de mi padre es %d\n", 
			getpid(), getppid());*/
        sleep(1);
        printf("Hijo : Hola padre!\n");
		/* Escribe valor de variable y la cambia 
		printf ("Hijo  : variable = %d. La cambio por variable = 2\n", variable);
		variable = 2;
		
		/* Espera 5 segundos, saca en pantalla el valor de variable y sale */
		sleep (3);
		printf ("Proceso ppadre : %d\n", getppid());
		exit (353);
	}

	/* fork() devuelve un número positivo al padre. Este número es el id del
	 * hijo. */
	if (idProceso > 0)
	{
		/* Espera un segundo (para dar tiempo al hijo a hacer sus cosas y no
		 * entremezclar salida en la pantalla) y escribe su pid y el de su hijo */
		
		printf ("Proceso padre del padre : %d\n", 
			getppid());
        printf("Padre : Hola hijito!\n");
        
        printf("idProceso hijo : %d\n", idProceso);
       
		/* Espera que el hijo muera */
		wait (&estadoHijo);

		/* Comprueba la salida del hijo */
		
            
		/* Escribe el valor de variable, que mantiene su valor original */
		
	}

}

