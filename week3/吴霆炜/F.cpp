#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int a[100005];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int level=1;
    ll MAX=a[1];
    ll res=1;
    int num=1;
    int pos=2;
    for(;;)
    {
        level++;
        num*=2;
        ll sum=0;
        for(int j=pos;j<=min(pos+num-1,n);j++)sum+=a[j];
        if(sum>MAX)
        {
            res=level;
            MAX=sum;
        }
        pos=pos+num;
        if(pos>n)break;
    }
    printf("%lld\n",res);
    return 0;
}