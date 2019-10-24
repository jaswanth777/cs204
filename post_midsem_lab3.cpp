#include<bits/stdc++.h>
using namespace std;
int input[1000][1000]={0};
int Count=0;
int Max=0;
bool is_valid(int i,int j,int m,int n)
{
	if(0<=i && i<m && 0<=j && j<m && input[i][j]==1)
		return true;
	else
		return false;
}
void BFS(int i,int j, int m,int n)
{
	Count=Count+1;
	if(is_valid(i,j,m,n))
	{   
	    input[i][j]=0;
		if(is_valid(i-1,j,m,n))
			 BFS(i-1,j,m,n);
		if(is_valid(i,j-1,m,n))
			BFS(i,j-1,m,n);
		if(is_valid(i+1,j,m,n))
			BFS(i+1,j,m,n);
		if(is_valid(i,j+1,m,n))
			BFS(i,j+1,m,n);
	}
}
int main()
{
int m,n;
cin>>m>>n;
int k;
cin>>k;
while(k--)
{
	int x,y;
	cin>>x>>y;
	input[x-1][y-1]=1;
}
for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{	if(Count>Max)
			Max=Count;
			Count=0;
			if(is_valid(i,j,m,n)){BFS(i,j,m,n);}
		}
	}
	cout<<Max;
	return 0;
}