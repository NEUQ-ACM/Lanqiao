#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef long long LL;

pair<int,int> infor[100002];
int pr[100002],re[100002];
bool ok[100002];

int main()
{
    memset(pr,0,sizeof(pr));
    memset(re,0,sizeof(re));
    memset(ok,0,sizeof(ok));

    int n,m,t,cnt=0;

    cin>>n>>m>>t;

    for(int i=1;i<=m;i++)
        cin>>infor[i].first>>infor[i].second;

    sort(infor+1,infor+m+1);

    for(int i=1;i<=m;i++){
        if(infor[i].first!=re[infor[i].second])
            pr[infor[i].second]=pr[infor[i].second]-(infor[i].first-re[infor[i].second]-1);
        if(pr[infor[i].second]<0) pr[infor[i].second]=0;
        if(pr[infor[i].second]<=3&&ok[infor[i].second]){
            ok[infor[i].second]=0;
            cnt--;
        }
        pr[infor[i].second]+=2;
        if(pr[infor[i].second]>5&&!ok[infor[i].second]){
            ok[infor[i].second]=1;
            cnt++;
        }
        re[infor[i].second]=infor[i].first;
    }

    for(int i=1;i<=n;i++){
        pr[i]=pr[i]-(t-re[i]);
        if(pr[i]<=3&&ok[i]) cnt--;
    }

    cout<<cnt;

    return 0;
}

