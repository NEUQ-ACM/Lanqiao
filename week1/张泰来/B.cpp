#include <bits/stdc++.h>
using namespace std;
map <pair<double,double>,bool>vis;
int n = 20,m = 21,ans;
int main()
{
	for (int i = 0;i < n; i++)
	{
		for (int j = 0;j < m; j++)
		{
			for (int a = 0;a < n; a++)
			{
				for (int b = 0;b < m; b++)
				{
					if (i == a)
					{
						if (!vis[make_pair(1e9,i)])
						{
							ans++;
							vis[make_pair(1e9,i)] = true;
						}
						
					} else {
						double k1 = (j - b) * 1.0 / (i - a);
						double b1 = (a * j - i * b) * 1.0 / (a - i);
						if (!vis[make_pair(k1,b1)])
						{
							ans++;
							vis[make_pair(k1,b1)] = true;
						}
					}
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
