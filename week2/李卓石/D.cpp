#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1e5;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
struct node{
    int u,v,w;
    node(int uu,int vv,int ww) { u=uu,v=vv,w=ww; }
};
int n,dis[maxn];
vector<node>g;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) dis[i]=inf; dis[1]=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            if(j-i>21) continue;
            g.push_back( node(  i , j , i*j/gcd(i,j)  ) );//两个点以及之间的长度存入向量
        }
    for(int i=1;i<=n-1;i++)
    {
        bool f=0;
        for(int j=0;j<g.size();j++)
        {
            int u=g[j].u,v=g[j].v,w=g[j].w;
            if(dis[v]>dis[u]+w)
                f=1,dis[v]=dis[u]+w;
        }
        if(f==0) break;
    }
    printf("%d\n",dis[n]);
    return 0;
}
