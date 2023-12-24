//definimos las librerías
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#define N 5 //se define el tamaño de la matriz

int main(int argc, char* argv[]) {
	int rank, tam, longitud, i, j;
	int tag = 1;
	int matriz[N][N]; //se define la matriz
	//funciones MPI
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &tam);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Status status;
	//matriz superior
	int vector_long_sup[N];
	MPI_Aint vector_despl_sup[N];
	MPI_Datatype vector_tipos[N];
	MPI_Datatype matriz_superior;
	int _long = N, _despl = 0;
// Configuración del tipo de dato MPI para la matriz superior
	for (i = 0; i < N; i++) {
		vector_long_sup[i] = _long;
		vector_despl_sup[i] = _despl;
		_despl = _despl + (N + 1) * sizeof(int);
		_long = _long - 1;
		vector_tipos[i] = MPI_INT;
	}
	MPI_Type_struct(N, vector_long_sup, vector_despl_sup, vector_tipos, &matriz_superior);
	MPI_Type_commit(&matriz_superior);
	//matriz inferior
	int vector_long_inf[N];
	MPI_Aint vector_despl_inf[N];
	MPI_Datatype matriz_inferior;
	_despl = 0;
	// Configuración del tipo de dato MPI para la matriz inferior
	for (i = 0; i < N; i++) {
		vector_despl_inf[i] = _despl;
		_despl = _despl + (N) * sizeof(int);
		vector_long_inf[i] = i + 1;
		vector_tipos[i] = MPI_INT;
	}
	MPI_Type_struct(N, vector_long_inf, vector_despl_inf, vector_tipos, &matriz_inferior);
	MPI_Type_commit(&matriz_inferior);
	//creamos  una matriz de valores nulos para los procesos 1 y 2
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			matriz[i][j] = 0;
		}
	}
	//si el proceso es 0 
	if (rank == 0) { // generamos matriz con num aleatorios 
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				matriz[i][j] = rand() % 10;
			}
		}
		printf("\nMatriz proceso %d:\n", rank); //imprimimos la matriz inicial
		fflush(stdout);
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				printf("%d ", matriz[i][j]);
			}
			printf("\n");
			fflush(stdout);
		}
		// Enviamos la matriz superior al proceso 1 y la matriz inferior al proceso 2
		MPI_Send(&matriz, 1, matriz_superior, 1, tag, MPI_COMM_WORLD);
		MPI_Send(&matriz, 1, matriz_inferior, 2, tag, MPI_COMM_WORLD);
	}
	//si el proceso es 1
	if (rank == 1) { 
		printf("\nMatriz creada por proceso %d:\n", rank); // Imprimimos la matriz triangular superior
		fflush(stdout);
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				printf("%d ", matriz[i][j]);
			}
			printf("\n");
			fflush(stdout);
		}
		//recibimos la matriz diagonal superior del proceso 0
		MPI_Recv(&matriz, 1, matriz_superior, 0, tag, MPI_COMM_WORLD, &status);
		// Imprimimos la matriz recibida
printf("\nMatriz recibida por proceso %d, hecha la diagonal superior:\n", rank);
		fflush(stdout);
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				printf("%d ", matriz[i][j]);
			}
			printf("\n");
			fflush(stdout);
		}
	}
	//si el proceso es el 2
	if (rank == 2) {
		printf("\nMatriz creada por proceso %d:\n", rank); // Imprimimos la matriz triangular inferior
		fflush(stdout);
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				printf("%d ", matriz[i][j]);
			}
			printf("\n");
			fflush(stdout);
		}
		//recibimos matriz diagonal inferior del proceso 0
		MPI_Recv(&matriz, 1, matriz_inferior, 0, tag, MPI_COMM_WORLD, &status);
		// Imprimimos la matriz recibida
printf("\nMatriz recibida por proceso %d, hecha la diagonal inferior:\n", rank);
		fflush(stdout);
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				printf("%d ", matriz[i][j]);
			}
			printf("\n");
			fflush(stdout);
		}
	}
	MPI_Finalize(); //finalize mpi
	return 0;
}
