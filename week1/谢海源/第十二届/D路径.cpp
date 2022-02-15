#include<bits/stdc++.h>
using namespace std;
const int maxn=2021;//1->2021个点
const int INF=1e9;
int dp[maxn]={};

int gcd(int a,int b)//最大公约数
{
	if(a%b==0) return b;
	else return gcd(b,a%b);
}
int m(int a,int b)//最小公倍数
{
	return a*b/gcd(a,b);
}

int main()
{
	dp[1]=0;
	for(int i=2;i<=maxn;i++) dp[i]=INF;
	for(int i=1;i<=maxn;i++)
	{
		for(int j=i+1;j<=maxn;j++)
		{
			if(abs(i-j)>21) continue;
			int x=m(i,j);
			dp[j]=min(dp[j],dp[i]+x);
		}
	}
	cout<<dp[maxn];
    return 0;
}
