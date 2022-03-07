#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long i,a,b,c,d;
    a=1,b=1,c=1;
	for(i=4;i<=20190324;i++)
	{
		d=a+b+c;
		if(d>9999)
		d=d%10000;
		a=b,b=c,c=d;		
	} 
	cout<<d<<endl;
	return 0;
}
