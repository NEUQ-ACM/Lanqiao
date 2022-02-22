#include<bits/stdc++.h>
#define N 100005
using namespace std;


int a[N];
int res[N];

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] += a[i-1];
	}
	res[1] = a[1];
	for(int i = 1, j = 2; i <= n; j++){
		i = i*2 + 1;
		if(i > n){
			res[j] = a[n] - a[i/2];
			break;
		}
		res[j] = a[i] - a[i/2];
	}
//	for(int i = 1; i <= 3; i++){
//		cout << res[i] << " ";
//	}
	int ans = 1, maxm = res[1];
	for(int i = 2; i <= n; i++){
		if(res[i] > maxm){
			ans = i;
			maxm = res[i];
		} 
	}
	cout << ans;
}


