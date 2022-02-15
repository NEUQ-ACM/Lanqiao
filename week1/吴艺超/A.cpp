#include<bits/stdc++.h>
using namespace std;
int a[10];
const int maxn=2021;
int ans=1;
int flag=0;
void chai(int s)
{
	while(s)
	{
		int x=s%10;
		s/=10;
		if(a[x]==0)
		{
			flag=1;
			return;
		}
		else a[x]--;
	}
}
int main()
{
	for(int i=0;i<=9;i++)
		a[i]=maxn;
	while(1)
	{
		chai(ans);
		if(flag==0)
		ans++;
		else break;
	}
	ans--;
	cout<<ans;
}

