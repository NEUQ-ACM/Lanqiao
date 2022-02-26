#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int cnt=0;
	for (int i=1;i<=2020;i++){
		int temp=i;
		while (temp){
			if (temp%10==2) cnt++;
			temp/=10;
		}
	}
	cout<<cnt;
	return 0;
} 
