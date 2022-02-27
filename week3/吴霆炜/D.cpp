#include<bits/stdc++.h>
using namespace std;
char maps[501][501];
int vis[500][500];
char dic[4]={'D','L','R','U'};
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
struct yep{
	int x,y;
	int step;
	string path;
};
int x1,x2,y1,y2,n,m;
void bfs(){
	queue<yep>q;
	yep p;
	p.x=x1;
	p.y=y1;
	p.step=0;
	p.path="";
	vis[x1][y1]=1;
	q.push(p);
	while(!q.empty()){
		yep p=q.front();
		if(p.x==x2&&p.y==y2){
			cout<<p.step<<endl;
			cout<<p.path;
		}
		yep v;
		for(int i=0;i<4;i++){
			v.x=p.x+dir[i][0];
			v.y=p.y+dir[i][1];
			if(v.x>=0&&v.y>=0&&v.x<n&&v.y<m&&vis[v.x][v.y]==0&&maps[v.x][v.y]!='1'){
				vis[v.x][v.y]=1;
				v.step=p.step+1;
				v.path=p.path+dic[i];
				q.push(v);
			}
		}
		q.pop();
	}
}
int main(){
	n=30,m=50;
	memset(maps,'1',sizeof(maps));
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>maps[i][j];
		}
	}
	x1=0;
	y1=0;
	x2=n-1;
	y2=m-1;
	bfs();
	return 0;
}