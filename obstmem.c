#include<stdio.h>
#include<limits.h>

 int sum(int freq[],int n,int m)
  {  
    int s=0;
    for(int i=n;i<=m;i++)
     s=s+freq[i];
     return s;
  }
 int obst[10][10];
 int optimal(int key[],int freq[],int i,int j)
  {
    int min,val;
     if(i>j)
     return obst[i][j]=0;
     if(obst[i][j]!=-1)
       return obst[i][j];
   else
     {
      if(i==j)
      return obst[i][j]=freq[i];
       min=INT_MAX;
     for(int k=i;k<=j;k++)
      {
        val=optimal(key,freq,i,k-1)+optimal(key,freq,k+1,j);
        if(min>val)
         min=val;
      } 
      return obst[i][j]=min+sum(freq,i,j);
      }
  
 }
 
 int main()
  {
    int n;
    printf("enter no of keys : ");
     scanf("%d",&n);
    for(int i=0;i<n;i++)
     { 
      for(int j=0;j<n;j++)  
       obst[i][j]=-1;
     }  
    int freq[n],key[n];
    printf("\nenter keys and respective frequencies : ");
    for(int i=0;i<n;i++)
     scanf("%d%d",&key[i],&freq[i]);
    int min=optimal(key,freq,0,n-1);
    printf("\ncost of optimal binary tree = %d\n",min);
    printf("memorisation table :\n");
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      printf("%d ",obst[i][j]);
       printf("\n");
    }
   
  }
  
  
