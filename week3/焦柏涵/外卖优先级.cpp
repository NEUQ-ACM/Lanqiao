#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pa;
int main()
{
	int n,m,t,val[1001],post[1001];
	bool st[1001];
	pa a[1001];
	cin>>n>>m>>t;
	for(int i=0;i<m;i++)
	{
		int ts,id;
		cin>>ts,id;
		a[i]={ts,id};
	}
	sort(a,a+m);
	for(int i=0;i<m;)
	{
		int j=i;
		while(j<m&&a[i]==a[j]) j++;
		int num=j-i,ti=a[i].first,di=a[i].second;
		val[di]-=ti-post[di]-1;
		if(val[di]<0) val[di]=0;
		if(val[di]<=3) st[di]=false;
		val[di]+=num*2;
		if(val[di]>5) st[di]=true;
		post[di]=ti;
		i=j;
	}
	for(int i=01;i<=n;i++)
	{
		if(post[i]<t)
		{
			val[i]-=t-post[i];
			if(val[i]<0) val[i]=0;
			if(val[i]<=3) st[i]=false;
		}
	}
	int w=0;
	for(int i=1;i<=n;i++)
	{
		if(st[i]) w++;
	}
	cout<<w<<endl;
	return 0;
}
