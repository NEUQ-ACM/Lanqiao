#include <bits/stdc++.h>
using namespace std;
// http://lx.lanqiao.cn/problem.page?gpid=T2697
// ?????https://blog.csdn.net/qq_26139541/article/details/121284273?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164491769216781685391475%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=164491769216781685391475&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-8-121284273.first_rank_v2_pc_rank_v29&utm_term=%E5%A4%96%E5%8D%96%E5%BA%97%E4%BC%98%E5%85%88%E7%BA%A7&spm=1018.2226.3001.4187
// ??
#define maxn 1000000
pair<int, int> order[maxn];
long long n, m, t;
int ans[maxn];        //??????????
long long last[maxn]; // ???i?????????????
bool first[maxn];     //??????
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> t;
    for (int i = 1; i <= m; i++)
    {
        cin >> order[i].first >> order[i].second;
    }
    sort(order + 1, order + 1 + m); //?????????
    for (int i = 1; i <= m; i++)
    {
        int ts = order[i].first, id = order[i].second;
        if (ts != last[id]) //??????????????????
        {
            ans[id] = ans[id] - (ts - last[id] - 1); //???????????????????
        }
        ans[id] = max(ans[id], 0);
        if (ans[id] <= 3)
        {
            first[id] = false;
        }
        ans[id] += 2;
        if (ans[id] > 5)
            first[id] = true;
        last[id] = ts; //??last??
    }
    for (int i = 1; i <= n; i++)
    { //??m?????????????????????????????????ans????????????????
        if (last[i] != t)
            ans[i] = ans[i] - (t - last[i]);
        if (ans[i] <= 3) 
            first[i] = false;
    }
    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (first[i])
            res++;
    }
    cout << res;
    return 0;
}