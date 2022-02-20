#include<bits/stdc++.h>
using namespace std;
int main()
{
	int min=1000,max=0,a;
	long long sum=0;
	double n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		sum+=a;
		if(a<min) min=a;
		if(max<a) max=a; 
	}
	cout<<max<<'\n'<<min<<'\n';
	printf("%.2f",sum/n);
	return 0;
}
