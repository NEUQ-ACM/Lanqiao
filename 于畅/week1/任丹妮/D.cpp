#include <bits/stdc++.h>
using namespace std;
struct pos{
	int x, y;
};
pos pre[50][50];
int Map[30][50];
int d[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
bool vis[30][50]={false};
vector<pos>path;
int r=30,c=50;
void bfs(pos start){
	queue<pos>q;
	q.push(start);
	vis[start.x][start.y]=true;
	pos temp;
	while(!q.empty()){
		pos p=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int dx=d[i][0]+p.x;
			int dy=d[i][1]+p.y;
			if(dx<0||dx>=r||dy>=c||dy<0) continue;
			if(vis[dx][dy]||Map[dx][dy]==1) continue;
			vis[dx][dy]=true;
			pre[dx][dy]=p;
			temp.x=dx;
			temp.y=dy;
			q.push(temp);
			if(dx==r-1&&dy==c-1) break;
		}
	}
}
void dfs(int x,int y){
	pos temp;
	if(x==0&&y==0) {
		temp.x=x;
		temp.y=y;
		path.push_back(temp);
		return;
	}
	dfs(pre[x][y].x,pre[x][y].y);
	temp.x=x;
	temp.y=y;
	path.push_back(temp);
}
void print(){
	for(int i=0;i<path.size()-1;i++){
		pos next=path[i+1];
		if(path[i].x<next.x) cout<<"D";
		else if(path[i].x>next.x) cout<<"U";
		else if(path[i].y>next.y) cout<<"L";
		else if(path[i].y<next.y)cout<<"R";
	}
}
int main(){
	string strs[50];
	for(int i=0; i<r; i++){
		getline(cin,strs[i]);
	}
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			Map[i][j] = strs[i][j]-'0';
		}
	}
	pos start;
	start.x=0;
	start.y=0;
	bfs(start);
	dfs(r-1,c-1);
	cout<<path.size()<<endl;
	print();
	return 0;
}

