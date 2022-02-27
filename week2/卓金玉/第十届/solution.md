# 蓝桥杯 第十届 省赛 A组
## 外卖店优先级
### 思路
模拟题，思路很简单，把每家店获取订单的时刻以链表形式存储起来，然后对每家店的订单时间排序，开始模拟，注意同一时刻可能来多条订单。注意随着优先级的下降调整优先缓存。

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
vector<int> a[maxn];
int main()
{
    int n, m, t;
    cin >> n >> m >> t;

    int ts, id, cnt = 0;
    for (int i = 0; i < m; ++i)
    {
        cin >> ts >> id;
        a[id].push_back(ts);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i].size())
        {
            sort(a[i].begin(), a[i].end());
            bool flag = 0;
            int temp = 0;
            for (int j = 0; j < a[i].size(); ++j)
            {

                if (j == 0)
                    temp += 2;
                else
                {
                    if (a[i][j] != a[i][j - 1])
                        temp = temp - (a[i][j] - a[i][j - 1] - 1);
                    if (temp < 0)
                    {
                        temp = 0;
                        flag = 0;
                    }
                    else if (temp <= 3)
                        flag = 0;
                    temp += 2;
                    if (temp > 5)
                        flag = 1;
                }
            }
            if (t != a[i][a[i].size() - 1])
                temp = temp - (t - a[i][a[i].size() - 1]);
            if (temp < 0)
            {
                temp = 0;
                flag = 0;
            }
            else if (temp <= 3)
                flag = 0;
            cnt += flag;
        }
    }
    cout << cnt << endl;
    return 0;
}
```
## 完全二叉树的权值
### 思路
感觉很简单的题，把树每层的节点值加起来比大小就可以了，数据好像也很友善不会超时超限，就注意会爆int用longlong存储，再考虑有负数情况，但是莫名其妙卡了两个测试点不知道错在哪

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[100005];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int maxLayer = 1, maxn = -100005, k = 0;
    for (int i = 1; i <= log2(n + 1); i++)
    {
        int temp = 0;
        for (int j = 0; j < pow(2, i - 1); j++)
            temp += a[k++];
        if (temp > maxn)
        {
            maxn = temp;
            maxLayer = i;
        }
    }
    cout << maxLayer;
    return 0;
}
```

## 修改数组
### 思路
之前试着用set暴力解，果然tle了。

后来用并查集，还是有两个测试点没过

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
int n, f[maxn], a[maxn];
int find(int x)
{
    if (x == f[x])
    {
        return f[x];
    }
    else
    {
        return f[x] = find(f[x]);
    }
}
void merge(int x, int y)
{
    int findx = find(x);
    int findy = find(y);
    if (findx == findy)
    {
        return;
    }
    else if (findx < findy)
    {
        f[findx] = findy;
    }
    else
    {
        f[findy] = findx;
    }
    return;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int re = find(a[i]);
        merge(re, re + 1);
        if (i == 1)
        {
            cout << re;
        }
        else
        {
            cout << " " << re;
        }
    }
    cout << endl;
    return 0;
}

```
