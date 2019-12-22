#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main(){
	int mat[100][100],vec[100],res[100],i,j,k,x,y,resp[100];
	for(i=0;i<100;i++)
		for(j=0;j<100;j++){
			mat[i][j]=rand()%1000;
			vec[j]=rand()%100;
		}
	for(i=0;i<100;i++){
		res[i]=0;
		for(j=0;j<100;j++){
			res[i]=res[i]+mat[i][j]*vec[j];
		}
	}
	#pragma omp parallel for num_threads(16) private(j)
	for(i=0;i<100;i++){
		resp[i]=0;
		for(j=0;j<100;j++){
			resp[i]=resp[i]+mat[i][j]*vec[j];
		}
	}
	
		for(j=0;j<100;j++){
			printf("%d ",res[j]);
		}
		printf("\n\n\n\nnow parallel\n");
		for(i=0;i<100;i++)
			printf("%d ",resp[i]);

}