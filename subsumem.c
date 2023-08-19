#include<stdio.h>
#include<stdbool.h>                    //subset sum true or false memorisation
int a[100][100];

int subsetsum(int ss[],int n,int sum)
{
   if(sum==0)
     return a[n][sum]=true;
     
   if(n==0)
     return a[n][sum]=false;
     
   if(a[n][sum]!=-1)
     return a[n][sum];
     
   if(ss[n-1]<=sum)
      return a[n][sum]=subsetsum(ss,n-1,sum-ss[n-1]) || subsetsum(ss,n-1,sum);
      
   else
     return a[n][sum]= subsetsum(ss,n-1,sum);
    
}


 int main()
 {
   int n,i,j,m,s;
     printf("enter n value \n");
       scanf("%d",&n);
   int ss[n];
     printf("\nenter required sum\n");
       scanf("%d",&m);
    for(i=0;i<=n;i++)
    { 
       for(j=0;j<=m;j++) 
        a[i][j]=-1;
    }
   
    printf("\nenter values\n");
   for(i=0;i<n;i++)
     {
       scanf("%d",&ss[i]);
     } 
   s=subsetsum(ss,n,m);
   
   if(s==false)
     printf("\n\tFALSE\n");
   else
     printf("\n\tTRUE\n");
   printf("memorisation table\n");  
   for(i=0;i<=n;i++)
    { 
       for(j=0;j<=m;j++) 
          printf("%d\t",a[i][j]);
       printf("\n");
    }
 }
 
 
