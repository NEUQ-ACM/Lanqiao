#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int t;
int n,sum;
int x;
int num[23];
int main()
{
	cin>>t;
	while(t--)
	{
        memset(num,0,sizeof(num));
        sum=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>x;
			sum^=x;
			int cnt=1;
			while(x)
			{
				if(x&1)num[cnt]++;
				cnt++;
				x>>=1;
			}
		}
		if(!sum)cout<<"0"<<endl;
		else
		{
			for(int i=20;i>0;i--)
			{
				if(num[i]==1)
				{
					cout<<"1"<<endl;
					break;
				}
				else if(num[i]%2==1)
				{
					if(n%2==1)
					{
						cout<<"1"<<endl;
						break;
					}
					else
					{
						cout<<"-1"<<endl;
						break;
					}
				}
			}
		}
	}
	return 0;
}
