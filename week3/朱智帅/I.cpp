/*
Author: xzc
2019/4/5
2019第十届蓝桥杯省赛C++A组 I题糖果
前会长Y_Cl亲自帮我对拍的，AC了~ 
*/
#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
#define Mst(a,b) memset(a,(b),sizeof(a))
using namespace std;
int dp[1<<20]; //二进制状态压缩 
int a[105];
int main()
{
	//freopen("in.txt","r",stdin);
	int m,n,k;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		set<int> v; //记录n包中所有糖果的种类数 
		memset(dp,0x3f,sizeof(int)*(1<<m)); //初始化 
		dp[0] = 0;
		For(i,1,n)
		{
			int x = 0,y;
			For(j,1,k)
			{
				scanf("%d",&y);
				--y;
				v.insert(y);
				x |= (1<<y);
			}
			a[i] = x; //x的二进制形式第i位为1代表这个集合中有第i+1种糖果 
			dp[x] = 1;//这种状态只需要第i包糖果1包就可以达到 
		}
		if((int)v.size()<m) //把n包唐都买了也吃不到m中糖果 
		{
			printf("-1\n");continue;
		}
		int ed = (1<<m)-1; //目标状态 
		For(i,1,n)
		{
			For(state,0,ed)
			{
				if(dp[state]>200) continue; //用已有的状态去更新加上第i包糖果后的状态 
				int to = a[i]|state;
				dp[to] = min(dp[to],1+dp[state]);
			}
		}
		printf("%d\n",dp[ed]); 
	}
	
	return 0;
}