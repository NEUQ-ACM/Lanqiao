#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,0};
int map[35][55];
int vis[35][55]={0};
char ch[4]={'D','U','L','R'};
struct Point{
	int x;
	int y;
	string step;
};
queue<Point> que;
int main(){
	Point start;
	vis[0][0]=1;
	start.x=0;start.y=0;start.step="";
	for(int i=0;i<30;i++) for(int j=0;j<50;j++){
		cin >> map[i][j];
	}
	que.push(start);
	bool found=false;
	while(!que.empty()||found){
		Point setup=que.front();
		for(int i=0;i<4;i++){
			Point next;
			next.x=setup.x+dx[i];
			next.y=setup.y+dy[i];
			next.step=setup.step+ch[i];
			if(next.x==29&&next.y==49){
				cout << next.step << endl;
				found=true;
			}
			if(vis[next.x][next.y]==0||next.x<30||next.y<50||map[next.x][next.y]==0){
				que.push(next);
				vis[next.x][next.y]=1;
			}
		}
		que.pop();
	}
}