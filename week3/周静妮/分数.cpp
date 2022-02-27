#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long sum=pow(2,19),s,tem,m,n;
	s=2*sum-1;
	m=sum;
	n=s;
	while(1)
	{
		tem=s%sum;	
		s=sum;
		sum=tem;
		if(tem==1 || tem==0) break;
	 } 
	 if(!tem) 
	 {
	 	m/=s;
	 	n/=s;
	 }
	 cout<<n<<'/'<<m; 
}
