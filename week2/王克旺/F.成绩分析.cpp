#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,min=100,max=0,sum=0;
	double average;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		sum=sum+a;
		if(a<min)
		{
			min=a;
		}
		if(a>max)
		{
			max=a;
		}
	}
	average=1.0*sum/n;
	cout<<max<<endl<<min<<endl<<fixed<<setprecision(2)<<average;
	return 0; 
}
