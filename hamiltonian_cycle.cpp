#include<bits/stdc++.h>
using namespace std;
int A[100][100];
bool is_safe(int *a,int index,int val,int n)
{
	if(index==n-1)
	{
		for(int i=0;i<index;i++)
		{
			if(a[i]==val || A[a[index-1]][val]==0 || A[val][a[0]]==0 )
				return false;
		}
	}
	for(int i=0;i<index;i++)
	{
		if(a[i]==val || A[a[index-1]][val]==0)  
			return false;
	}
	return true;
}
void display(int *a,int n)
{
	for(int i=0;i<=n;i++)
		cout<<a[i]<<"  ";
	cout<<endl;
}
void hamiltonian(int *a,int index,int n)
{
	if(index==n)
	{
		a[n]=a[0];
		display(a,n);
		return;
	}
	for(int i=1;i<n;i++)
	{
		if(is_safe(a,index,i,n))
		{
			a[index]=i;
			hamiltonian(a,index+1,n);
		}
	}
}
int main()
{
	int n;
	cout<<"enter number of nodes : ";
	cin>>n;
	cout<<"enter the edges in adjancy matrix : "<<endl;
	//int A[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>A[i][j];		
		}		
	}
	int a[n+1];
	a[0]=0;
	hamiltonian(a,1,n);
}
