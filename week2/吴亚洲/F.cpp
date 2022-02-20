#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,Max=-1,Min=101,sum=0,x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		Max=max(x,Max);
		Min=min(Min,x);
		sum+=x;
	}
	cout<<Max<<endl<<Min<<endl;
	double ave=(double)sum/(double)n;
	cout<<fixed<<setprecision(2)<<ave;
}
