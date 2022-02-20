#include<bits/stdc++.h>
#define N 2050
using namespace std;

int g[N][N], dis[N], n=2021;
bool edge[N];

int gcd(int a, int b)
	{
		if(b==0)
			return a;
		return gcd(b, a%b);
	}
int main(void)
{
	for(int i=1; i<N; i++)
		for(int j=i; j<N; j++)
		{
			if(j-i>21)
				g[i][j]=g[j][i]=9999999999;
			else
				g[i][j]=g[j][i]=i*j/gcd(i, j);
		}
	
	memset(dis, 63, sizeof(dis));
	dis[1]=0;
	for(int k=0; k<n; k++)
	{
        int u=0;
        for(int i=1; i<=n; i++)
            if(!edge[i] && dis[i]<dis[u])
				u=i;
		
        edge[u]=1;
        if(u==2021)
			break;
			
        for(int i=1;i<=n;i++)
			dis[i]=min(dis[i],dis[u]+g[u][i]);
    }
	cout<<dis[n];
	
	return 0;
}