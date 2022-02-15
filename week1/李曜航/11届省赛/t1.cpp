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
int main() 
{
    int n;
    scanf("%d", &n);
    int mx = -1, mi = 101, sum = 0;
    for (int i = 0; i < n; i++) 
    {
        int x;
        scanf("%d", &x);
        mx = max(mx, x);
        mi = min(mi, x);
        sum += x;
    }
    printf("%d\n", mx);
    printf("%d\n", mi);
    printf("%.2f\n", 1.0 * sum / n);
    return 0;
}

