#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int gcd(int x,int y){
	if (x%y==0) return y;
	return gcd(y,x%y);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int cnt=0;
	for (int i=1;i<=2020;i++){
		for (int j=1;j<=2020;j++){
			int temp=gcd(i,j);
			if (temp==1) cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
