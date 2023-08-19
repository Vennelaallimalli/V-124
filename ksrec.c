//knapsack recursion
#include<stdio.h>
int max(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}
int knapsack(int wt[],int val[],int W,int n)
{
 if(n==0 || val==0)
  return 0;
if(wt[n-1]<=W)
{
	return max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));
}
else
  return knapsack(wt,val,W,n-1);
}

void main()
{
  int n,W,i;
  printf("Enter wt of knapsack:");
  scanf("%d",&W);
  printf("Size:");
  scanf("%d",&n);
  int wt[n],val[n];
  printf("enter wt array elements:");
  for(i=0;i<n;i++)
  {
   scanf("%d",&wt[i]);
  }
  printf("Enter value array:");
  for(i=0;i<n;i++)
  {
  scanf("%d",&val[i]);
  }
  int k=knapsack(wt,val,W,n);
  printf("max value=%d",k);  
}
