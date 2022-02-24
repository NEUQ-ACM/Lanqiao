#include <bits/stdc++.h>
using namespace std;
#define pair <int,int> pii
const int mod=1e9+7;
const int INF=0x3f3f3f3f; 
typedef long long ll;
struct node{
	int x;
	int y;
};
struct pre{
	int x;
	int y;
	int dir;
}p[100][100];
int vis[100][100];
int dirx[4]={1,0,0,-1};
int diry[4]={0,-1,1,0};
string str[100];
queue<node>q;
void dfs(node now){
	if (now.x==0&&now.y==0) return;
	else {
		dfs((node){p[now.x][now.y].x,p[now.x][now.y].y});
		switch(p[now.x][now.y].dir){
			case 0:cout<<"D";break;
			case 1:cout<<"L";break;
			case 2:cout<<"R";break;
			case 3:cout<<"U";break;
		}
	}
}
int step[100][100];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	for (int i=0;i<30;i++)
		cin>>str[i];
	q.push((node){0,0});
	vis[0][0]=1;
	step[0][0]=0;
	while (!q.empty()){
		node now=q.front();
		q.pop();
		if (now.x==29&&now.y==49) break;
		for (int i=0;i<4;i++){
			int xx=now.x+dirx[i];
			int yy=now.y+diry[i];
			if (xx<0||xx>=30||yy<0||yy>=50) continue;
			if (str[xx][yy]=='1'||vis[xx][yy]) continue;
			vis[xx][yy]=1;
			p[xx][yy].x=now.x;
			p[xx][yy].y=now.y;
			p[xx][yy].dir=i;
			q.push((node){xx,yy});
			step[xx][yy]=step[now.x][now.y]+1;
		}
	}
	dfs((node){29,49});
	return 0;
} 
