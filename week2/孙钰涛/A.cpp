#include<bits/stdc++.h>
using namespace std;
int main()
{
    int cnt=0;
    for(int i=1;i<=2020;i++)
    {
        string num=to_string(i);
        for(int j=0;j<num.size();j++)
        {
            if(num[j]=='2') cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
//624