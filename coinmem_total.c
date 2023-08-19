#include<stdio.h>
int dp[50][50];

int coinmem(int a[],int s,int n)
 {
   if(s==0)
     return dp[n][s]=1;
   if(n==0)
     return dp[n][s]=0;
    if(dp[n][s]!=-1)
     return dp[n][s];
   else
   {
    if(a[n-1]<=s)
        return dp[n][s]=coinmem(a,s-a[n-1],n)+coinmem(a,s,n-1);
      else
        return coinmem(a,s,n-1);  
    }
    return dp[n][s];
 }


 int main()
  {
    int n,i,m,j,change;
    printf("enter no of coins\t");
     scanf("%d",&n);
    int a[n];
    printf("enter the amount of change\t");
     scanf("%d",&change);
    printf("enter coin values\t");
    for(i=0;i<n;i++)
     scanf("%d",&a[i]);
    for(i=0;i<=n;i++)
     {
        for(j=0;j<=change;j++)
         dp[i][j]=-1;
     }   
     m=coinmem(a,change,n);  
    printf("total no of ways to get given amount is %d\n",m);
    printf("table\n");
     for(i=0;i<=n;i++)
     {
        for(j=0;j<=change;j++)
        printf("%d\t",dp[i][j]);
        printf("\n");
     }   
    return 0;  
  }
  
  
