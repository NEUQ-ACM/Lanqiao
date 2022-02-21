#include <bits/stdc++.h>
using namespace std;
// https://www.lanqiao.cn/courses/2786/learning/?id=67813
long long ans1 = 0;
long long ans2 = 0;
bool judge(int n)
{
    while (n)
    {
        int remp = n % 10;
        if (remp == 1 || remp == 2 || remp == 0 || remp == 9)
            return true;
        n /= 10;
    }
    return false;
}
int main()
{
    for (int i = 1; i <= 2019; i++)
    {
        if(judge(i))
        {
            ans1+=i;
            ans2+=i*i;
        }
    }
    cout<<ans2;
        return 0;
}