#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
#include<math.h>
int main(int argc, char **argv){
	int rank,numproc,i,j,k;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&numproc);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	int a=0,b=100,c=1;
	for(i=a+rank;i<b;i+=numproc){
		if(cos(i*M_PI)==c)
			printf("cos(%dpi) is 1 in radians=%lf\n",i,(double)i*M_PI);
	}
	//printf("%lf",cos((7*M_PI)/2));
	MPI_Finalize();
}