#include <bits/stdc++.h>
using namespace std;
int n,t;
int fa[1000005];
int find(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void unionn(int x,int y)
{
	int a = find(x);
	int b = find(y);
	if (a == b) return;
	fa[a] = b;
	return;
}
int main()
{
	for (int i = 1;i <= 1e5; i++)
		fa[i] = i;
	scanf("%d",&n);
	for (int i = 1;i <= n; i++)
	{
		scanf("%d",&t);
		int ans = find(t);
		printf("%d%c",ans," \n"[i == n]);
		unionn(ans,ans + 1);
	}
	return 0;
}
