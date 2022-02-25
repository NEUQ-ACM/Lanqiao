#include<iostream>
using namespace std;

int main() {
	int cnt = 0;
	for (size_t i = 1; i <= 2020; i++)
	{
		int t = i;
		while (t > 0) {
			if (t % 10 == 2)++cnt;
			t /= 10;
		}
	}
	cout << cnt;
}