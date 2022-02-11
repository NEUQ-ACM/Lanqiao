//10266837
#include<bits/stdc++.h>
using namespace std;

struct Edge
{
	int from,to,w;
};
vector<Edge>vec[2025];
queue<int>q;
int vis[2025],dis[2025];
int gcd(int a,int b)
{
	if(a%b==0) return b;
	gcd(b,a%b);
}
int lcm(int a,int b)
{
	return a*b/gcd(a,b);
}

void spfa(int start)
{
	q.push(start);
	dis[start]=0;
	while(q.size())
	{
		int now=q.front();
		q.pop();
		vis[now]=0;
		for(int i=0;i<vec[now].size();i++)
		{
			if(dis[vec[now][i].to]>dis[now]+vec[now][i].w)
				dis[vec[now][i].to]=dis[now]+vec[now][i].w;
			if(!vis[vec[now][i].to])
			{
				vis[vec[now][i].to]=1;
				q.push(vec[now][i].to);
			}
		}
	}
}
int main()
{
	for(int i=1;i<2021;i++)
	{
		for(int j=i+1;j<=i+21&&j<=2021;j++)
		{
			Edge edge;
			edge.from=i;
			edge.to=j;
			edge.w=lcm(i,j);
			//cout<<i<<' '<<j<<' '<<lcm(i,j)<<endl;
			vec[i].push_back(edge);
		}
	}
	for(int i=1;i<2025;i++) dis[i]=0x7ffffff;
	spfa(1);
	cout<<dis[2021];
	return 0;
}
