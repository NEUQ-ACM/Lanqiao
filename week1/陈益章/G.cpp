#include<bits/stdc++.h>
using namespace std;
int num[60]={0};

void add(int x)
{
    int cnt=0;
    while(x>0)
    {
        if(x&1) num[cnt]++;
        cnt++;
        x=x>>1;
    }
}

int main()
{
    int T,n,a,b;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        int sum=0,temp;
        memset(num,0,sizeof(num));
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>temp;
            add(temp);
            sum=sum^temp;
        }
        if(sum==0)
        {
            cout<<"0\n";
            continue;
        }
        int ans=0,p=0;
        for(int j=30;j>=0;j--)
        {
            if(num[j]%2==1)
            {
                p=j;
                break;
            }
        }
        if(n%2==1 || num[p]==1) cout<<"1\n";
        else cout<<"-1\n";
    }
    return 0;
}