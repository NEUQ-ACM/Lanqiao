#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,w[200],f[200007],g[200007];
int main() {
    cin>>n;
    for(int i=1;i<=n;++i) cin>>w[i];
    f[100000]=1;
    for(int i=1;i<=n;++i) {
        for(int j=0;j<=200000;++j) {
            if(f[j]==1) {
                if(j-w[i]>=0) g[j-w[i]]=1;
                if(j+w[i]<=200000) g[j+w[i]]=1;
            }
        }
        for(int j=0;j<=200000;++j) f[j]=max(f[j],g[j]),g[j]=0;
    }
    int ans=0;
    for(int i=100001;i<=200000;++i) ans+=f[i];
    cout<<ans;
    return 0;
}