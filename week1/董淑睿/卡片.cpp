#include <bits/stdc++.h>
using namespace std;
const int maxn = 2021;
int a[10];
vector<int> f(int x) {
	vector<int> ret;
	if(x == 0) {
		ret.push_back(0);
		return ret;
	}
	while(x>0) {
		ret.push_back(x % 10);
		x/=10;
	}
	return ret;
}
bool g(const vector<int> &x) {
	for(unsigned int i = 0; i < x.size(); i++) {
		a[x[i]]--;
		if(a[x[i]] < 0) return 0;
	}
	return 1;
}
int main() {
	for(int i = 0; i < 10; i++) a[i] = maxn;
	int ans = 1;
	while(1) {
		vector<int> N = f(ans);
		bool tmp = g(N);
		if(!tmp) break;
		ans++;
	}
	printf("%d\n", ans - 1);
	return 0;
}
