#include <bits/stdc++.h>
using namespace std;
// 传送门：http://oj.ecustacm.cn/problem.php?id=1511
// dfs+并查集+回溯
// 思路：首先用dfs(1)到dfs(7)利用回溯多层递归将所有的点亮方式枚举
// 然后在dfs(8)中对每一层的不同种情况进行judge判断即可
int edge[8][8];
int father[8]; //并查集数组
int use[8];    //判断是否点亮
void input()
{
    edge[1][2] = edge[1][6] = 1;
    edge[2][1] = edge[2][7] = edge[2][3] = 1;
    edge[3][2] = edge[3][4] = edge[3][7] = 1;
    edge[4][3] = edge[4][5] = 1;
    edge[5][4] = edge[5][6] = edge[5][7] = 1;
    edge[6][1] = edge[6][5] = edge[6][7] = 1;
}
int find(int x)
{
    if (father[x] == x)
        return x;
    else
        return father[x] = find(father[x]);
}
void connect(int x, int y)
{
    father[find(x)] = father[find(y)];
}
int ans;
void judge()
{
    for (int i = 1; i <= 7; i++)
        father[i] = i;
    for (int i = 1; i <= 7; i++)
        for (int j = 1; j <= 7; j++)
        {
            if (edge[i][j] && use[i] && use[j])
            {
                int fa1 = find(i);
                int fa2 = find(j);
                if (fa1 != fa2)
                {
                    connect(fa1, fa2);
                }
            }
        }
    int count = 0;
    for (int i = 1; i <= 7; i++)
    {
        if (use[i] && father[i] == i)
            count++;
    }
    if (count == 1)
        ans++;
    return;
}
void dfs(int n)
{
    if (n > 7)
    {
        judge();
        return;
    }
    use[n] = 1;
    dfs(n + 1);
    use[n] = 0;
    dfs(n + 1); //回溯！
}
int main()
{
    input();
    dfs(1);
    cout << ans;
    return 0;
}