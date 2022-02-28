#include<bits/stdc++.h>
using namespace std;
int pre[100010], nxt[100010], a[27];
string s;
int main(void)
{
    long long ans=0;
	cin>>s;
    s+='0';

    int l_s=s.size();
    for(int i=1; i<=l_s; i++)
    {
        int c=s[i]-'a';
        pre[i]=a[c];
        a[c]=i;
    }
    for(int i=0; i<26; i++)
        a[i]=l_s+1;

    for(int i=l_s; i>0; i--)
    {
        int cc=s[i]-'a';
        nxt[i]=a[cc];
        a[cc]=i;
    }
    for(int i=1; i<=l_s; i++)
        ans+=(long long)(i-pre[i])*(nxt[i]-i);
    cout<<ans;
	
	return 0;
}