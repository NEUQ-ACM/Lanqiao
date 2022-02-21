#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[10];
	for (int i = 0; i <= 9; i++)
		a[i] = n;
	int i = 1;
	for (;; i++) {
		int t = i;
		while (t) {
			a[t % 10]--;
			if (a[t % 10] == 0)
				goto loop;
			t /= 10;
		}
	}
loop:
	cout << i << endl;
	return 0;
}