#include<bits/stdc++.h>
using namespace std;
int mx[]={-1,0,0,1};
int my[]={0,1,-1,0};
int v[4][4];
int ans=0;
void dfs(int st,int x,int y)
{
	if(st==16){ans++;return;}
	for(int i=0;i<4;i++)
	{
		int tx=x+mx[i];
		int ty=y+my[i];
		if(v[tx][ty]==1||tx<0||ty<0||tx>3||ty>3){continue;}
		v[tx][ty]=1;
		dfs(st+1,tx,ty);
		v[tx][ty]=0;
	}
	return;
}
int main()
{
	
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			v[i][j]=1;
			dfs(1,i,j);
			v[i][j]=0;
		}
	}
	printf("%d",ans);
} 
