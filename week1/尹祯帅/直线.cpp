#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
const double eps=1e-6;  //为了防止数据丢失带来的偏差 
double xl[N],jj[N];
int ans=0;

void check(double x,double j)
{
	for(int i=0;i<ans;i++) 
	if(abs(x-xl[i])<=eps&&abs(j-jj[i])<=eps) return ;
	
	xl[ans]=x;
	jj[ans++]=j;
}
int main()
{
	int n,m;
//	n=2,m=3;
	n=20,m=21;
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	for(int k=i+1;k<m;k++)
	for(int d=0;d<n;d++)
	{
		if(k==i) continue;
		double x=(double)(d-j)/double(k-i);
		check(x,d-x*k);
	}
	cout<<ans+m;
	return 0;
}
