#include<bits/stdc++.h>
#define ll long long
using namespace std;
int ans=1;
int main()
{
	for(int i=2;i<=20;i++)
	{
		ans+=(i-1)*4;
	}
	cout<<ans;
}
