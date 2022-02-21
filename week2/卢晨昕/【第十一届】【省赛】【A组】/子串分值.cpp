//100
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;
string s;
ll pre[100005],nex[100005];
ll pos[30];
ll ans;
int main()
{
	cin>>s;
	for(int i=0;i<=26;i++)pos[i]=-1;
	for(int i=0;i<s.length();i++)
	{
		pre[i]=pos[s[i]-'a'];
		pos[s[i]-'a']=i;
	}
	for(int i=0;i<=26;i++)pos[i]=s.length();
	for(int i=s.length()-1;i>=0;i--)
	{
		nex[i]=pos[s[i]-'a'];
		pos[s[i]-'a']=i;
	}
	for(int i=0;i<s.length();i++)
	{
		ans+=(i-pre[i])*(nex[i]-i);
	}
	cout<<ans;
	return 0;
}
