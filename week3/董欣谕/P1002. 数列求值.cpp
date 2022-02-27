#include <bits/stdc++.h>
using namespace std;
#define pair <int,int> pii
const int mod=1e9+7;
const int INF=0x3f3f3f3f; 
typedef long long ll;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	ll a,b,c,d;
	int cnt=4;
	a=1,b=1,c=1,d;
	while (cnt<=20190324){
		d=(a+b+c)%10000;
		a=b;
		b=c;
		c=d;
		cnt++;
	}
	cout<<d;
	return 0;
} 
