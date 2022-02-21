//答案：40257
//暴力穷举

#include <iostream>
#include<map>
using namespace std;
struct points
{
	double x, y;
};
points point[1000000];
long long en = 0;  // 最终结果
int num;
map<pair<double, double>, bool> ma;
int main()
{
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 21; j++)
		{
			point[num].x = i;
			point[num].y = j;
			num++;
		}
	for(int i=0;i<num;i++)
		for (int j = i+1; j < num; j++)
		{
			if (point[i].x == point[j].x)
				continue;
			else
			{
				double k = (point[i].y - point[j].y) / (point[i].x - point[j].x);
				double b = (point[j].x * point[i].y - point[j].y * point[i].x) / (point[j].x - point[i].x);  //如果用y1-kx1的方式求会导致误差增大（尚不知为什么表现为数量减小）
				if (!ma[{k, b}])
				{
					ma[{k, b}] = true;
					en++;
				}
			}
		}
	cout << en + 20;
	return 0;
}