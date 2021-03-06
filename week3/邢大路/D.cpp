#include<iostream>
using namespace std;

const int N=8;
int map[N][N],fa[N],vis[N],ans;

int getfa(int i)										//寻找根节点 
{
	if(fa[i]==i)
		return i;
	return fa[i]=getfa(fa[i]);							//压缩路径 
}

void dfs(int k)
{
	if(k>7)												//7个灯都枚举完了 
	{
		for(int i=1;i<=7;i++)							//先把自己设为自己的父节点 
			fa[i]=i;
		for(int i=1;i<=7;i++)
			for(int j=1;j<=7;j++)
			{
				if(map[i][j]&&vis[i]&&vis[j])			//将连通且亮着的灯，并在一块 
				{
					int faa=getfa(i),fab=getfa(j);
					if(faa!=fab)
						fa[faa]=fab;
				}
			}
		int cnt=0;
		for(int i=1;i<=7;i++)							//有几个根节点说明有几个集合 
			if(fa[i]==i&&vis[i])						//亮着的灯的集合数 
				cnt++;
		if(cnt==1)										//都连通的话，只有一个集合 
			ans++;							
		return;
	}
	vis[k]=1;											//k灯亮  dfs中k+1亮和灭 
	dfs(k+1);
	vis[k]=0;											//k灯灭 
	dfs(k+1);
}

int main()
{
	map[1][2]=map[2][1]=1;map[1][6]=map[6][1]=1;	//连通的存图 
	map[6][7]=map[7][6]=1;map[6][5]=map[5][6]=1;
	map[2][7]=map[7][2]=1;map[2][3]=map[3][2]=1;
	map[5][7]=map[7][5]=1;map[5][4]=map[4][5]=1;
	map[3][7]=map[7][3]=1;map[4][3]=map[3][4]=1;
	dfs(1);
	cout<<ans;
	return 0;
}

