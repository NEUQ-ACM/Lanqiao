#include<bits/stdc++.h>
using namespace std;
int main()
{
	int ans=0;
	for(int i=1;i<=2020;i++)
	{
		bool t=0;
		for(int j=2;j<=sqrt(i);j++)
		if(i%j==0)
		t=1;
		if(t)
		ans++;
	}
	cout<<ans;
}
