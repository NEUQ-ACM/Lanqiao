//70
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;
int v;
string s;
int ans1,ans2;
int main()
{
	cin>>v;
	for(int i=1;i<=26;i++)
	{
		for(int j=0;j<=i;j++)
		{
			int now=0;
			for(int k=0;k<j;k++)
			{
				now+=2*2*k;
			}
			for(int k=j*2;k<=j+i-1;k++)
			{
				now+=k;
			}
			if(now==v)
			{
				ans1=i;
				ans2=j;
				break;
			}
		}
		if(ans1!=0||ans2!=0)break;
	}
	for(int i=ans1;i>=1;i--)
	{
		if(i>ans2)cout<<(char)(i+'a'-1);
		else cout<<(char)(i+'a'-1)<<(char)(i+'a'-1);
	}
	return 0;
}
