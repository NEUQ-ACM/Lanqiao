#include <bits/stdc++.h>
using namespace std;
// ????http://oj.ecustacm.cn/problem.php?id=1508
int find(int n)
{
    int a=0;
    while(n)
    {
        if(n%10==2)
            a++;
        n/=10;
    }
    return a;
}
int main()
{
    long long ans=0;
    for(int i=1;i<=2020;i++)
    {
        ans+=find(i);
    }
    cout<<ans;
    return 0;
}