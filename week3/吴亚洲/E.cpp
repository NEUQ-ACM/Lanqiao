#include<bits/stdc++.h>
using namespace std;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool vis[5][5];
long long ans;
void dfs(int x,int y,int cnt)
{
	if(cnt==16)
	{
		ans++;
		return ;
	}
	
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(!vis[nx][ny]&&nx>=1&&nx<=4&&ny>=1&&ny<=4)
		{
			vis[nx][ny]=1;
			dfs(nx,ny,cnt+1);
			vis[nx][ny]=0;
		}
	}
}
int main()
{
	for(int i=1;i<=4;i++)
	for(int j=1;j<=4;j++)
	{
		vis[i][j]=1;
		dfs(i,j,1);
		vis[i][j]=0;
	}
	cout<<ans;
}
