#include <bits/stdc++.h>
using namespace std;
// 题解：https://blog.csdn.net/qq_52652816/article/details/122333311?ops_request_misc=&request_id=&biz_id=102&utm_term=%E5%B7%A6%E5%AD%A9%E5%AD%90%E5%8F%B3%E5%85%84%E5%BC%9F&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-4-122333311.first_rank_v2_pc_rank_v29&spm=1018.2226.3001.4187
// 如果我们把>2的兄弟节点标号排序的话，那么标号在最后一个节点它的深度是最大的，整棵任意节点的高度就等于高度加深度，所以如果我们想要获得更大的高度，只需要把高度最大的那个节点找出来，将它放到最后一个即可。
// 这样的话，递归关系就出来了，找到高度最大的孩子节点，加上它距离原来的父节点的深度
// 知识点：树形dp
vector<int> edge[100000];
int dp[1000090]; // dp[i]代表第i个结点当根节点时，此时以它为结点的子树的深度最大为多少
void dfs(int x)  // x为当前节点
{
    int len=edge[x].size();
    int max1=0;
    for(int i=0;i<len;i++)//寻找子树高度最大的子节点
    {
        int son=edge[x][i];
        dfs(son);
        max1=max(max1,dp[son]);
    }
    dp[x]=max1+len;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int remp;
        cin >> remp;
        edge[remp].push_back(i);
    }
    dfs(1);
    cout << dp[1];
    return 0;
}