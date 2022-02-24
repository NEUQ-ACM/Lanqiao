#include <queue>
#include <cstdio>
#define N 2022 
#define Max 0x7fffffff
using namespace std;

int D[N], u[N];

int head[N], p; 
struct ss{
	int to, ls, dis;
}q[N * N];
void add(int a, int b, int c){q[++ p] = (ss){b, head[a], c};head[a] = p;}

struct s{
	int id, dis;
	bool operator < (const s &r) const{return r.dis < dis;}
};

int lcm(int a, int b){
	int pro = a * b;
	while(1){
		if(a < b){
			int c = a;
			a = b;
			b = c;
		}
		a -= b;
		if(!a) break;
	}
	return pro / b;
}

void dijkstra(){
	for(int i = 2;i <= 2021;i ++)
		D[i] = Max;
	priority_queue<s> que;
	que.push((s){1, 0});
	while(!que.empty()){
		s now = que.top();
		que.pop();
		int x = now.id;
		if(u[x]) continue;
		u[x] = 1;
		for(int i = head[x];i;i = q[i].ls){
			int to = q[i].to;
			int dis = q[i].dis;
			if(D[to] > D[x] + dis && !u[to]){
				D[to] = D[x] + dis;
				que.push((s){to, D[to]});
			}
		}
	}
	printf("%d", D[2021]);
}

int main(){
	for(int i = 1;i < 2021;i ++)
		for(int j = i + 1;j <= 2021;j ++)
			if(j - i <= 21){
				int d = lcm(i, j);
				add(i, j, d);
				add(j, i, d);
			}
	dijkstra();
	return 0;
} 
