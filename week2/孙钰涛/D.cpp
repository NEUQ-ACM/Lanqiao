#include<bits/stdc++.h>
using namespace std;
int n,cnt=0,m[10][10];
bool vis[10],flag[10];
vector<int> vec[10];

void dfs(int x)
{
    if(!flag[x]) return ;
    vis[x]=1;
    cnt++;
    for(int i=0;i<vec[x].size();i++)
    {
        int y=vec[x][i];
        if(!vis[y]) dfs(y);
    }
}

void add(int x,int y)
{
    vec[x].push_back(y);
    vec[y].push_back(x);
}

int main()
{
    add(0,1);add(0,5);
	add(1,2);add(1,6);
	add(2,3);add(2,6);
	add(3,4);add(4,5);
	add(4,6);add(5,6);
    int sum=0;
    for(int i=1;i<(1<<7);i++)
    {
        int k=0,s=0;
        memset(flag,0,sizeof(flag));
        memset(vis,0,sizeof(vis));
        for(int j=0;j<7;j++)
        {
            if(i&(1<<j))
            {
                flag[j]=1;
                k=j;
                s++;
            }
        }
        cnt=0;
        dfs(k);
        if(cnt==s) sum++;
    }
    cout<<sum;
    return 0;
}
//80