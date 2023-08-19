m#include<stdio.h>
#define INT_MAX 99999
int arr[100][100];
int MCM(int dp[100][100],int a[],int i,int j,int n)
{

int min,l,val,k;
for(l=0;l<n;l++)
{
	for(i=1;i<n-l;i++)
	{
		
		
		j=i+l;
	}

		if(i==j)
		{
			dp[i][j]=0;
			continue;
		}
		min=INT_MAX;
		for(k=i;k<j;k++)
		{
			val=dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j];
			if(val<min)
			min=val;
		
	
}
}
dp[i][j]=min;
	
}




int main()
{
	int n,i,j,x;
	printf("enter the size ");
	scanf("%d",&n);
	printf("enter elements");
	int a[100];
	int dp[100][100];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
		for( i=0;i<n;i++)
	{
		for( j=i;j<n;j++)
		{
		
			arr[i][j]=-1;
		}
		
	}
	x=MCM(dp,a,0,n-1,n);
	printf("%d is the min val",x);
}
