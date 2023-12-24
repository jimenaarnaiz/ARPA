// Código del padre

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define hijos 5

int main(int argc, char* argv[]) {
    MPI_Comm intercom, intracom;
    char file[] = "C:\\ASIGNATURAS 3º\\1 SEMESTRE\\Arquitecturas paralelas\\PRACTICAS\\hijo\\x64\\Debug\\hijo.exe";
    char mensaje[] = "Hola hijo, yo soy tu padre";
    int rank;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    MPI_Comm_spawn(file, MPI_ARGV_NULL, hijos, MPI_INFO_NULL, 0, MPI_COMM_WORLD, &intercom, MPI_ERRCODES_IGNORE);

    // CREACION DE INTERCOMUNICADOR
    MPI_Intercomm_merge(intercom, 0, &intracom);

    // ENVIO DE MENSAJE A LOS HIJOS A TRAVEZ DEL INTRACOM
    MPI_Bcast(&mensaje, 27, MPI_CHAR, 0, intracom);

    MPI_Finalize();
    return 0;
}
