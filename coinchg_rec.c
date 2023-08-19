# include<stdio.h>
int cc(int wt[],int n,int w)
{
	if(n==0)
	return 0;
	if(w==0)
	return 1;
	if(wt[n-1]<=w)
	{
		return cc(wt,n,w-wt[n-1])+cc(wt,n-1,w);
	}
	else
	return cc(wt,n-1,w);
}

int main()
{
	int n,w,i,k;
	printf("enter size");
	scanf("%d",&n);
	printf("enter weight");
	scanf("%d",&w);
	int wt[n];
	printf("enter vals");
	for(i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	k=cc(wt,n,w);
	printf("%d",k);
}
