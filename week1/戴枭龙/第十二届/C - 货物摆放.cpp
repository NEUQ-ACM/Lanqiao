#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	LL n = 2021041820210418;
	vector<LL>yinshu;
	int i, sum = 0;
	for (i = 1; i <= sqrt(n); i++) {
		if (n % i == 0)
			yinshu.emplace_back(i);
	}
	i = sqrt(n) == yinshu.back() ? yinshu.size() - 2 : i = yinshu.size() - 1;
	for (; i >= 0;  i--) {
		yinshu.emplace_back(n / yinshu[i]);
	}
	int cnt = yinshu.size();
	for (size_t i = 0; i < cnt; i++) {
		for (size_t j = 0; j < cnt; j++) {
			for (size_t m = 0; m < cnt; m++) {
				if (yinshu[i] * yinshu[j] * yinshu[m] == n)
					++sum;
			}
		}
	}
	cout << sum;
}