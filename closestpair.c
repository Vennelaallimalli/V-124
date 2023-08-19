#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<float.h>
#include<limits.h>
struct point
{
 int x,y;
};
int k;

float bruteforce(struct point p[],int st,int end)
 {
   float min=99999,dist;
   int  n,i,j;
   
 for(i=st;i<end;i++)
 {
 	for(j=i+1;j<end;j++){
    dist=sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
     if(dist<min)
      min=dist;
  
   }
 
  // return p[i].x,p[i].y,p[j].x,p[j].y;
}
 return min;
}

float closestpair(struct point p[],int st,int end)
{
 int k=0,i;
 struct point strip[100];
 if((end-st)<3)
 {
  return bruteforce(p,st,end);
 }
 else
 {
  int mid=(st+end)/2;
  float dl=closestpair(p,st,mid);
  float dr=closestpair(p,mid+1,end);
  float l=dl>dr?dr:dl;
 for( i=st;i<end;i++)
 {
  if(p[i].x>=p[i].x-l && p[i].x<=p[i].x+l)
   strip[k++]=p[i];
 }
 float d=bruteforce(strip,0,k);
 return d>l?l:d;
}
}
void sort(struct point p[],int n)
{
	int i,j;
 for( i=0;i<n-1;i++)
 {
  for(j=0;j<n-i-1;j++)
  {
   if(p[j].x>p[j+1].x)
   {
    struct point temp;
     temp=p[j];
     p[j]=p[j+1];
     p[j+1]=temp;
   }
  }
 }
}

void main()
{
 struct point p[100];
 int n,i;
 printf("Enter no of coordinates\n");
 scanf("%d",&n);
 printf("enter coordinates\n");
 for(i=0;i<n;i++)
 {
  scanf("%d %d",&p[i].x,&p[i].y);
 }
 sort(p,n);
 float k=closestpair(p,0,n);
 printf("min dist is %f",k);
}

