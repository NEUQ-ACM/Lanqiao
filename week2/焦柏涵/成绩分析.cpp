#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,maxn=0,minn=100,sum=0;
	cin>>n; 
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		if(maxn<a) maxn=a;
		if(minn>a) minn=a;
		sum+=a;
	}
	double d;
	d=sum*1.0/n;
	cout<<maxn<<endl<<minn<<endl<<fixed<<setprecision(2)<<d;
	return 0;
}
