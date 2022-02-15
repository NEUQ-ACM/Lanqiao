
#include<iostream>
#include<map>
#include<set>
using namespace std;
struct ax {
	int x, y;
}a[500];
int t;
typedef pair<double, double> p;
set<p> s;
int main()
{
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 21; j++)
			a[++t].x = i, a[t].y = j;
	for (int i = 1; i <= 419; i++)
		for (int j = i + 1; j <= 420; j++)
		{
			int x1 = a[i].x, y1 = a[i].y;
			int x2 = a[j].x, y2 = a[j].y;
			if (x1 == x2 || y1 == y2)continue;
			double f = (x2 - x1) * 1.0;
			double k = (y2 - y1) * 1.0 / f;
			double b = (y1 * x2 - x1 * y2) * 1.0 / f;
			s.insert(make_pair(k, b));
		}
	cout << s.size() + 41;
}