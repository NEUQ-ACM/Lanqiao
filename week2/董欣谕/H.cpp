#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const int N=1e5+5;
int r[N],lc[26],rc[26];
char s[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>s+1;
	int len=strlen(s+1);	
	for (int i=0;i<26;i++)
		rc[i]=len+1,lc[i]=0;
	for (int i=len;i>=1;i--){
		r[i]=rc[s[i]-'a'];
		rc[s[i]-'a']=i;
	}
	ll ans=0;
	for (int i=1;i<=len;i++){
		ans+=1ll*(r[i]-i)*(i-lc[s[i]-'a']);
		lc[s[i]-'a']=i;
	}
	cout<<ans;
	return 0;
} 
