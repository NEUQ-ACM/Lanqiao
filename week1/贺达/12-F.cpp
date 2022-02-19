#include<bits/stdc++.h>
using namespace std;
int a[110];
bool b[105][200010];
int sum = 0;
int main()
{
    int n;
    cin>>n;
    b[0][0] = true;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum = sum + a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j = 0;j<=sum;j++)
        {
           b[i][j] = b[i-1][j]||b[i-1][j+a[i]]||b[i-1][abs(j-a[i])];
           //或运算处理数组，标记选中个数
        }
    }
    int res = 0;
    for(int i = 1;i<=sum;i++)
    {
        if(b[n][i] == true)
        {
            res++;
        }
    }
    cout<<res;
    return 0;
}
