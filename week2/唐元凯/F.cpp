#include<iostream>
#include<cmath>

using namespace std;

const int maxn = 1000 + 5;

int main() {
	int N;
	cin >> N;
	int cur = 1, max = -9999999, ans, temp;
	bool ending = 0;
	while(true)
	{
		int sum = 0;
		int c = pow(2, cur - 1);
		while (c--) {
			if (!(cin >> temp))ending = 1;
			sum += temp;
			if (c == 0||ending==1) {
				if (sum > max) {
					max = sum;
					ans = cur;
				}
			}
			if (ending)break;
		}
		if (ending)break;
		cur++;
	}
	cout << ans;
}