/*
提交时间	02-09 21:32:28
评测结果	正确
得分	100
CPU使用	109ms
内存使用	2.800MB
*/
#include<bits/stdc++.h>
using namespace std;
int T;
int a[32];

int main()
{
	cin>>T;
	while(T--)
	{
		memset(a,0,sizeof(a));
		int n;
		cin>>n;
		int ans=0;
		for(int j=0;j<n;j++)
		{
			int x;
			cin>>x;
			ans^=x;
			for(int i=1;i<=30&&x;i++)
			{
				if(x&1) a[i]++;
				x>>=1;
			}
		}
		if(!ans) cout<<0<<endl;
		else
		{
			for(int i=30;i>0;i--)
			{
				if(a[i]==1)
				{
					cout<<1<<endl;
					break;
				}
				else if(a[i]&1)
				{
					if(n&1) cout<<1<<endl;
					else cout<<-1<<endl;
					break;
				}
			}
		} 
	}
	return 0;
}
