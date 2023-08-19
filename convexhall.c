#include<stdio.h>
#include<stdlib.h>
struct point{
	int x,y;
};
int main(){
	struct point p[20];
	int n,i,np,nn,a,b,c,d,k,j;
	printf("enter the size of array");
	scanf("%d",&n);
	if(n<=2){
		printf("the points cannot form convexhall");
	}
	else{	
	   printf("enter the elements of array");
	   for(i=0;i<n;i++){
	      scanf("%d%d",&p[i].x,&p[i].y);}
		for(i=0;i<n-1;i++){
			for(j=i+1;j<n;j++){
				a=p[i].y-p[j].y;
				b=p[j].x-p[i].x;
				c=(p[j].y*p[i].x)-(p[i].y*p[j].x);
				np=0,nn=0;
				for(k=0;k<n;k++){
					if(k==i|| k==j){
						continue;
					}
					else{
						d=a*p[k].x+b*p[k].y+c;
					if(d>0){
					 np++;}
					 else{
					 	nn++;
					 }	 
				}
			}
					if(np==0||nn==0){
				printf("(%d,%d) and (%d,%d) forms convexhall\n",p[i].x,p[i].y,p[j].x,p[j].y);
			}
			}
			}
		}
	}



