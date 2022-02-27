#include<bits/stdc++.h>
using namespace std;
long long res;
bool check(int x) {
	while(x) {
		int a = x % 10;
		x /= 10;
		if(a == 2 || a == 0 || a == 1 || a == 9) return 1;
	}
	return 0;
}
int main()
{
	for(int i = 1; i < 2020; i++) {
		if(check(i)) res += i * i;
	}
	cout << res << endl;
}
