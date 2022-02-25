#include <bits/stdc++.h>
using namespace std;
vector <int> v[100005];
int n,m,t,ts,id,ans;
int main()
{
	scanf("%d%d%d",&n,&m,&t);
	for (int i = 1;i <= m; i++)
	{
		scanf("%d%d",&ts,&id);
		v[id].push_back(ts);
	}
	for (int i = 1;i <= n; i++)
	{
		sort(v[i].begin(),v[i].end());
	}
	for (int i = 1;i <= n; i++)
	{
		int last = 0,rank = 0;
		bool flag = false;
		for (int j = 0;j < v[i].size(); j++)
		{
			int k = v[i][j];
			if (last < k) rank -= k - last - 1;
			rank = max(rank,0);
			if (rank <= 3 && flag) flag = false;
			last = k;
			rank += 2;
			if (rank > 5 && (!flag)) flag = true;
		}
		rank -= t - last;
		rank = max(rank,0);
		if (rank <= 3 && flag) flag = false;
		if (flag)	ans++;
	}
	printf("%d\n",ans);
	return 0;
}

