#include<iostream>
using namespace std;

const int N=8;
int map[N][N],fa[N],vis[N],ans;

int getfa(int i)									
{
	if(fa[i]==i)
		return i;
	return fa[i]=getfa(fa[i]);						

void dfs(int k)
{
	if(k>7)										
	{
		for(int i=1;i<=7;i++)							
			fa[i]=i;
		for(int i=1;i<=7;i++)
			for(int j=1;j<=7;j++)
			{
				if(map[i][j]&&vis[i]&&vis[j])		
				{
					int faa=getfa(i),fab=getfa(j);
					if(faa!=fab)
						fa[faa]=fab;
				}
			}
		int cnt=0;
		for(int i=1;i<=7;i++)						
				cnt++;
		if(cnt==1)									
			ans++;							
		return;
	}
	vis[k]=1;										
	dfs(k+1);
	vis[k]=0;											
	dfs(k+1);
}

int main()
{
	map[1][2]=map[2][1]=1;map[1][6]=map[6][1]=1;	
	map[6][7]=map[7][6]=1;map[6][5]=map[5][6]=1;
	map[2][7]=map[7][2]=1;map[2][3]=map[3][2]=1;
	map[5][7]=map[7][5]=1;map[5][4]=map[4][5]=1;
	map[3][7]=map[7][3]=1;map[4][3]=map[3][4]=1;
	dfs(1);
	cout<<ans;
	return 0;
}

