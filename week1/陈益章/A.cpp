#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[10],i=0;
    memset(a,0,sizeof(a));
    while(++i)
    {
        int flag=0;
        string num=to_string(i);
        for(int j=0;j<num.size();j++)
        {
            a[num[j]-'0']++;
            if(a[num[j]-'0']>2021)
            {
                flag=1;
                break;
            }
        }
        if(flag==1) break;
    }
    cout<<i-1;
    return 0;
}
