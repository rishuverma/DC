#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int A[100],B[100],C[100];
void merge(int l,int m,int h){
	int i=l;
	int j=m+1;
	int k=l;
	int y=0;
	int index=0;
	while(i<=m&&j<=h){
		if(A[i]<A[j])
			B[index++]=A[i++];
		else
			B[index++]=A[j++];
	}
	while(i<=m)
		B[index++]=A[i++];
	while(j<=h)
		B[index++]=A[j++];
	for(k=l;k<=h;k++)
		A[k]=B[y++];


}
void mergeserial(int l,int m,int h){
	int i=l;
	int j=m+1;
	int k=l;
	int y=0;
	int index=0;
	while(i<=m&&j<=h){
		if(C[i]<C[j])
			B[index++]=C[i++];
		else
			B[index++]=C[j++];
	}
	while(i<=m)
		B[index++]=C[i++];
	while(j<=h)
		B[index++]=C[j++];
	for(k=l;k<=h;k++)
		C[k]=B[y++];


}
void mergesort(int l,int h){
	if(l<h){
		int m=(l+h)/2;
		#pragma omp parallel sections
		{
			#pragma omp section
		{
			mergesort(l,m);
		}
		#pragma omp section
		{
		mergesort(m+1,h);
	}
	}
		merge(l,m,h);
	}
	else
		return;
}
void mergesortserial(int l,int h){
	if(l<h){
		int m=(l+h)/2;
		#pragma omp parallel sections
		{
			#pragma omp section
		{
			mergesort(l,m);
		}
		#pragma omp section
		{
		mergesort(m+1,h);
	}
	}
		mergeserial(l,m,h);
	}
	else
		return;
}

int main(){
	int i,j,k;
	double t1,t2,t3,t4;
	for(i=0;i<100;i++){
		A[i]=rand()%100;
		C[i]=A[i];
	}
	for(i=0;i<100;i++)
		printf("%d ",A[i]);
	t3=omp_get_wtime();
mergesortserial(0,99);
t4=omp_get_wtime();
t1=omp_get_wtime();
	mergesort(0,99);
t2=omp_get_wtime();

	printf("aftermergesort\n");
	for(i=0;i<100;i++)
		printf("%d ",A[i]);
	printf("serial %lf\n paralle %lf\n",t4-t3,t2-t1);
	


}
