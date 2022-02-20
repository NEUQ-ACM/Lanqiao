#include<iostream>
using namespace std;
int main()
{
	long long n;
	int h,m,s;
	cin>>n;
	long long t=n%(1000*24*60*60);
	h=t/(60*60*1000);
	m=(t%(60*60*1000))/60000;
	s=(t/1000)%60;
	printf("%02d:%02d:%02d", h, m, s);
	return 0;
}