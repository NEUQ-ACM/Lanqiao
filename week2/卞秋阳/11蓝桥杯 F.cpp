#include<bits/stdc++.h>
#define ll long long
using namespace std;
int maxx,n,minn=2147483647,ans;
double ave;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		ans+=x;
		minn=min(minn,x);
		maxx=max(maxx,x);
	}
	ave=(double)ans/n;
	cout<<maxx<<endl<<minn<<endl;
	printf("%.2lf",ave);
}

