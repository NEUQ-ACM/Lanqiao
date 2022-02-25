#include<bits/stdc++.h>
#define ll long long
using namespace std;
int fa[10],a[10][10];
bool vis[10];
int ans;
int get(int x)
{
	if(x==fa[x])return x;
	return fa[x]=get(fa[x]);
}
void dfs(int x)
{
	if(x==8)
	{
		for(int i=1;i<=7;i++)fa[i]=i;
		for(int i=1;i<=7;i++)
			for(int j=1;j<=7;j++)
				if(a[i][j] && vis[i] && vis[j])
				fa[get(i)]=get(j);
		int cnt=0;
		for(int i=1;i<=7;i++)
			if(vis[i]&& fa[i]==i)
				cnt++;
		if(cnt==1)ans++;
		return;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
}
int main()
{
	a[1][2]=a[1][6]=a[2][1]=a[2][7]=a[2][3]=a[3][2]=a[3][7]=a[3][4]=a[4][3]=a[4][5]=a[5][7]=a[5][6]=a[5][4]=a[6][5]=a[6][7]=a[6][1]=a[7][6]=a[7][5]=a[7][2]=a[7][3]=1;
	dfs(1);
	cout<<ans;
}
