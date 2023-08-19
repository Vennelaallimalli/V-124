#include<stdio.h>
int a[20][20];
int max(int a,int b){
	if(a>b)
 return a;
	else
 return b;
}
int ks(int val[],int wt[],int w,int n){
	if(n==0 || w==0)
	return a[n][w]=0;
 if(a[n][w]!=-1)
 return a[n][w];
 if(wt[n-1]<=w){
    return	a[n][w]= max(val[n-1]+ks(val,wt,w-wt[n-1],n-1),ks(val,wt,w,n-1));
 }
	else
return a[n][w]	= ks(val,wt,w,n-1);
}
int main(){
	int m,n;
	printf("enter the no of weights:");
	scanf("%d",&m);
	printf("enter the no of values:");
	scanf("%d",&n);
	int wt[n];
	int val[m];
	int i,j,w;
	printf("enter the weight of the knapstack bag:");
	scanf("%d",&w);
	printf("enter the weights in array:");
	for(i=0;i<n;i++){
		scanf("%d",&wt[i]);
	}
	printf("enter the values in array:");
		for(i=0;i<m;i++){
		scanf("%d",&val[i]);
	}
	for(i=0;i<n+1;i++)
	{
	for(j=0;j<w+1;j++)
	{
		a[i][j]=-1;
	}
	}
   j=ks(val,wt,w,n);
   printf("max val:%d",j);	
}

