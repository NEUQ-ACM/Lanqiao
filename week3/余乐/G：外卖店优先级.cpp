#include <queue>
#include <cstdio>
using namespace std;
int n, m, t, ans;
priority_queue<int, vector<int>, greater<int> > q[100001];
int main(){
	scanf("%d%d%d", &n, &m, &t);
	for(int i = 1;i <= m;i ++){
		int a, b;
		scanf("%d%d", &a, &b);
		q[b].push(a);
	}
	for(int i = 1;i <= n;i ++)
		if(!q[i].empty()){
			int ls = q[i].top(), tot = 0, pd = 0;
			while(!q[i].empty()){
				int x = q[i].top();
				q[i].pop();
				if(ls != x) tot -= x - ls - 1;
				tot = max(0, tot);
				if(tot <= 3) pd = 0;
				tot += 2;
				if(tot > 5) pd = 1;
				ls = x;
			}
			if(ls != t) tot -= t - ls;
			if(tot <= 3) pd = 0;
			if(pd) ans ++;
		}
	printf("%d", ans);
	return 0;
}
