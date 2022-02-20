#include<vector>
#include<set>
#include<iostream>
#include<cmath>
#include<map>
using namespace std;

int main() {
	double rat, ic;
	int sum = 0;
	set<pair<double, double>>cnt;
	for (double x1 = 0; x1 < 20; x1++)
	{
		for (double y1 = 0; y1 < 21; y1++)
		{
			for (double x2 = 0; x2 < 20; x2++)
			{
				for (double y2 = 0; y2 < 21; y2++)
				{
					if (x1 != x2) {
						rat = (y2 - y1) / (x2 - x1);
						ic = (x2 * y1 - y2 * x1) / (x2 - x1);
						cnt.insert(make_pair(rat, ic));
					}
				}
			}
		}
	}
	cout << cnt.size() + 20;
}