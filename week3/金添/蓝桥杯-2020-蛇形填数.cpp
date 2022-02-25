#include <bits/stdc++.h>
using namespace std;
// http://oj.ecustacm.cn/problem.php?id=1510
int main()
{
    int ans=1;

    for(int i=1;i<=19;i++)
        ans+=(i*4);
    cout<<ans;
    return 0;
}