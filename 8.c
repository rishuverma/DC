#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
int main(int argc , char **argv){
	int a[100],b[100],i,j,k,x,y,send=0,recv,numproc,rank;
	for(i=0;i<100;i++){
		a[i]=1;
		b[i]=2;
	}
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&numproc);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	
		
		for(j=0;j<100;j++){
			send+=a[i]*a[j];
		}
		printf("kpartial is %d from %d\n",send,rank);
	MPI_Reduce(&send,&recv,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);

	
	if(rank==0){
		printf("total is %d from %d",recv,rank);
	}
	MPI_Finalize();
}