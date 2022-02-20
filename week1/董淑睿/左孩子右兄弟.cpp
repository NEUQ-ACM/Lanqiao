#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _=1e5+7;
vector<int> G[_];
int f[_];
void dfs(int u) {
    for(int i=0;i!=G[u].size();++i) {
        int v=G[u][i];
        dfs(v);
        f[u]=max(f[u],f[v]);
    }
    f[u]=f[u]+(int)G[u].size();
}
int main() {
    int n;cin>>n;
    for(int i=2;i<=n;++i) {
        int x;cin>>x;
        G[x].push_back(i);
    }
    dfs(1);
    cout<<f[1];
    return 0;
}