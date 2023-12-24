//CóDIGO DEL HIJO

#include <mpi.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
int main(int argc, char* argv[]) {
	int rank, rankhijos, tamano;
	int longitud;
	char mensaje_hijo[42], mensaje_padre[60];
	strcpy_s(mensaje_hijo, "Hola hermanos, soy el hijo de menor rango");
	MPI_Comm intercom, intracom;
	MPI_Init(&argc, &argv);
	MPI_Comm_get_parent(&intercom);
	MPI_Intercomm_merge(intercom, 1, &intracom);
	MPI_Comm_rank(intracom, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &tamano);
	MPI_Comm_rank(MPI_COMM_WORLD, &rankhijos);
	printf("[Hijo %d]¡Hola! Soy el hijo numero %d y acabo de ser creado \n", rankhijos, rankhijos);
	fflush(stdout);
	MPI_Bcast(&mensaje_padre, 50, MPI_CHAR, 0, intracom);
	//HIJO DE MENOR RANGO
	if (rankhijos == 0) {
		//Mandamos el mensaje del hijo menor a todos los hijos enviado por el comunicador world
		MPI_Bcast(&mensaje_hijo, 42, MPI_CHAR, 0, MPI_COMM_WORLD);
	}
	printf("[Hijo %d] Mi hermano de menor rango ha dicho: %s\n", rankhijos, &mensaje_hijo);
	fflush(stdout);
	printf("[Hijo %d] Mi padre ha dicho: %s \n\n", rankhijos, &mensaje_padre);
	fflush(stdout);
	MPI_Finalize();
	return 0;
}
