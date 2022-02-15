#include<bits/stdc++.h>
using namespace std;
long long x;
int num[25];
void getnum()
{
	int cnt=1;
	while(x)
	{
		if(x&1)
		num[cnt]++;
		x>>=1;
		cnt++;
	}
}
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(num,0,sizeof(num));
		for(int i=1;i<=n;i++)
		{
			cin>>x;
			getnum();
		}
		int k=0;
		for(k=1;num[k]>0;k++);
		k--;
		while(1)
		{
			if(k==0)
			{
				cout<<0<<endl;
				break;
			}
			else if(num[k]==1)
			{
				cout<<1<<endl;
				break;
			}
			else if(num[k]%2!=0)
			{
				if(n%2==0)
				{
					cout<<-1<<endl;
					break;
				}
				else
				{
					cout<<1<<endl;
					break;
				}
			}
			else if(num[k]%2==0)
			{
				k--;
				continue;
			}
		}
	}
}
