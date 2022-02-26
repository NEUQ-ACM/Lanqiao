#include <bits/stdc++.h>
using namespace std;
char mp[30][50];
bool vis[30][50];
int dir[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
char dirc[4]={'D','L','R','U'}; 
int n,m;
struct node{
	int x,y,step;
	string str;
	node(int xx,int yy,int ss,string s){
		x=xx;
		y=yy;
		step=ss;
		str=s;
	}
}; 
queue<node> q;
int check(int x,int y){
	if (x<0 || x>=n || y<0 || y>=m || vis[x][y] || mp[x][y]=='1') return 0;
	return 1;
}
void bfs(int x, int y){
	q.push(node(x,y,0,""));
	vis[x][y]=1;
	while(!q.empty()){
		node now=q.front();
		if(now.x==n-1 && now.y==m-1){
			cout<<now.str<<endl;
			return ;
		}
		q.pop();
		for(int i=0;i<4;i++){
			int nx=now.x+dir[i][0],ny=now.y+dir[i][1];
			if(check(nx,ny)){
				q.push(node(nx,ny,now.step+1,now.str+dirc[i]));
				vis[nx][ny]=1;
			}
		}
	}
} 
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;i<m;j++)
			cin>>mp[i][j];
	bfs(0,0);
	return 0;
}
