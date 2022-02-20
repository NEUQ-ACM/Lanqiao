#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pre[30];
string s;
int main(){
	cin>>s;
	ll ans=0,len=s.length();
	s="0"+s;
	for(ll i=1;i<=len;i++){
		ans+=(i-pre[s[i]-'a'])*(len-i+1);
		pre[int(s[i]-'a')]=i;
	}	
	cout<<ans<<endl;
}
