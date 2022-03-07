#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int firttime[100005] = { 0 };
struct Item
{
	int ts, id;
};
bool cmp(Item a, Item b)
{
	return a.ts < b.ts;
}
Item It[100005];
int In[100005];
int main()
{
	int N, M, T, i, j;
	cin >> N >> M >> T;
	
	for (i = 0; i < M; i++)
	{
		cin >> It[i].ts >> It[i].id;
	}
	sort(It, It + M, cmp);
	for (i = 1; i <= T; i++)
	{
		int vis[100005] = { 0 };
		for (j = 0; j < M; j++)
		{
			if (It[j].ts == i)
			{
				firttime[It[j].id] += 2;
				vis[It[j].id] = 1;
				if (firttime[It[j].id] > 5) In[It[j].id] = 1;
			}
		}
		for (j = 1; j <= N; j++)
		{
			if (vis[j] == 0 && firttime[j])
			{
				firttime[j]--;
				if (firttime[j] < 4) In[j] = 0;
			}
		}
	}
	int cnt = 0;
	for (j = 1; j <= N; j++) if (In[j]) cnt++;
	cout << cnt << endl;
	return 0;
}