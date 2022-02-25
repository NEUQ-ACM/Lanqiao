//bfs
//比较基础，但侧面反映出我该多熟悉一下bfs了


#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

char ma[30][50];
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,-1,1,0 };
char l[4] = { 'D','L','R','U' };
int vis[30][50] = { 0 };

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
		if (t.x == 29 && t.y == 49)
		{
			cout << t.road << endl;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int x = t.x + dx[i];
			int y = t.y + dy[i];
			if (x >= 0 && x < 30 && y >= 0 && y < 50)
			{
				if (ma[x][y] == '0' && !vis[x][y])
				{
					point tt(x, y);
					tt.road = t.road + l[i];//记录路径
					q.push(tt);
					vis[x][y] = 1;
				}
			}
		}
	}
}

int main()
{
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 50; j++)
			cin>>ma[i][j];
	bfs();
	return 0;
}