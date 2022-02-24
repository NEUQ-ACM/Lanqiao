#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector <int> a;
		int sum=0,maxn=0;
		for(int i=0;i<n;i++)
		{
			int d;
			cin>>d;
			a.push_back(d);
			if(d>maxn) maxn=d;
			sum^=d;
		}
		if(sum==0)
		{
			cout<<"0";continue;
		}
		int site=0,num=0;
		while(maxn>0)
		{
			maxn>>=1;
			site++;
		}
		for(int i=0;i<n;i++)
		{
			num+=(a[i]>>site);
		}
		if(!num%2) cout<<"1";
		else cout<<"-1";
	}
	return 0;
}
