#include<stdio.h>
#define INT_MAX 99999
int arr[100][100];
int MCM(int a[],int i,int j)
{
	int min,val,k;
	if(i==j)
	{
		return arr[i][j]=0;
	}
	if(arr[i][j]!=-1)
return arr[i][j];
else{
	min=INT_MAX;
	for(k=i;k<j;k++)
	{
	   val=MCM(a,i,k)+MCM(a,k+1,j)+a[i-1]*a[k]*a[j];
		if(min>val)
		min=val;
	}
	return arr[i][j]= min;
}
}
int main()
{
	int n,i,j,x;
	printf("enter the size ");
	scanf("%d",&n);
	printf("enter elements");
	int a[100];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
		for( i=0;i<n;i++)
	{
		for( j=0;j<n;j++)
		{
		
			arr[i][j]=-1;
		}
		
	}
	x=MCM(a,1,n-1);
	printf("%d is the min val",x);
}
