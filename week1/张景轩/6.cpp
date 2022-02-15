#include<iostream>
#include<cstring>
using namespace std;

const int N=110,M=2000001,B=M/2;
int a[N],n;
bool f[M],t[M];

int main()
{
    cin>>n;
    int m=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        m = m + a[i];
    }
    f[B] = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j=-m;j<=m;j++)
        {
            if(f[j+B])
            {
                t[j+B] = true;
                t[j+a[i]+B] = t[j-a[i]+B] = true;
            }
        }
        memcpy(f,t,sizeof(t));
    }
    int ans = 0;
    for(int i=1;i<=m;i++)
    {
        ans = ans + f[i+B];
    }
    cout<<ans<<endl;

    return 0;
}