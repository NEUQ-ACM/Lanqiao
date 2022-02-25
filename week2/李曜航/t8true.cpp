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
#define ll long long
const int N=1e6+5;
int p[N], a[N];
int find(int x)
{
	if(x!=p[x]) p[x]=find(p[x]);
	return p[x]; 
}
int main()
{
	int n = read();
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=N;i++) p[i]=i;
	for(int i=1;i<=n;i++)
	{
		a[i]=find(a[i]);
		p[a[i]]=find(a[i]+1);
	}
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
}