#include<stdio.h>
void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}



void sort(int wt[],int val[],int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			int v1=(float)val[j]/wt[j];
			int v2=(float)val[j+1]/wt[j+1];
			if(v1<v2){
			 swap(&val[j],&val[j+1]);
			 swap(&wt[j],&wt[j+1]);
		}
	}
}
}

int fk(int wt[],int val[],int W,int i,int n){
	if(n==0||W==0)
	 return 0;
	if(wt[i]<=W){
		int value=val[i]+fk(wt,val,W-wt[i],i+1,n);
		return value;
		
	}
	else
	  return (val[i]/wt[i])*W;
}
int main(){
	int i,n,W;
	printf("enter size:");
	scanf("%d",&n);
	printf("enter bag weight:");
	scanf("%d",&W);
	int wt[n],val[n];
	printf("enter weights:");
	for(i=0;i<n;i++)
	scanf("%d",&wt[i]);
	printf("enter values:");
	for(i=0;i<n;i++)
	scanf("%d",&val[i]);
	sort(wt,val,n);
	printf("after sorting:");
	printf("weights:");
	for(i=0;i<n;i++)
	printf("%d\t",wt[i]);
	printf("values:");
	for(i=0;i<n;i++)
	printf("%d\t",val[i]);
	int k=fk(wt,val,W,0,n);
	printf("max val:%d",k);
return 0;
	
}
