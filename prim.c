#include<stdio.h>
#include<limits.h>
int a[20][20];
void prims(int n,int a[][n],int visit[]){
int i,j,k,l,sum=0,x,y;
visit[0]=1;
for(l=0;l<n-1;l++){
int min=INT_MAX;
for(i=0;i<n;i++){
if(visit[i]==1){
for(j=0;j<n;j++){
if(visit[j]==-1 && a[i][j]!=-1){
if(min>a[i][j]){
min=a[i][j];
x=i;
y=j;
}
}
}
}
}
sum=sum+min;
printf("\n%d to %d is %d",x,y,min);
visit[y]=1;
}
printf("\n%d",sum);

}

int main(){
int n,i,j;
scanf("%d",&n);

int a[n][n],visit[n];

for(i=0;i<n;i++){
for(j=0;j<n;j++){
scanf("%d",&a[i][j]);
}
}

for(i=0;i<n;i++)
visit[i]=-1;
prims(n,a,visit);


}
