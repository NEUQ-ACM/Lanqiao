#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int fa[N],level[N]={0};
vector<int>p[N];
vector<int>q[N];
int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin>>n;
	level[0]=0;
	level[1]=0;
	q[0].push_back(1);
	for(int i=2;i<=n;i++)
	{
		cin>>fa[i];
		level[i]=level[fa[i]]+1;
		//cout<<level[i]<<" ";
		q[level[i]].push_back(i);
		p[fa[i]].push_back(i);	
	}
	int ans=0,Max=-99999;
	for(int i=0;q[i].size();i++){
		Max=-99999;
		for(int j=0;j<q[i].size();j++){
			int m=(int)p[q[i][j]].size();
		//	cout<<m<<" ";
			Max=max(Max,m);
		}
		//cout<<endl<<Max<<endl;
		ans+=Max;
	}
	cout<<ans<<endl;
} 
