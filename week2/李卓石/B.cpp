#include <bits/stdc++.h>
using namespace std;

int main() {
	double k,b;
	int sum = 0;
	set<pair<double, double>>s;
	for (double x1 = 0; x1 < 20; x1++)
	{
		for (double y1 = 0; y1 < 21; y1++)
		{
			for (double x2 = 1; x2 < 20; x2++)
			{
				for (double y2 = 0; y2 < 21; y2++)
				{
					if (x1 != x2) {
						k = (y2 - y1) / (x2 - x1);
						b = (x2 * y1 - y2 * x1) / (x2 - x1);//最简式表达去除精度问题
						s.insert(make_pair(k, b));//自动去重,set唯一限制 
					}
				}
			}
		}
	}
	cout << s.size() + 20;//竖直无斜率
}
