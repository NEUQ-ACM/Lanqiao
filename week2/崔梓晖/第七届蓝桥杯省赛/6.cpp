#include<bits/stdc++.h>
using namespace std;
string str;
int dp[1002][1002];
int main() 
{
	cin>>str;
	string restr=str;
	int n=str.length();
	reverse(str.begin(),str.end());
	for(int i=0;i<=n;i++) 
	{
		dp[0][i]=dp[i][0]=0;
	}
	for(int i=1;i<=n;i++) 
	{    
		for(int j=1;j<=n;j++) 
		{
			if(restr[i-1]==str[j-1]) 
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}else 
			{
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			}
		}
	}
	cout<<n-dp[n][n];
	return 0;
} 

