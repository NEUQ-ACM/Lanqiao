#include <bits/stdc++.h>
using namespace std;
// https://www.lanqiao.cn/courses/2786/learning/?id=280825
// 3181
int a[9];
bool judge(int n)
{
    while (n)
    {
        int remp = n % 10;
        if (a[remp] == 0)
            return false;
        a[remp]--;
        n /= 10;
    }
    return true;
}
int main()
{
    for (int i = 0; i <= 9; i++)
    {
        a[i] = 2021;
    }
    int num = 0;
    while (judge(num+1))
    {
        num++;
    }
    cout<<num;
    return 0;
}