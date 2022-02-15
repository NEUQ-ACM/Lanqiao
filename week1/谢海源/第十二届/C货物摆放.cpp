#include<bits/stdc++.h>
using namespace std;
#define int long long
const int n=2021041820210418;
//const int n=12;
signed main()
{
	int sum=0;
	for(int i=1;i<=pow(n,1.0/3);i++)//范围是1->n的根号3次方
	{
		if(n%i!=0) continue;
		int n1=n/i;
		for(int j=i;j<=sqrt(n);j++)//范围是1->根号n
		{
			if(n1%j!=0) continue; 
			int k=n1/j;
			if(k<j) continue;//保证x<=y<=z
			if(i==j&&j==k) sum=sum+1;
			else if(i==j||i==k||j==k) sum=sum+3;		
			else if(i!=j&&i!=k&&j!=k) sum=sum+6;
		}
	}
	cout<<sum;
    return 0;
}
