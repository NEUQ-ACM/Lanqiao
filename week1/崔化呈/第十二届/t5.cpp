#include<bits/stdc++.h>
using namespace std;
bool dp[105][100100];
int w[105];
int main()
{
	int n,sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&w[i]);
		sum+=w[i];
	}	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			dp[i][j]=dp[i-1][j];
			if(dp[i-1][j]==0)
			{
				if(w[i]==j){dp[i][j]=1;}
				if(dp[i-1][j+w[i]]){dp[i][j]=1;}
				if(dp[i-1][abs(j-w[i])]){dp[i][j]=1;}
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=sum;i++)
	{
		if(dp[n][i]){ans++;}
	}
	printf("%lld",ans);
	return 0;
}
