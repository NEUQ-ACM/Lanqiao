#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int weight[2022][2022];
int visit[2022];
int ans[2022];
int gcd(int x,int y)
{
	if(x%y==0)
	{
		return y;
	}
	return gcd(y,x%y);
}
int lcm(int x,int y)
{
	return x*y/gcd(x,y);
}
int main()
{
	memset(weight,INF,sizeof(weight));
	memset(ans,INF,sizeof(ans));
	memset(visit,0,sizeof(visit));
	for(int i=1;i<=2021;i++)
	{
		for(int j=i+1;j<=2021;j++)
		{
			if(j-i>21)
			{
				continue;
			}
			weight[i][j]=lcm(i,j);
			weight[j][i]=lcm(i,j);
		}
	}	
	ans[1]=0;
	for(int i=1;i<=2021;i++)
	{
		int start;
		int Min=INF;
		for(int j=1;j<=2021;j++)
		{
			if(!visit[j]&&ans[j]<=Min)
			{
				Min=ans[j];
				start=j;
			}
		}
		visit[start]=1;
		for(int j=1;j<=2021;j++)
		{
			ans[j]=min(ans[j],ans[start]+weight[start][j]);
		}
	}
	cout<<ans[2021];
	return 0; 
}
