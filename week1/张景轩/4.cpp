#include<iostream>
#include<cstring>
using namespace std;

const int N = 2050;
int g[N][N],n;
bool st[N];
int dis[N];

int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}

void djs()
{
    memset(dis,0x3d,sizeof(dis));
    dis[1] = 0;
    for(int k=0;k<n;k++)
    {
        int u = 0;
        for(int i=0;i<=n;i++)
        {
            if(!st[i] && dis[i]<dis[u])
            {
                u = i;
            }
        }
        st[u] = true;
        if(u == 2021)
        {
            break;
        }
        for(int i=1;i<=n;i++)
        {
            dis[i] = min(dis[i],dis[u]+g[u][i]);
        }
    }
}


int main()
{
    n = 2021;
    for(int i=1;i<N;i++)
    {
        for(int j=i;j<N;j++)
        {
            if(j-i>21)
            {
                g[i][j] = g[j][i] = 0x3f3f3f3f;
            }
            else
            {
                g[i][j] = g[j][i] = i*j/gcd(i,j);
            }
        }
    }
    djs();

    cout<<dis[n];

    return 0;
}