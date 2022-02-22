#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct point
{
	int x; //横坐标
	int y; //纵坐标
};

int main()
{
	vector<point> p;//存放所有点
	for (int i = 0; i <= 19; ++i)
		for (int j = 0; j <= 20; ++j)
			p.push_back({i, j});

	int len = p.size();
	set<pair<double, double>> lines; //存放斜直线y=kx+b
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len; ++j)
		{
			if (p[i].x != p[j].x && p[i].y != p[j].y) // 统计所有斜直线的情况
			{
				double k = (p[j].y - p[i].y) * 1.0 / (p[j].x - p[i].x);
				double b = (p[j].y * (p[j].x - p[i].x) - (p[j].y - p[i].y) * p[j].x) * 1.0 / (p[j].x - p[i].x);
				//double b = p[j].y - k * p[j].x; 不用这种方法，避免k造成精度爆炸
				lines.insert(pair<double, double>(k, b));
			}

		}
	}
	cout << lines.size() + 20 + 21 << endl; // 总的直线=斜直线+横直线+竖直线
	return 0;
}