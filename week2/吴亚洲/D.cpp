#include<bits/stdc++.h>
using namespace std;
int mp[9][9];
bool vis[9];
int fa[9];
int ans;
int getfa(int x)
{
	if(x==fa[x])
	return x;
	else
	return getfa(fa[x]);
}
void dfs(int k)
{
	if(k>7)
	{
		for(int i=1;i<=7;i++)
		fa[i]=i;
		for(int i=1;i<=7;i++)
		for(int j=1;j<=7;j++)
		{
			if(mp[i][j]&&vis[i]&&vis[j])
			{
				int x=getfa(i),y=getfa(j);
				if(x!=y)
				fa[x]=y;
			}
		}
		bool ju[9]={};
		int cnt=0;
		for(int i=1;i<=7;i++)
		if(!ju[getfa(i)]&&vis[i])
		{
			cnt++;
			ju[getfa(i)]=1;
		}
		if(cnt==1)
		ans++;
		return ;
	}
	else
	{
		dfs(k+1);
		vis[k]=1;
		dfs(k+1);
		vis[k]=0;
	}
}
int main()
{
	mp[1][2]=1;mp[1][6]=1;
	mp[2][1]=1;mp[2][3]=1;mp[2][7]=1;
	mp[3][2]=1;mp[3][4]=1;mp[3][7]=1;
	mp[4][3]=1;mp[4][5]=1;
	mp[5][4]=1;mp[5][6]=1;mp[5][7]=1;
	mp[6][1]=1;mp[6][5]=1;mp[6][7]=1;
	mp[7][2]=1;mp[7][3]=1;mp[7][5]=1;mp[7][6]=1;
	dfs(1);
	cout<<ans;
	}
