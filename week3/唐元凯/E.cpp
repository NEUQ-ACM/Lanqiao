#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int m = 20, n = 20;
	int ans = m * m - m + 2 * m * n + 1 + n * (n + 1) / 2;
	cout << ans;
}