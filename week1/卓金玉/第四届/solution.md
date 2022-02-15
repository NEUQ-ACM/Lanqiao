# 蓝桥杯 第四届 省赛 A组
## 剪格子
### 思路
用dfs，如果走过的格子的值加总等于总和的一半则记录步数，最后选取最小步数输出。本题dfs要注意重复经过原点的情况。
### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int n, m, sum = 0;
int minnum = 9999;
bool vis[11][11];
int a[11][11];
void dfs(int i, int j, int cnt, int item)
{
    if (item == sum / 2)
    {
        if (cnt < minnum)
        {
            minnum = cnt;
        }
    }
    if (i + 1 < n && vis[i + 1][j] && item < sum / 2)
    {
        vis[i + 1][j] = 0;
        dfs(i + 1, j, cnt + 1, item + a[i + 1][j]);
        vis[i + 1][j] = 1;
    } //下
    if (j + 1 < m && vis[i][j + 1] && item < sum / 2)
    {
        vis[i][j + 1] = 0;
        dfs(i, j + 1, cnt + 1, item + a[i][j + 1]);
        vis[i][j + 1] = 1;
    } //右
    if (i - 1 >= 0 && vis[i - 1][j] && item < sum / 2)
    {
        vis[i - 1][j] = 0;
        dfs(i - 1, j, cnt + 1, item + a[i - 1][j]);
        vis[i - 1][j] = 1;
    }
    if (j - 1 >= 0 && vis[i][j - 1] && item < sum / 2)
    {
        vis[i][j - 1] = 0;
        dfs(i, j - 1, cnt + 1, item + a[i][j - 1]);
        vis[i][j - 1] = 1;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
            sum += a[i][j];
        }
    }
    memset(vis, 1, sizeof(vis));
    vis[0][0] = 0;
    dfs(0, 0, 1, a[0][0]);
    cout << minnum << endl;
    return 0;
}
```
## 错误票据
### 思路
因为本题数据最多只有100个，但每个数字的值可能会很大，于是把每个数字对100取余，并记录被100除过的商，建立长度为100的数组，这样就可以利用下标储存访问状态。之后暴力查找重复数和缺少的数，将下标还原为原始数据输出即可

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a[150], temp, k = -1, lit, m = 0, n = 0;
    memset(a, 0, sizeof(a));
    cin >> lit;
    while (cin >> temp)
    {
        a[temp % 100]++;
    }
    lit = temp / 100;
    bool flag = 1;
    for (int i = 0; i < 100; ++i)
    {
        if (a[i] == 0 && flag)
            continue;
        else
        {
            flag = 0;
        }
        if (a[i] == 0 && m == 0)
        {
            m = i + lit * 100;
        }
        else if (a[i] > 1)
        {
            n = i + lit * 100;
        }
    }
    cout << m << " " << n;
    return 0;
}
```

## 大臣的旅费
### 思路
把因为本题n座城市有n-1条路相连，所以可以看作一棵树，因此本题可以转换为求一棵有权树的最大直径，再根据题意计算路费即可
有权树用临界矩阵储存，用到的数据结构是二维vector，里面储存结构体，表示有权树。
找树的直径的方法是，先任选一个节点为起点dfs找最长的距离，再从这段距离的终点处进行第二遍dfs，第二遍dfs得出的结果即是整条树的直径。
### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int vis[10004];
int dis[10004];
typedef struct node
{
    int x;
    int y;
} NODE;
vector<NODE> edge[10004];
void dfs(int st)
{
    for (int i = 0; i < edge[st].size(); i++)
    {
        int to = edge[st][i].x;
        if (!vis[to])
        {
            vis[to] = 1;
            vis[st] = 1;
            dis[to] = dis[st] + edge[st][i].y;
            // cout << "dis[" << to << "] = " << dis[to] << endl;
            dfs(to);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        NODE nd;
        nd.x = b;
        nd.y = c;
        edge[a].push_back(nd);
        nd.x = a;
        edge[b].push_back(nd);
    }
    memset(dis, 0, sizeof(dis));
    dfs(1);
    int maxlen = 0, Q, W, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] > maxlen)
            maxlen = dis[i], Q = i;
        dis[i] = vis[i] = 0;
    }
    dfs(Q);
    for (int i = 1; i <= n; i++)
        if (dis[i] > ans)
            ans = dis[i];
    // cout << ans << endl;
    cout << (11 + ans + 10) * ans / 2 << endl;
    return 0;
}
```


## 买不到的数目
### 思路
数论知识，不能覆盖到的最大的数是a*b-a-b，带入公式计算即可

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    cin >> a >> b;
    cout << a * b - a - b << endl;
    return 0;
}
```
## 带分数
### 思路
用dfs全排列，然后计算是否符合带分数的条件，如果符合cnt+1。
### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
bool vis[10];
int a[10], num, cnt = 0;
int cal(int l, int r)
{
    int re = 0;
    for (int i = l; i <= r; ++i)
    {
        re = 10 * re + a[i];
    }
    return re;
}
int dfs(int n)
{
    if (n == 9) //边界
    {
        for (int i = 0; i < 7; ++i)
        {
            for (int j = i + 1; j < 8; ++j)
            {
                int a = cal(0, i), b = cal(i + 1, j), c = cal(j + 1, 8);
                if (a * c + b == c * num)
                {
                    cnt++;
                }
            }
        }
    }
    for (int i = 1; i < 10; ++i)
    {
        if (vis[i] == 0)
        {
            vis[i] = 1;
            a[n] = i;
            dfs(n + 1);
            vis[i] = 0; //回溯
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int a, b, c;
    cin >> num;
    dfs(0);
    cout << cnt << endl;
    return 0;
}
```