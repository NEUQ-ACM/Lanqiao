#include <bits/stdc++.h>

using namespace std;

const int N=110,M=200010,B=M/2;

int a[N],n;
bool f[M],t[M];

int main()
{
    cin>>n;
    int m=0;
    for(int i=1;i<=n;i++) cin>>a[i],m+=a[i];
    
    f[B]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=-m;j<=m;j++)
            if(f[j+B]) 
            {
                t[j+B]=true;
                t[j+a[i]+B]=t[j-a[i]+B]=true;
            }
        memcpy(f,t,sizeof t);
    }
    
    int res=0;
    for(int i=1;i<=m;i++) res+=f[i+B];
    cout<<res<<endl;
    
    return 0;
}
