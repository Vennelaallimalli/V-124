#include<stdio.h>
#include<limits.h>


int fp(int parent[],int i){
while(parent[i]!=-1)
i=parent[i];
return i;
}

int f_min(int a[][5],int visit[],int *u,int *v,int n){
int i,j,min=INT_MAX;
for(i=0;i<n;i++){
for(j=0;j<n;j++){
if(a[i][j]!=-1 && min>a[i][j]){
min=a[i][j];
*u=i;
*v=j;
}
}
}
return min;
}

void krus(int a[][5],int visit[],int parent[],int n){

int c=0,sum=0,min,u,v,pu,pv;
while(c<n-1){
min=f_min(a,visit,&u,&v,n);
pu=fp(parent,u);
pv=fp(parent,v);
if(pu!=pv){
parent[pv]=pu;
c++;
sum=sum+min;

printf("min=%d\n",min);
}
a[u][v]=-1;
a[v][u]=-1;
}
printf("%d",sum);
}

int main(){
int n,i,j;
scanf("%d",&n);

int visit[n],parent[n];
for(i=0;i<n;i++)
visit[i]=-1;

for(i=0;i<n;i++)
parent[i]=-1;

int a[n][n];
for(i=0;i<n;i++){
for(j=0;j<n;j++){
scanf("%d",&a[i][j]);
}
}
//printf("n");


krus(a,visit,parent,n);
}
