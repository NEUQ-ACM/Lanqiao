#include<bits/stdc++.h>
using namespace std;
char ma[32][52];
bool vis[32][52];
int record[32][52];
string s = "DLRU";
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
			if (x0 >= 0 && x0 < 30 && y0 >= 0 && y0 < 50 && !vis[x0][y0] && ma[x0][y0] == '0')
			{
				next.x = x0;
				next.y = y0;
				vis[x0][y0] = 1;
				q.push(next);
				record[x0][y0] = i;
			}
		}
	}
	stack<char> st;
	int x = 29, y = 49;
	while (x != 0 || y != 0)
	{
		st.push(s[record[x][y]]);
		x = x - dx[record[x][y]];
		y = y - dy[record[x][y]];
	}
	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}
}

int main()
{
	for (int i = 0; i < 30; i++) cin >> ma[i];
	bfs();
	return 0;
}


//DDDDRURRRRRDRRRDDDDDDDDDDDDDDDDDDDRRURUURDDDDDRRRRRDRURDDDRRRUUUUUUUUUULUUUURRRUULLUUUULUUUUURURUURRDDRRRRDDRDDLLDDRDDDDDDDLDDLLDDDDDDRRRRRRRRDDDDDDRR
