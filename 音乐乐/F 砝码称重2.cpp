/*
提交时间	02-10 16:32:22
评测结果	正确
得分	100
CPU使用	46ms
内存使用	23.55MB
*/
#include<bits/stdc++.h>
using namespace std;
int n,a[110],ok[100010][110],sum;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	ok[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=sum;j++)
		{
			if(ok[j][i-1])
			{
				ok[j+a[i]][i]=1;
				ok[abs(j-a[i])][i]=1;
				ok[j][i]=1;
			}
		}
		ok[a[i]][i]=1;
	}
	int ans=0;
	for(int i=1;i<=sum;i++)
		if(ok[i][n]) ans++;
	cout<<ans;
	return 0;
}
