#include<bits/stdc++.h>
using namespace std;
long long dis[2050][2050];
bool jud[2050];
long long jl[2050];

int gbs(int a,int b)
{
	
	return b?gbs(b,a%b):a;
}

void djs()
{
	memset(jl,0x3f,sizeof(jl));
	jl[1]=0;
	for(int k=0;k<2021;k++)
	{
		int u=0;
		for(int i=1;i<2021;i++) if(!jud[i]&&jl[i]<jl[u]) u=i;
		jud[u]=1;
		for(int i=1;i<=2021;i++) jl[i]=min(jl[i],jl[u]+dis[u][i]);
	}
}
 
int main()
{
	for(int i=1;i<=2021;i++)
	{
		for(int j=1;j<=2021;j++) 
		{
			if(abs(i-j)>21) dis[i][j]=dis[j][i]=1e9;
			else dis[i][j]=dis[j][i]=i*j/gbs(i,j);
		}
	}
	djs();
	cout<<jl[2021];
	return 0;
}
