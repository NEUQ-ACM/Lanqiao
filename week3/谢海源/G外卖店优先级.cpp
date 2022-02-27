#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=100005;
int n,m,t;
int ts,id;
vector<int>ve[maxn];
vector<int>pq;//优先缓存
int p[maxn]={};//每家店的优先级
bool v[maxn];
signed main()
{
	cin>>n>>m>>t;
	for(int i=0;i<m;i++)
	{
		cin>>ts>>id;
		ve[ts].push_back(id);
	}
	
	for(int i=1;i<=t;i++)//时刻i
	{
		memset(v,0,sizeof(v));//初始化标记
		for(int j=0;j<ve[i].size();j++)
		{
			int it=ve[i][j];
			v[it]=1;//有订单
			p[it]+=2;//优先级加2
		}
		for(int j=1;j<=n;j++)//遍历n个店
		{
			if(v[j]==0&&p[j]>0) p[j]--;
			
			if(p[j]>5) pq.push_back(j);//加入优先缓存
		}
		
		for(int j=0;j<pq.size();j++)
		{
			int it=pq[j];
			if(p[it]<=3) pq.erase(pq.begin()+j);
		}
	}
	
	cout<<pq.size();
}
