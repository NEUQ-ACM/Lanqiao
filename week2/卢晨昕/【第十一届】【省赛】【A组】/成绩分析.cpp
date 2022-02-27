//100
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;
int n;
double ave;
int maxn=0,minn=105;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		if(a>maxn)maxn=a;
		if(a<minn)minn=a;
		ave+=a;
	}
	cout<<maxn<<endl<<minn<<endl;
	printf("%0.2lf",ave/n);
	return 0;
}
