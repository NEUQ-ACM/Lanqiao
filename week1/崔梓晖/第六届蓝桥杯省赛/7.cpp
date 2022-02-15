#include<bits/stdc++.h>
using namespace std;

int N, M, Q;
const int maxM = 2e5;
const int maxN = 5e4 + 5;
int par[maxN];

//定义边 
struct edge {
	int begin, end, cost;
}edges[maxM];

bool cmp(edge x, edge y) {
	return x.cost<y.cost;
}

//并查集
int get_root(int a) {    //求根节点 
	if(par[a] != a) {
		par[a] = get_root(par[a]);
	}
	return par[a];
}

//查询是否在同一集合中 
bool query(int a,int b) {
     return get_root(a) == get_root(b);
}

//合并两个结点 
void merge(int a,int b) {
     par[get_root(a)] = get_root(b);
}

//每次询问都要初始化 
void init() {
	for(int i = 1;i <= N;i++) {
		par[i] = i;
	}
}

int solve(int l, int r, int k, int c) {
	init();
	for(int i = 0;i < M;i++) {
		int begin = edges[i].begin;
		int end = edges[i].end;
		int cost = edges[i].cost;
		
		if(get_root(begin) == get_root(end)) {   //该边的两个结点已经在同一个集合中 
			continue;
		}else {
			merge(begin, end);  //合并加边 
		}
		//每添加一条边都要判断一下已经满足条件，是就退出 
		bool flag = true;
		int parent = 0;
		//检查l到r中模k余c的点是否已经连通 
		for(int i = l;i <= r;i++) {
			if(i % k == c) {
				if(parent == 0) {
					parent = get_root(i);
				}else {
					if(parent != get_root(i)) {   //实际上就是检查这些结点是不是在同一个集合里 
						flag = false;
						break;
					}
				}
			}
		}
		if(flag) {
			cout<<cost<<endl;  //已经在同一个集合，说明已经连通 
			break;
		}
	}
	return 1;
}

int main() {
	cin>>N>>M>>Q;
	for(int i = 0;i < M;i++) {
		cin>>edges[i].begin>>edges[i].end>>edges[i].cost;
	} 
	sort(edges, edges + M, cmp);   //边从小到大排序 
	for(int i = 0;i < Q;i++) {
		int l, r, k, c;
		cin>>l>>r>>k>>c;
		solve(l, r, k, c);
	}
	return 0;
}

