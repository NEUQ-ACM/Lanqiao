#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t=0;
	int ans=1;
	for(int i=2;i<=20;i++)
	{
		t+=4;
		ans+=t;
	}
	cout<<ans;
	return 0;
}

//761
