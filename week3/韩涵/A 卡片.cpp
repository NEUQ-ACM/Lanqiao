/*#include<iostream>
using namespace std;
int cards[10] = { 2021,2021,2021,2021,2021,2021,2021,2021,2021,2021 };
int main() {
	int ans,bot = 1;
	for (ans = 1;; ans++) {
		int temp = ans;
		while (temp != 0) {
			int card = temp % 10;
			temp = temp / 10;
			cards[card]--;
			if (cards[card] < 0)bot = 0;
		}
		if (!bot) break;
	}
	cout << ans - 1;

}*/