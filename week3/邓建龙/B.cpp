#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	ll a = 1, b = 1, c = 1, res;
	for(int i = 4; i <= 20190324; i++) {
		res = (a + b + c) % 10000;
		a = b; b = c; c = res;
	}
	cout << res << endl;
	return 0;
}