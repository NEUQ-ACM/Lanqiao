#include<bits/stdc++.h>
using namespace std;
int num[21];
long long a;
void s(long long a)
{
    int cnt=1;
    while(a)
    {
        if(a&1)num[cnt]++;
        cnt++;
        a>>=1;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(num,0,sizeof(num));
        int n,sum=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a;
            s(a); //预处理
            sum^=a;//位操作
        }
        if(!sum)puts("0");
        else
        {
            for(int i=20;i>0;i--)
            if(num[i]==1)
            {
                puts("1");
                break;
            }
            else if(num[i]%2==1)
            {
                if(n%2==1)
                {
                    puts("1");
                    break;
                }
                else if(n%2==0)
                {
                    puts("-1");
                    break;
                }
            }
        }
    }
    return 0;
}
