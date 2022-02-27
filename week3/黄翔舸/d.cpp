#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

char xz[30][50];
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,-1,1,0 };
char l[4] = { 'D','L','R','U' };
int bl[30][50] = { 0 };

struct dian
{
	int x, y;
	string road;
	dian(int a, int b)
	{
		x = a;
		y = b;
	}
};

void blhs()
{
	queue<dian> q;
	dian p(0, 0);
	p.road = "";
	q.push(p);
	bl[0][0] = 1;
	while (!q.empty())
	{
		dian t = q.front();
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
				if (xz[x][y] == '0' && !bl[x][y])
				{
					dian tt(x, y);
					tt.road = t.road + l[i];
					q.push(tt);
					bl[x][y] = 1;
				}
			}
		}
	}
}

int main()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			cin >> xz[i][j];
		}
	}
	blhs();
	return 0;
}