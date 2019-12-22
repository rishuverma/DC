#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main(){
	int fact1=1,fact2=1,n,i,j;
	scanf("%d",&n);
	#pragma omp parallel for firstprivate(n) num_threads(8)
	for(i=1;i<=n;i++)
		fact1*=i;
	#pragma omp parallel for firstprivate(n,fact2) num_threads(8)
	for(j=1;j<=n;j++)
		fact2*=j;
	printf("without firstprivate=%d\nwith first private=%d\n",fact1,fact2);
}