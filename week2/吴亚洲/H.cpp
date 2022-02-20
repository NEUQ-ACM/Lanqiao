#include<bits/stdc++.h>
using namespace std;
string s;
long long ans;
int main()
{
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		int l=i-1,r=i+1;
		for(l;l>=0;l--)
		if(s[i]==s[l])
		break;
		for(r;r<=s.length()-1;r++)
		if(s[i]==s[r])
		break;
		ans+=((i-l)*(r-i));
	}
	cout<<ans;
}
