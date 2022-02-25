#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
typedef pair<int,int>PII;
PII order[N];
int s[N],last[N];  //last 重要 储存上次订单时间 
bool vis[N];
int main()
{
	int n, m, t;
	cin >> n >> m >> t;
	for (int i = 1; i <= m; i++)
		cin >> order[i].first >> order[i].second;
	sort(order+1, order+1+m);
	
	for (int i = 1; i <= m; i++)  //遍历订单，而不是遍历时间 
	{
		int ts = order[i].first, id = order[i].second;
		if(ts != last[id]) s[id] -= ts - last[id] - 1;
		s[id] = max(0,s[id]);
		if(s[id] <= 3) vis[id] = 0;
		s[id] += 2;
		if(s[id] > 5) vis[id] = 1;
		last[id] = ts;
	}
	for (int i = 1; i <= n; i++)  //处理最后一秒各个店铺的状态 
	{
		if(last[i] != t)  s[i] -= t - last[i];
		if(s[i] <= 3) vis[i] = 0;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if(vis[i]) ans++;
	cout << ans;
	return 0;
}//参考 https://blog.csdn.net/qq_26139541/article/details/121284273?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164491769216781685391475%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=164491769216781685391475&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-8-121284273.first_rank_v2_pc_rank_v29&utm_term=%E5%A4%96%E5%8D%96%E5%BA%97%E4%BC%98%E5%85%88%E7%BA%A7&spm=1018.2226.3001.4187 
