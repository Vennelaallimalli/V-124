#include<stdio.h>
#include<stdlib.h>
int a[10];
int nq(int k,int n){
	int i;
	for(i=1;i<=n;i++){
		if(issafe(k,i)){
			a[k]=i;
			if(k==n){
				for(i=1;i<=n;i++){
					printf("%d\t",a[i]);
				}
				printf("\n");
			}
			else
			nq(k+1,n);
		}
	}
}
int issafe(int k,int i){
	int j;
	for(j=1;j<=k-1;j++){
		
		if(a[j]==i|| abs(a[j]-i)==abs(j-k))
		return 0;
	}
		return 1;
	
}
int main(){
 int n;
 scanf("%d",&n);
 nq(1,n);
}
