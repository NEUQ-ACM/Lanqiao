#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef long long LL;

int main()
{
    int n,a[200000],temp=0,maxsum=0,cnt,ans=0;

    cin>>n;

    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++)
        cin>>a[i];

    for(int i=1;temp<=n;i*=2){
        int sum=0;
        for(int j=0;j<i;j++){
            sum+=a[temp];
            temp++;
        }
        if(sum>maxsum){
            maxsum=sum;
            cnt=i;
        }
    }

    while(cnt){
        cnt/=2;
        ans++;
    }

    cout<<ans;

    return 0;
}

