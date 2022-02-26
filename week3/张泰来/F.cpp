#include <bits/stdc++.h>
using namespace std;
int now,n,t,pos,maxx = -1;
long long f[25];
int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n; i++)
	{
		if (i == (1 << now)) now++;
		scanf("%d",&t);
		f[now] += t;
	}
	for (int i = 1;i <= now; i++)
	{
		if (f[i] > maxx) 
		{
			maxx = f[i];
			pos = i;
		}
	}
	printf("%d\n",pos);
	return 0;
}
