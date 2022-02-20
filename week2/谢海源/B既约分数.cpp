#include<bits/stdc++.h>
using namespace std;
const int maxn=2020;
int gcd(int a,int b)//最大公约数
{
	if(a%b==0) return b;
	else return gcd(b,a%b);
}
int main()
{
	int sum=0;
	for(int i=1;i<=maxn;i++)//上
	{
		for(int j=1;j<=maxn;j++)//下
		{
			if(gcd(i,j)==1) sum++;
		}
	}
	cout<<sum;
    return 0;
}
