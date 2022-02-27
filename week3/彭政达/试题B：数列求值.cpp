#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll a[30000000];
	a[0]=a[1]=a[2]=1;
	for(ll i=3;i<20190324;i++) a[i]=(a[i-1]+a[i-2]+a[i-3])%10000;
	cout<<a[20190323]<<endl;
	return 0;
}
