#include <bits/stdc++.h>
using namespace std;
int e[10][10],ans=0,use[10],fa[10];
void init()
{
	e[1][2]=e[1][6]=1;
	e[2][1]=e[2][7]=e[2][3]=1;
	e[3][2]=e[3][7]=e[3][4]=1;
	e[4][3]=e[4][5]=1;
	e[5][4]=e[5][7]=e[5][6]=1;
	e[6][1]=e[6][7]=e[6][5]=1;
	e[7][2]=e[7][3]=e[7][5]=e[7][6]=1;
}
int find(int u)
{
	while(fa[u]!=u)
	{
		u=fa[u];
	}
	return u;
}
void dfs(int d)
{
	if(d>7)
	{
		for(int i=1;i<=7;i++){fa[i]=i;}
		for(int i=1;i<=7;i++)
		{
			for(int j=1;j<=7;j++)
			{
				if(e[i][j]&&use[i]&&use[j])
				{
					int fx=find(i);
					int fy=find(j);
					if(fx!=fy){fa[fx]=fy;}
				}
			}
		}
		int k=0;
		for(int i=1;i<=7;i++)
		{
			if(use[i]&&fa[i]==i){k++;}
		}
		if(k==1){ans++;}
		return;
	}
	use[d]=1;
	dfs(d+1);
	use[d]=0;
	dfs(d+1); 
}
int main()
{
	init();
	dfs(1);
	cout<<ans;
}
