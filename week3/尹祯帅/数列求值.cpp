#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a1=1,a2=1,a3=1;
	long long ans;
	int cnt=3;
	while(cnt!=20190324)
	{
		a1=a1+a2+a3,cnt++;
		if(a1>10000) a1%=10000;
		a2+=a1+a3,cnt++;
		if(a2>10000) a2%=10000;
		a3+=a1+a2,cnt++;
		if(a3>10000) a3%=10000;
		cout<<cnt<<'\n'<<a3<<'\n';
	}
	return 0;
}

//4659
