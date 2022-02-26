#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#define ll long long
using namespace std;
int m,n;
char map[60][60];
bool vis[60][60];
int dir[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
char dirc[4]={'D','L','R','U'};
struct node
{
	int x,y,step;
	string str;
	node(int xx,int yy,int ss,string s)
	{
		x=xx;y=yy;step=ss;str=s;
	}
};
bool check(int x,int y)
{
	if(x<0 || x>=m || y<0 || y>=n || vis[x][y] || map[x][y]=='1')
		return false;
	return true;
}
queue<node> q;
void bfs(int x,int y)
{
	q.push(node(0,0,0,""));
	vis[0][0]=true;
	while(!q.empty())
	{
		node now=q.front();
		if(now.x==m-1 && now.y==n-1)
		{
			cout<<now.str<<endl;
			break;
		}
		q.pop();
		for(int i=0;i<4;i++)
		{
			int xx=now.x+dir[i][0];
			int yy=now.y+dir[i][1];
			if(check(xx,yy))
			{
				 q.push(node(xx, yy, now.step+1, now.str+dirc[i]));
				 vis[xx][yy]=true;
			}
		}
	}
}
int main()
{
	cin>>m>>n;
	for(int i=0;i<m;i++)
		scanf("%s",map[i]);
	bfs(0,0);
	return 0;
}
