#include<gd.h>
#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *fo,*fc;
	int h,w,i,j,c,r,g,b,k;
	fo=fopen("input.png","r");
	gdImagePtr img;
	img=gdImageCreateFromPng(fo);
	w=gdImageSY(img);
	h=gdImageSX(img);
	#pragma omp parallel for private(c,j,r,g,b) num_threads(8)
	for(i=0;i<w;i++){
		#pragma omp critical
		{
		for(j=0;j<h;j++){
			c=gdImageGetPixel(img,i,j);
			r=gdImageRed(img,c);
			g=gdImageGreen(img,c);
			b=gdImageBlue(img,c);
			k=(r+g+b)/3;
			r=k,g=k,b=k;
			c=gdImageColorAllocate(img,r,g,b);
			gdImageSetPixel(img,i,j,c);
		}
	}
}
	fc=fopen("output.png","w");
	gdImagePng(img,fc);
	fclose(fc);
	gdImageDestroy(img);

}