#include<iostream>
#include<string>
#include<queue>
#include<stack>
using namespace std;
char map[32][52];//地图，存放0和1
bool vis[32][52];//是否访问过
int record[32][52];//记录如何到达(x, y)点
string s = "DLRU";//方向
int dx[] = { 1, 0, 0,-1 };
int dy[] = { 0,-1, 1, 0 };

struct node
{
	int x;
	int y;
};

void bfs()
{
	queue<node>q;
	node now, next;
	now.x = 0;
	now.y = 0;
	vis[0][0] = 1;
	q.push(now);
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int x0 = now.x + dx[i];
			int y0 = now.y + dy[i];
			//如果在范围内，并且没有被访问过，且可以访问
			if (x0 >= 0 && x0 < 30 && y0 >= 0 && y0 < 50 && !vis[x0][y0] && map[x0][y0] == '0')
			{
				next.x = x0;
				next.y = y0;
				vis[x0][y0] = 1;
				q.push(next);
				record[x0][y0] = i;//记录如何到达此点
			}
		}
	}

	//从出口开始向入口遍历记录，因此放在栈中，便于反向输出
	stack<char> st;
	int x = 29, y = 49;
	while (x != 0 || y != 0)
	{
		st.push(s[record[x][y]]);
		x = x - dx[record[x][y]];
		y = y - dy[record[x][y]];
	}
	//输出
	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}
}

int main()
{
	for (int i = 0; i < 30; i++) cin >> map[i];
	bfs();
	return 0;
}
