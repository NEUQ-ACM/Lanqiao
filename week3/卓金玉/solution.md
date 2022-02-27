# 蓝桥杯 第二届 省赛 A组
## 砝码称重
### 思路
dp问题，每个数有3种状态。以题目样例为例，从第二个砝码开始dp，除了继承第一个砝码的状态之外(1)，第二个砝码可以单独出现(4)、和上一个砝码求和(5)或求差(3)。据此可列状态转移方程
### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
bool vis[102][100005];
int main()
{
    int n, num, sum = 0;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i)
    {
        cin >> num; // 1 4 6
        sum += num;
        a.push_back(num);
    }
    sort(a.begin(), a.end());

    memset(vis, 0, sizeof(vis));
    vis[0][a[0]] = 1;
    int temp;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j <= sum; ++j)
        {
            if (vis[i - 1][j])
            {
                vis[i][j] = 1;
                temp = fabs(j - a[i]);
                vis[i][j + a[i]] = 1;
                vis[i][temp] = 1;
                vis[i][a[i]] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= sum; ++i)
    {
        if (vis[n - 1][i])
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
```
## 括号序列
### 思路
dp问题，本题要先记录左括号的插入方案数，再将序列倒置后记录右括号的插入方案数，最后把乘积对1e9+7取模
### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
#define N 5003
int f[N][N];
int mod = 1e9 + 7;
string s;
long long cal(int n)
{
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        if (s[i - 1] == '(')
            for (int j = 1; j <= n; j++)
                f[i][j] = f[i - 1][j - 1];
        else
        {
            f[i][0] = (f[i - 1][1] + f[i - 1][0]) % mod;
            for (int j = 1; j <= n; j++)
                f[i][j] = (f[i - 1][j + 1] + f[i][j - 1]) % mod;
        }
    for (int i = 0; i <= n; i++)
        if (f[n][i])
            return f[n][i];
    return -1;
}
int main()
{
    int n;
    getline(cin, s);
    n = s.length();
    long long a = cal(n);
    reverse(s.begin(), s.end());
    for (int i = 0; i < n; i++)
        if (s[i] == ')')
            s[i] = '(';
        else
            s[i] = ')';
    long long b = cal(n);
    cout << (a * b) % mod << endl;
}

```

## 左孩子右兄弟
### 思路
树形dp，把树存成二维链表形式，每一个节点的链表里存它的所有子节点。数组f[N]记录每个节点所在的层数

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
#define N 100005
int f[N]; // you
vector<int> tree[N];
void dfs(int data)
{
    f[data] = tree[data].size();
    int maxn = 0;
    for (int i = 0; i < tree[data].size(); ++i)
    {
        int j = tree[data][i];
        dfs(j);
        maxn = max(maxn, f[j]);
    }
    f[data] += maxn;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, data;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> data;
        tree[data].push_back(i);
    }
    dfs(1);
    cout << f[1] << endl;
    return 0;
}

```

## 双向排序
### 思路
使用vector的stl函数来进行升降排序，过了60%的测试点
蓝桥杯不能用auto定义迭代器，要乖乖写容器类型；另外本题还要注意迭代器的下标的使用

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> v;
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        v.push_back(i);
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        if (a)
        {
            sort(v.begin() + b - 1, v.end());
        }
        else
        {
            sort(v.begin(), v.begin() + b, cmp);
        }
    }
    vector<int>::iterator it = v.begin();
    for (it; it != v.end(); ++it)
    {
        if (it == v.begin())
            cout << *it;
        else
            cout << " " << *it;
    }
    cout << endl;
    return 0;
}
```

