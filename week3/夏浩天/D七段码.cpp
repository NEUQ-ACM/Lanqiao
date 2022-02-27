//答案：80
//递归枚举+并查集
//因为只有七条边 每条边只有选和不选的 0 1 操作，所以递归枚举七条边的所有情况 2 7 2 ^ 7 27。
//枚举完每次用并查集check一下是否所有选上的边的断点都在同一个集合里，如果在同一个集合，res++
//参考：https://www.icode9.com/content-1-908856.html
#include<iostream>
#include<string>//to_string
int book[10], res = 0, f[10];
int u[10] = { 0,1,2,3,4,5,1,3 }; //存边的端点
int v[10] = { 0,2,3,4,5,6,6,6 };
int find(int x) 
{
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}
void check()
{
    int pos = -1;
    for (int i = 1; i <= 6; i++) f[i] = i;  //并查集 初始化
    for (int i = 1; i <= 7; i++)
        if (book[i])  //如果选上了就连起来
            f[find(u[i])] = find(v[i]), pos = u[i];
    if (pos == -1) return;
    for (int i = 1; i <= 7; i++)  //检查是否在同一个集合里
        if (book[i] && find(u[i]) != find(pos))
            return;
    res++;  //在同一个集合里
    return;
}
void dfs(int x)
{
    if (x == 8) 
    {
        check();
        return;
    }
    book[x] = 1; dfs(x + 1);  //选上第x条边
    book[x] = 0; dfs(x + 1);  //不选
}
int main()      // 80
{
    dfs(1); //暴力枚举七条边是否选取  2^7次方种情况
    printf("%d\n", res);
    return 0;
}