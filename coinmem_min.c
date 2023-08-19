#include<stdio.h>
#include<limits.h>
#define MAX 50
int dp[50][50];
int min(int a,int b)
 {
   if(a<b)
     return a;
   else
     return b;  
 }
 
 int coinc(int a[],int sum,int n)
  {
    if(sum==0)
      return dp[n][sum]=0;
    else if(n==0)
     return dp[n][sum]=MAX;
    else if(dp[n][sum]!=-1)
      return dp[n][sum]; 
    else if(n==1)
      {
         if(sum%a[n-1]==0)
           return dp[n][sum]=sum/a[n-1];
         else
           return dp[n][sum]=MAX;  
      }   
    else
    {
     if(a[n-1]<=sum)
       return dp[n][sum]=min(1+coinc(a,sum-a[n-1],n),coinc(a,sum,n-1));
    else
     return dp[n][sum]=coinc(a,sum,n-1);  
   }     
   return dp[n][sum]; 
  }
  
  int main()
   {
     int n,i,sum,k;
     printf("enter no of coins\t");
      scanf("%d",&n);
     printf("enter total sum\t");
      scanf("%d",&sum);
     int a[n];
     printf("enter coins values\t");
     for(i=0;i<n;i++)
      scanf("%d",&a[i]);
     for(int i=0;i<=n;i++)
      {
        for(int j=0;j<=sum;j++)
          dp[i][j]=-1;
      } 
     k=coinc(a,sum,n) ;
     printf("min no of coins : %d\n",k);  
     printf("memorisation table\n");
      for(int i=0;i<=n;i++)
      {
        for(int j=0;j<=sum;j++)
          printf("%d\t",dp[i][j]);
        printf("\n");  
      } 
   }
  
  
