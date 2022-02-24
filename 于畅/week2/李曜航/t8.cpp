#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
int a[150000];
bool vis[1000010];
map <int, int> m;
int main()
{
    // freopen("read.in","r",stdin);
    int n = read();
	for(int i=1;i<=n;i++)
	{
		int x = read();
		while(m.count(x))
		{
			x++;
		}
		m[x] = 1;
		cout<<x<<" ";
	}

}