#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const int maxn=1e6+4;
int cnt[15];
void dfs(int x){
	int temp=x;
	while (temp>0){
		cnt[temp%10]--;
		temp/=10;
	}
	for (int i=0;i<10;i++)
		if (cnt[i]<0) {
			cout<<x-1;
			exit(0);
		}
	dfs(x+1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	for (int i=0;i<10;i++) cnt[i]=2021;
	dfs(1);
	return 0;
} 
