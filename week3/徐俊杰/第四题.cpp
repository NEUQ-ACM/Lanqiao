#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<set>
using namespace std;

#define N 30
#define M 50

char map[N][M];
int dir[4][2] = { {1,0},{0,-1},{0,1},{-1,0} };//D<L<R<U
char ch[4] = { 'D','L','R','U' };
int vis[N][M] = { 0 };

struct point
{
	int x, y;
	string road;
	point(int a, int b)
	{
		x = a;
		y = b;
	}
};

void bfs()
{
	queue<point> q;
	point p(0, 0);
	p.road = "";
	q.push(p);
	vis[0][0] = 1;
	while (!q.empty())
	{
		point t = q.front();
		q.pop();
		if (t.x == N - 1 && t.y == M - 1)
		{
			cout << t.road << endl;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int dx = t.x + dir[i][0];
			int dy = t.y + dir[i][1];
			if (dx >= 0 && dx < N && dy >= 0 && dy < M)
			{
				if (map[dx][dy] == '0' && !vis[dx][dy])
				{
					point tt(dx, dy);
					tt.road = t.road + ch[i];//记录路径
					q.push(tt);
					vis[dx][dy] = 1;
				}
			}
		}
	}
}

int main()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			scanf("%c", &map[i][j]);
		getchar();//读掉回车 
	}
	bfs();
	return 0;
}