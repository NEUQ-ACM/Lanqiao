#include<bits/stdc++.h>
using namespace std;
const int maxn = 100052;
typedef long long int qq;
vector<int>a[maxn];
int n,m,t;
bool f(int x){
    if(a[x].size()==0)return 0;
    bool ret=0;
    int now=2;
    for(int i=1;i<a[x].size();i++){
        now= max(0, now -(a[x][i]-a[x][i-1]-1) );
        if(now<=3) ret=0;
        now+=2;
        if(now>5) ret=1;
    }
    now= max(0, now -(t-a[x][a[x].size()-1]));
    if(now<=3) ret=0;
    return ret;
}
int main(){
    scanf("%d%d%d",&n,&m,&t);
    while(m--){
        int ts,id;
        scanf("%d%d",&ts,&id);
        a[id].push_back(ts);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(f(i)==true)ans++;
    }
    printf("%d\n",ans);
    return 0;
}


