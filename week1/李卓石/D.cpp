#include<bits/stdc++.h>  //递归枚举+并查集
using namespace std;
int book[10],res=0,f[10];
int u[10]={0,1,2,3,4,5,1,3}; //存边的端点，有序
int v[10]={0,2,3,4,5,6,6,6};
int find(int x)
{
    return x == f[x] ? x : (f[x] = find(f[x]));
}
void check()
{
    int pos=-1;
    for(int i=1;i<=6;i++) f[i]=i;  //并查集 初始化
    for(int i=1;i<=7;i++)
        if(book[i])  //如果选上了就连起来
            f[find(u[i])]=find(v[i]),pos=u[i];
    if(pos==-1) return;
    for(int i=1;i<=7;i++)  //有几个根节点说明有几个集合：判断根节点是否相同 ——检查两个元素是否在同一个集合里
        if(book[i]&&find(u[i])!=find(pos))
            return ;
    res++;  //在同一个集合里
    return;
}
void dfs(int x)
{
    if(x==8){
        check();
        return ;
    }
    book[x]=1; dfs(x+1);  //亮
    book[x]=0; dfs(x+1);  //不亮
}
int main()     
{
    dfs(1); //递归枚举
    printf("%d\n",res);
    return 0;
}
