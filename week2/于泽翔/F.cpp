#include<bits/stdc++.h>
#define N 2050
using namespace std;

int w[110];
bool dp[110][100010];

int main(void)
{
	int n, sum=0;
	cin>>n;
	
	for(int i=1; i<=n; i++)
	{
		cin>>w[i];
		sum+=w[i];
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=sum; j++)
		{
			dp[i][j]=dp[i-1][j];
			if(dp[i-1][j]==0)
			{
				if(w[i]==j)
					dp[i][j]=1;
				if(dp[i-1][j+w[i]] || dp[i-1][abs(j-w[i])])
					dp[i][j]=1;
			}
		}
	long long ans=0;
	for(int i=1; i<sum; i++)
		if(dp[n][i])
			ans++;
	cout<<ans+1;
	
	
	return 0;
}