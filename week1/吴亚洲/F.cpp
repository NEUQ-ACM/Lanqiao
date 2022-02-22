#include<bits/stdc++.h>
using namespace std;
const int M=100006;
bool dp[105][2*M];
int n,cnt;
int w[105];
int main()
{
	dp[0][M]=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=2*M;j++)
		{
			if(dp[i-1][j])
			dp[i][j]=1;
			else if(j+w[i]<=2*M&&dp[i-1][j+w[i]])
			dp[i][j]=1;
			else if(j-w[i]>=0&&dp[i-1][j-w[i]])
			dp[i][j]=1;
		}
	}
	for(int i=M+1;i<=2*M;i++)
	if(dp[n][i])
	cnt++;
	cout<<cnt;
}
