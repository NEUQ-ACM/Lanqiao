#include <bits/stdc++.h>
using namespace std;
vector <pair<int,int> > v[2825];
int n = 2021;
long long dis[2825];
bool vis[2825];
int gcd(int x,int y)
{
	return y > 0 ? gcd(y,x % y) : x;
}
int lcm(int x,int y)
{
	return x * y / gcd(x,y);
}
void dijkstra(int start)
{
	for (int i = 1;i <= n; i++)
		dis[i] = 1e11;
	dis[start] = 0;
	
	for (int i = 1;i <= n; i++)
	{
		long long minn = 1e12;
		int pos = 0;
		for (int j = 1;j <= n; j++)
		{
			if (vis[j]) continue;
			if (minn > dis[j])
			{
				minn = dis[j];
				pos = j;
			}
		}
		vis[pos] = true;
		for (int j = 0;j < v[pos].size(); j++)
		{
			int next = v[pos][j].first;
			int val = v[pos][j].second;
			if (dis[next] > dis[pos] + val)
			{
				dis[next] = dis[pos] + val;
			}
		}
	}
	return;
}
int main()
{
	for (int i = 1;i <= n; i++)
	{
		for (int j = i + 1;j <= min(i + 21,n); j++)
		{
			int w = lcm(i,j);
			v[i].push_back(make_pair(j,w));
			v[j].push_back(make_pair(i,w));
		}
	}
	dijkstra(1);
	cout << dis[n] << endl;
	return 0;
} 
