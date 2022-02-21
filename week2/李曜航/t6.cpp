#include <iostream>
#include <algorithm>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
int node[200000];
int maxfloor = 1;
int floor[5000];
int n;
void dfs(int x, int dept)
{
    if (x > n)
        return;
    
    floor[dept] += node[x]; 
    maxfloor = max(maxfloor, dept);
    
    dfs(x << 1, dept + 1);
    dfs(x << 1 | 1, dept + 1);
}
int main()
{
    // freopen("read.in","r",stdin);
    n = read();
    for(int i=1;i<=n;i++)
    	node[i] = read();
    dfs(1,1);
    	
    int ans = 1;
    for(int i=maxfloor;i>=1;i--)
    	if(floor[i]>=floor[ans])
    		ans = i;
    cout<<ans;

}