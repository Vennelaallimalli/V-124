#include<stdio.h>          
#include<stdbool.h>
int dp[50][50];
int ssm(int a[],int n,int sum)
{
  if(n==0)
    {
      return dp[n][sum]=false;
    }
  else if(sum==0)
    {
      return dp[n][sum]=true;
    }  
   else if(dp[n][sum]!=-1)
    {
       return dp[n][sum];
    } 
  else 
  {
    if(sum>=a[n-1])
     {
      return dp[n][sum]=ssm(a,n-1,sum-a[n-1]) || ssm(a,n-1,sum);
     }  
    else
     {
      return dp[n][sum]=ssm(a,n-1,sum);
     }
   }  
   
  return dp[n][sum];
}
 int main()
{
  int sum=0,n,j,i,ss;
   printf("enter n value\t");
     scanf("%d",&n);
   int a[n];
   printf("enter set elements");
    for(i=0;i<n;i++)
   scanf("%d",&a[i]);
    for(i=0;i<n;i++)
       sum=sum+a[i];
   
    for(i=0;i<=n;i++)
     {
         for(j=0;j<=(sum/2);j++)
           dp[i][j]=-1;
     }
   if(sum%2!=0)
     printf("FALSE equal partition is cant be done\n");
   else
   {  
       ss=ssm(a,n,sum/2);
      if(ss==true)
        printf("\n\tTRUE:equal partition can be done\n");
      else
       printf("\n\tFALSE:equal partition is cant be done\n");
     }  
     return 0;
}

