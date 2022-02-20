#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int num[23];
void get(ll x)
{
	int cnt=1;
	while(x)
	{
		if(x&1){num[cnt]++;}
		cnt++;
		x>>=1;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(num,0,sizeof(num));
		int ans=0;
		int n;
		scanf("%d",&n);
		ll x;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&x);
			get(x);
			ans^=x;
		}
		if(ans==0){printf("0\n");}
		else
		{
				for(int i=20;i>0;i--)
				{
					if(num[i]==1)
					{
						printf("1\n");
						break;
					}
					if(num[i]%2==1)
					{
						if(n%2==1)
						{
							printf("1\n");break;
						}
						else 
						{
							printf("-1\n");break;
						}
					}
				}	
		}
	}
}
