//参考：https://blog.csdn.net/linruier2017/article/details/88803441
#include<iostream>
using namespace std;
int bit[2000001];
int n = 1000001;
int sum(int i)
{
    int s = 0;
    while (i > 0)
    {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}
void add(int i, int x)
{
    while (i <= n)
    {
        bit[i] += x;
        i += i & -i; // 位运算，i&(-i)运算的功能为返回 i 的二进制数表示为１的最低位的权值
    }
}
bool vis[1000005];
int ans[100005];
int N;
int a[100005];
int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < N; i++)
    {
        if (!vis[a[i]])//没出现过
        {
            ans[i] = a[i];
            vis[a[i]] = 1;
            add(a[i], 1);
        }
        else
        {
            int l = a[i]; int r = 1000002;
            int mid;
            while (r - l > 1)
            {
                mid = (l + r) / 2;
                int l = mid - a[i] + 1;
                int cnt = sum(mid) - sum(a[i] - 1);
                if (cnt < l)r = mid;
                else l = mid;
            }
            ans[i] = r;
            vis[r] = 1;
            add(r, 1);
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (i == N - 1)
            printf("%d%c", ans[i], ' ');
        else
            printf("%d%c", ans[i], '\n');
    }
    return 0;
}





