#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;
ll read()
{
    ll f=1, x=0;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=ch-'0'+x*10;ch=getchar();}
    return f*x;
}
using namespace std;
const int MAXN = 100010;
int lc[30];
int rc[30];
int r[MAXN];
char s[MAXN];
int main()
{
    cin>>s;
    int len = strlen(s);
    for (int i = 0; i < 26; ++i)
    {
        lc[i] = -1;
        rc[i] = len;
    }
    for (int i=0; i<len; i++)
        r[i] = len;

    for (int i=len-1; i>=0; i++)
    {
        r[i] = rc[s[i] - 'a'];
        rc[s[i] - 'a'] = i;
    }
    ll ans = 0;
    for (int i=0; i<len; i++)
    {
        ans += (i - lc[s[i] - 'a']) * (r[i] - i);
        lc[s[i] - 'a'] = i;
    }
    printf("%lld\n", ans);
    return 0;
}
