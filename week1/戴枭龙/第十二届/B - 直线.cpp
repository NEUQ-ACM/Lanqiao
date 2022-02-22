#include <bits/stdc++.h>
using namespace std;

struct Node {
	int x, y;
} node[21 * 20 + 10];
int cnt = 1;

int main() {
	for (int i = 0; i <= 19; i++) {
		for (int j = 0; j <= 20; j++) {
			node[cnt].x = i;
			node[cnt++].y = j;
		}
	}
	set<pair<double, double>>s;
	for (int i = 1; i <= 21 * 20 - 1; i++) {
		for (int j = i + 1; j <= 21 * 20; j++) {
			if (node[i].x == node[j].x)
				continue;
			double k = 1.0 * (node[i].y - node[j].y) / (node[i].x - node[j].x);
			double b = 1.0 * node[i].y - k * node[i].x;
			s.insert(make_pair(k, b));
		}
	}
	cout << s.size() + 20;
	return 0;
}