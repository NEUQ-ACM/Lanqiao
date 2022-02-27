# 第六届蓝桥杯省赛大学a组

1.

7

暴力枚举。

2.

26

仍然暴力枚举

3.

dfs+回溯

```c++
#include<iostream>
using namespace std;
int map[6][6];
int ans;
bool vis[10];

bool check(int x, int y, int n)
{
	if (vis[n]) return false;
	if (x < 1 || x > 3) return false;
	if (y < 1 || y > 4) return false;
	if (map[x][y] != 0) return false;
	if (abs(map[x][y - 1] - n) <= 1) return false;
	if (abs(map[x - 1][y] - n) <= 1) return false;
	if (abs(map[x - 1][y - 1] - n) <= 1) return false;
	if (abs(map[x - 1][y + 1] - n) <= 1) return false;
	return true;
}

void dfs(int x,int y)
{
	for (int i=0;i<=9;i++)
	{
		int x0,y0;
		if(y==4)
		{
			x0=x+1;
			y0=1;
		}
		else
		{
			x0=x;
			y0=y+1;
		}
		if(x0==3&&y0==4)
		{
			ans++;
			return;
		}
		if(check(x0,y0,i))
		{
			map[x0][y0]=i;
			vis[i]=true;
			dfs(x0, y0);
			map[x0][y0]=0;
			vis[i]=false;
		}
	}
}
int main()
{
	memset(map,10,sizeof(map));
	for (int i=1;i<=3;i++)
	{
		for(intj=1;j<=4;j++)
		{
			map[i][j]=0;
		}
	}
	map[1][1]=-2;
	map[3][4]=-2;
	dfs(1,1);
	cout<<ans;
	return 0;
}

```

4.

swap(a, p, j);

5.

x & (x + 1)

不太明白。。。

上网搜的

6.

64

依然dfs+回溯

但是麻烦

```c++
#include<iostream>
using namespace std;
int a[5][3];
bool vis[14];
int ans;

bool check(int x, int y, int n)
{
	if (a[x][y] != 0) 
        return false;
	if (vis[n]) 
        return false;
	if (x < 1 || x > 4) 
        return false;
	if (y < 1 || y > 2) 
        return false;
	if (x == 1 && y == 2)
	{
		if ((a[x][1] + n) < 1 || (a[x][1] + n) > 13) 
            return false;
		if (a[x][1] + n == a[x][1] || a[x][1] + n == n) 
            return false;
		if (vis[a[x][1] + n]) 
            return false;
	}
	if (x == 2 && y == 2)
	{
		if ((a[x][1] - n) < 1 || (a[x][1] - n) > 13) 
            return false;
		if (a[x][1] - n == a[x][1] || a[x][1] - n == n) 
            return false;
		if (vis[a[x][1] - n]) 
            return false;
	}
	if (x == 3 && y == 2)
	{
		if ((a[x][1] * n) < 1 || (a[x][1] * n) > 13) 
            return false;
		if (a[x][1] * n == a[x][1] || a[x][1] * n == n) 
            return false;
		if (vis[a[x][1] * n]) 
            return false;
	}
	if (x == 4 && y == 2)
	{
		if (a[x][1] % n != 0) 
            return false;
		if ((a[x][1] / n) < 1 || (a[x][1] / n) > 13) 
            return false;
		if (a[x][1] / n == a[x][1] || a[x][1] / n == n) 
            return false;
		if (vis[a[x][1] / n]) 
            return false;
	}
	return true;
}

void sign(int x, int y, bool sign)
{
	if (x == 1 && y == 2) 
        vis[a[x][1] + a[x][2]] = sign;
	else if (x == 2 && y == 2) 
        vis[a[x][1] - a[x][2]] = sign;
	else if (x == 3 && y == 2) 
        vis[a[x][1] * a[x][2]] = sign;
	else if (x == 4 && y == 2) 
        vis[a[x][1] / a[x][2]] = sign;
}

void dfs(int x, int y)
{
	int sum = 0;
	for (int i = 1; i <= 13; i++)
	{
		if (vis[i]) sum++;
	}
	if (sum == 12)
	{
		ans++;
		return;
	}

	for (int i = 1; i <= 13; i++)
	{
		int x0, y0;
		if (y == 2)
		{
			x0 = x + 1;
			y0 = 1;
		}
		else
		{
			x0 = x;
			y0 = y + 1;
		}
		if (check(x0, y0, i))
		{
			a[x0][y0] = i;
			vis[i] = true;
			sign(x0, y0, true);
			dfs(x0, y0);
			vis[i] = false;
			sign(x0, y0, false);
			a[x0][y0] = 0;
		}
	}
}

int main()
{
	dfs(1, 0);
	cout << ans;
	return 0;
}


```

7

```c++
#include<iostream>
#include<algorithm>
using namespace std;
char a[4][5];		
bool vis[4][5];
string Sfind[1005];	
string s_black;		
int ans;			
int cnt;			
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
bool check(int x, int y)
{
	if (vis[x][y]) return false;
	if (x < 1 || x > 3) return false;
	if (y < 1 || y > 4) return false;
	return true;
}
bool check_s(string s)
{
	sort(s.begin(), s.end());
	if (s.length() != 5) return false;
	if (s.length() == 5)
	{
		for (int i = 0; i < 1005; i++)
		{
			if (Sfind[i] == s) return false;
		}
	}
	Sfind[cnt++] = s;
	return true;
}
void dfs(int x, int y, string s)
{
	if (check_s(s))
	{
		ans++;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int x0 = x + dx[i];
		int y0 = y + dy[i];

		if (check(x0, y0))
		{
			vis[x0][y0] = 1;
			dfs(x0, y0, s + a[x0][y0]);
			vis[x0][y0] = 0;
		}
	}
}
int main()
{
	char c = 'a';
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			a[i][j] = c++;
		}
	}
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			memset(vis, 0, sizeof(vis));
			vis[i][j]=1;
			dfs(i, j, s_black + a[i][j]);
		}
	}
	cout<<ans;
	return 0;
}

```

依然dfs+回溯

不过去重

