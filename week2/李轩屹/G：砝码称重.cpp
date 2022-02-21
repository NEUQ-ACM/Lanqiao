#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int n;
int ans=0;
int w[105];
int v[100005];//记录某个重量可否称到
map<int,int>lo[105];//用于剪枝
//now表示当前处理到第now个砝码
//suml表示当前左边重量
//sumr表示当前左边重量
void dfs(int now,int suml,int sumr)
{
	if(suml-sumr>0)v[suml-sumr]=1;
	if(lo[now][suml-sumr]==1)return;
    //若到第now个砝码时左右相差suml-sumr的情况出现过就不用再往下重复计算了
	lo[now][suml-sumr]=1;
	if(now==n)return;
	dfs(now+1,suml,sumr);//不选择当前砝码
	dfs(now+1,suml+w[now+1],sumr);//将当前砝码加到左边
	dfs(now+1,suml,sumr+w[now+1]);//将当前砝码加到右边
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	sort(w+1,w+1+n);//不排序只有80
	dfs(1,0,0);
	dfs(1,w[1],0);
	dfs(1,0,w[1]);
	for(int i=1;i<=100000;i++)
	{
		if(v[i]==1)ans++;
	}
	cout<<ans;
	return 0;
}
