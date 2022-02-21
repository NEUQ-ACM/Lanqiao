#include <bits/stdc++.h>
using namespace std;
struct node {
	int x,y;
}p[15]; 
int ans;
int fa[8];
bool vis[8];
int lowbits(int x)
{
	return x & (-x);
}
int find(int x)
{
	if (x == fa[x]) return x;
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
bool check(int x)
{
	int cnt = 0;
	memset(vis,0,sizeof(vis));
	for (int i = 1;i <= 7; i++)
		fa[i] = i;
	for (int i = x;i;i -= lowbits(i))
	{
		int t = log2(lowbits(i)) + 1;
		vis[t] = true;
		
	}
	for (int i = 1;i <= 10; i++)
	{
		if ((!vis[p[i].x]) || (!vis[p[i].y])) continue;
		unionn(p[i].x,p[i].y);
	}
	for (int i = 1;i <= 7; i++)
	{
		if (!vis[i]) continue;
		if (find(i) == i) cnt++;
	}
	if (cnt == 1) return true;
	return false;
}
int main()
{
	p[1].x = 1,p[1].y = 2;
	p[2].x = 1,p[2].y = 6;
	p[3].x = 2,p[3].y = 3;
	p[4].x = 2,p[4].y = 7;
	p[5].x = 3,p[5].y = 4;
	p[6].x = 3,p[6].y = 7;
	p[7].x = 4,p[7].y = 5;
	p[8].x = 5,p[8].y = 6;
	p[9].x = 5,p[9].y = 7;
	p[10].x = 6,p[10].y = 7;
	for (int i = 1;i < (1 << 7); i++)
	{
		if (check(i)) ans++;
	}
	check(5);
	printf("%d\n",ans);
	return 0;
}
