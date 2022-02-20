#include <bits/stdc++.h>
using namespace std;
 
int dx[] = {1, 0, 0, -1}, dy[] = {0, -1, 1, 0};
char dc[] = {'D', 'L', 'R', 'U'};
bool vis[60][60];
char m[60][60];   //vis 标记 m 地图 
struct node{
	int x, y;
	string way;  //路径存储参考 金添 代码 
};

int main()
{
	for (int i = 1; i <= 30; i++)
		for (int j = 1; j <= 50; j++)
			cin >> m[i][j];
	
	//开始dfs
	 queue<node> q;
	 vis[1][1] = 1;
	 node a; a.x = 1, a.y = 1;
	 q.push(a);
	 
	 while(!q.empty())
	 {
	 	node k = q.front();
	 	q.pop();
	 	int x = k.x, y = k.y;
	 	string way = k.way;
	 	if(x == 30 && y == 50) 
	 	{
//	 		cout << "No!";
	 		cout << way;
	 		return 0;
		}
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			string way2 = way + dc[i];
			if(!vis[xx][yy] && m[xx][yy] == '0' && xx <= 30 && xx > 0 && yy <= 50 && yy > 0)
			{
//				cout << "Yes!";
//				printf("xx = %d yy = %d \n",xx, yy);
				vis[xx][yy] = 1;
				node kk;
				kk.x = xx, kk.y = yy, kk.way = way2;
				q.push(kk);
			}
		}
	 }
	
	return 0;
}
