#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int Last[maxn];
int val[maxn];
bool in[maxn];
int main()
{
	int n,m,T;
	vector<pair<int,int> > vii;
	int pt,id;
	scanf("%d%d%d",&n,&m,&T);
	while(m--)
	{
		scanf("%d%d",&pt,&id);
		vii.push_back(make_pair(pt,id));	
	} 
	sort(vii.begin(),vii.end());
	for(auto x:vii) 
	{
		id = x.second;
		pt = x.first;
		if(Last[id])
		{
			val[id] = max(0,val[id]-(pt-Last[id])+1);
		}
		val[id] += 2;
		if(val[id]>5) in[id] = true;
		Last[id] = pt;
	}
	int cnt = 0;
	for(int i=1;i<=n;++i)
	{
		if(!Last[i]||!in[i]) continue;
		val[i] -= (T-Last[i]);
		if(val[i]>3) ++cnt;
	}
	printf("%d\n",cnt);
		
} 
