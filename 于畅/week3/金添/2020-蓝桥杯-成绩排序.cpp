#include <bits/stdc++.h>
using namespace std;
// https://www.dotcpp.com/oj/problem2591.html
// 注意四舍五入的写法
// ans1 = lower_bound(a + 1, a + 1 + n, 85) - a-1;
// 后面要多减去1，因为数组从1开始存数
int a[10000];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int ans1 = lower_bound(a + 1, a + 1 + n, 85) - a-1;
    int ans2 = lower_bound(a + 1, a + n + 1, 60) - a-1;
    double a1=n-ans1;
    double a2=n-ans2;
    a1=a1/n*100;
    a2=a2/n*100;
    a2=int(a2+0.5);
    a1=int(a1+0.5);
    cout<<a2<<"%"<<endl;
    cout<<a1<<"%";
    return 0;
}