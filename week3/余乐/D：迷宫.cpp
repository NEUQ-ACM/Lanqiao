#include <queue>
#include <cstdio>
#include <iostream>
#define Max 0x7fffffff
using namespace std;

int dis[31][51], u[31][51], p[31][51], ans[10001], t;
char map[31][51];
int th[] = {1, 0, 0, -1};
int tl[] = {0, -1, 1, 0};

struct ss{
	int h, l, d, T;
	bool operator < (const ss &r) const {if(r.d == d) return r.T < T;return r.d < d;}
};

void dijkstra(){
	for(int i = 1;i <= 30;i ++)
		for(int j = 1;j <= 50;j ++)
			dis[i][j] = Max;
	dis[1][1] = 0;
	priority_queue<ss> q;
	q.push((ss){1, 1, 0, 0});
	while(!q.empty()){
		ss now = q.top();
		q.pop();
		int h = now.h;
		int l = now.l;
		if(u[h][l]) continue;
		u[h][l] = 1;
		for(int i = 0;i < 4;i ++){
			int nh = h + th[i];
			int nl = l + tl[i];
			if(nh < 1 || nl < 1 || nh > 30 || nl > 50 || map[nh][nl] == '1') continue; 
			if(dis[nh][nl] > dis[h][l] + 1 && !u[nh][nl]){
				dis[nh][nl] = dis[h][l] + 1;
				p[nh][nl] = i;
				q.push((ss){nh, nl, dis[nh][nl], i});
			}
		}
	}
	int h = 30, l = 50;
	while(1){
		if(h == 1 && l == 1) break;
		int x = p[h][l];
		ans[++ t] = x;
		h -= th[x];
		l -= tl[x];
	}
	for(int i = t;i >= 1;i --){
		if(ans[i] == 0) printf("D");
		if(ans[i] == 1) printf("L");
		if(ans[i] == 2) printf("R");
		if(ans[i] == 3) printf("U");
	}
}
int main(){
	for(int i = 1;i <= 30;i ++)
		for(int j = 1;j <= 50;j ++)
			cin >> map[i][j];
	dijkstra();
	return 0;
}
