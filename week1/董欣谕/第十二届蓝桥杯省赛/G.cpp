#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const int maxn=2e5+5;
int a[maxn],cnt[25];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		memset(cnt,0,sizeof cnt);
		for (int i=1;i<=n;i++){
			cin>>a[i];
			for (int j=0;j<=20;j++)
				if (a[i]>>j&1) cnt[j]++;
		}
		int flag=0;
		for (int i=20;i>=0;i--){
			if (cnt[i]%2==1) {
				if (cnt[i]==1) flag=2;
				else flag=1;
				break;
			}
		}
		if (!flag) cout<<0<<"\n";
		else if (n%2==1||flag==2) cout<<1<<"\n";
		else cout<<-1<<"\n";
	}
	return 0;
} 
