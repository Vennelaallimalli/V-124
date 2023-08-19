#include<stdio.h>

void swap(int a[],int i,int j){
int t=a[i];
a[i]=a[j];
a[j]=t;
}

int min(int a[],int n){
int min=0,i;
for(i=0;i<n;i++){
if(a[i]<a[min])
min=i;

}

return min;
}

int omp(int a[],int n){
int sum=0,i;
while(n>1){
i=min(a,n);
swap(a,i,n-1);
i=min(a,n-1);
swap(a,i,n-2);
sum=sum+a[n-1]+a[n-2];
a[n-2]=a[n-1]+a[n-2];
n=n-1;
}
return sum;
}

int main(){
int n;
printf("enter no. of nodes:");
scanf("%d",&n);
int a[n],i;
printf("enter size of nodes:");
for( i=0;i<n;i++)
scanf("%d",&a[i]);

printf("%d",omp(a,n));


}
