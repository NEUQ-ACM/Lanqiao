#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define _ 1000007
pair<int, int> A[_];
ll n, m, t,last[_];
int ans[_];
bool first[_];   
int main() {
    cin>>n>>m>>t;
    for (int i=1;i<=m;i++) cin>>A[i].first>>A[i].second;
    sort(A+1,A+1+m);
    for (int i=1;i<=m;i++) {
        int ts=A[i].first,id=A[i].second;
        if (ts!=last[id])ans[id]=ans[id] - (ts - last[id] - 1);
        ans[id]=max(ans[id], 0);
        if (ans[id]<=3) first[id]=0;
        ans[id]+=2;
        if (ans[id] > 5) first[id]=1;
        last[id]=ts;
    }
    for (int i=1;i<=n;i++) {
        if (last[i]!=t) ans[i]=ans[i] - (t - last[i]);
        if (ans[i]<=3)  first[i]=0;
    }
    ll res=0;
    for (int i=1;i<=n;i++) if (first[i]) res++;
    cout << res;
    return 0;
}