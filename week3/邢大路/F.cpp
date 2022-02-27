#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main()
{
	int n,maxx=-1,minn=101;
	cin>>n;
	long long s=0;
	double ave;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s+=a[i];
		maxx=max(maxx,a[i]);
		minn=min(minn,a[i]);
	}
	ave=s/double(n);
	printf("%d\n%d\n%.2lf",maxx,minn,ave);	
}

