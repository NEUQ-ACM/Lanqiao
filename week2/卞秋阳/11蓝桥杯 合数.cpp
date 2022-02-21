#include<bits/stdc++.h>
#define ll long long
using namespace std;
int ans;
void solve(int x)
{
	while(x)
	{
		if(x%10==2)ans++;
		x/=10;
	}
} 
int main()
{
	for(int i=1;i<=2020;i++)
		solve(i);
	cout<<ans;
}
