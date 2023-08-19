#include<stdio.h>
void print(int a[],int n,int wt[],int tsum){
  int sum=0,i;
  for(i=0;i<n;i++){
    if(a[i]==1){
    sum=sum+wt[i];
    }
   }
   if(sum==tsum){
     for(i=0;i<n;i++){
       if(a[i]==1)
         printf("%d",wt[i]);
      }
   }
}

void ss(int a[],int k,int n,int wt[],int tsum){
  if(k==n){
    print(a,n,wt,tsum);
    printf(" ");
    return;
  }
  int i;
  for(i=0;i<2;i++){
      a[k]=i;
      ss(a,k+1,n,wt,tsum);
  }
}

int main(){
 int n,i,tsum;
 scanf("%d",&n);
 int a[n],wt[n];
 printf("enter weights");
 for(i=0;i<n;i++){
  scanf("%d",&wt[i]);
 }
 for(i=0;i<n;i++){
 a[i]=0;
 }
 printf("enter total sum:");
 scanf("%d",&tsum);
 ss(a,0,n,wt,tsum);
 }

 

