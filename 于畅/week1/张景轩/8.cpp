#include<bits/stdc++.h>
using namespace std;

const int maxn = 100001;
int f[maxn], n;
vector<int> v[maxn];

int dfs(int x) 
{
    int re = 1;

    for (int i = 0; i < v[x].size(); i++) 
    {
        int temp = 1 + dfs(v[x][i]) + v[x].size() - 1;
        re = max(temp, re);
    }
    return re;
}

int main() {
    cin>>n;
    for (int i = 0; i < n - 1; i++) 
    {
        cin>>f[i];
        v[f[i]].push_back(i + 2);
    }
    cout<<dfs(1)-1<<endl;
    return 0;
}
