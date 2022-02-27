//答案：761
#include<iostream>
#include<string>//to_string
using namespace std;
struct point
{
	int x, y, v;
};
int map[50][50];
int main()
{
	point now;
	now.x = 1;
	now.y = 1;
	now.v = 1;
	bool up_flag = 1;//是否向上
	while (true)
	{
		map[now.x][now.y] = now.v;
		if (up_flag)
		{
			if (now.y == 1)//到顶
			{
				up_flag = 0;
			}
			else
			{
				now.y--;
			}
			now.x++;
			now.v++;
		}
		else
		{
			if (now.x == 1)
			{
				up_flag = 1;
			}
			else
			{
				now.x--;
			}
			now.y++;
			now.v++;
		}
		if (now.x == 20 && now.y == 20)
		{
			cout << now.v << endl;
			break;
		}
	}
	for (int i = 1; i < 41; i++)//打印地图，方便验证
	{
		for (int j = 1; j < 41; j++)
			cout << map[i][j] << ' ';
		cout << endl;
	}
}