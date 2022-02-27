#include <bits/stdc++.h>
using namespace std;
#define LL long long
int main()
{
	int n,x;
	cin>>n;
	int deep = 1;
	map<int,int> mp;
	for(int i=1;i<=30;++i)
	{
		mp[(1<<i)-1] = i;
	} 
	LL sum = 0;
	LL MaxSum = -100000000000000000ll;
	int ans;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		sum += x;
		if(mp.count(i))
		{
			if(sum>MaxSum) MaxSum = sum,ans = mp[i]; 
			sum = 0;	
		}
	} 
	cout<<ans<<endl;
	return 0;	
} 
