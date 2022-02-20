#include<bits/stdc++.h>
using namespace std;
const int maxn=10000;
int a[maxn];
int main()
{
	int n;
	int maxa=-1,mina=101;
	double sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>maxa) maxa=a[i];
		if(a[i]<mina) mina=a[i];
		sum+=a[i];
	}
	cout<<maxa<<endl;
	cout<<mina<<endl;
	printf("%.2f",sum/n);
    return 0;
}
