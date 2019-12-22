#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<math.h>
double getdist(int x1,int y1,int x2, int y2){
	double d=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
	return d;
}
int main(){
	int a[4][2]={{25,25},{25,75},{75,25},{75,75}};
	int group[4]={0,0,0,0};
	int group2[4]={0,0,0,0};
	int xpoints[100],ypoints[100];
	int i,j,category;
	double mindist=9999.0,dist=9999.0;
	for(i=0;i<100;i++){
		xpoints[i]=rand()%100;
		ypoints[i]=rand()%100;
	}
	for(i=0;i<100;i++){
		mindist=9999.0;
		dist=9999.0;
		for(j=0;j<4;j++){
			dist=getdist(xpoints[i],ypoints[i],a[j][0],a[j][1]);
			if(dist<mindist){
				mindist=dist;
				category=j;

		}
			}
			group[category]++;
			category=-1;
	}
	j=0;
	i=0;
#pragma omp parallel for firstprivate(j) num_threads(10)
for(i=0;i<100;i++){
		mindist=9999.0;
		dist=9999.0;
		#pragma omp critical
		for(j=0;j<4;j++){
			dist=getdist(xpoints[i],ypoints[i],a[j][0],a[j][1]);
			
			if(dist<mindist){
				mindist=dist;
				category=j;

		}
			}
			group2[category]++;
			category=-1;
	}



	for(i=0;i<4;i++)
		printf("%d %d\n",group[i],group2[i]);



}
