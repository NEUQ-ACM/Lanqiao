#include <bits/stdc++.h>
using namespace std;
#define pair <int,int> pii
const int mod=1e9+7;
const int INF=0x3f3f3f3f; 
typedef long long ll;
bool check(int x){
	while (x){
		int temp=x%10;
		if (temp==1||temp==2||temp==0||temp==9) return 1;
		x/=10;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n=2019;
	ll sum=0;
	for (int i=1;i<=n;i++)	
		if (check(i)) sum+=i*i;
	cout<<sum;
	return 0;
} 
