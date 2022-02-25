#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef long long LL;

int ans=0,fa[7];
bool light[7],e[7][7];

int root(int x)
{
    if(fa[x]==x) return x;
    else return root(fa[x]);
}

void dfs(int x)
{
    if(x>6){
        for(int i=0;i<7;i++) fa[i]=i;
        for(int i=0;i<7;i++){
            for(int j=i+1;j<7;j++){
                if(e[i][j]&&light[i]&&light[j]){
                    int root1=root(i),root2=root(j);
                    if(root1!=root2) fa[root1]=root2;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<7;i++){
            if(light[i]&&fa[i]==i) cnt++;
        }
        if(cnt==1) ans++;
        return ;
    }

    light[x]=1;
    dfs(x+1);

    light[x]=0;
    dfs(x+1);
}

int main()
{
    /*
    a b c d e f g
    0 1 2 3 4 5 6
    */
    memset(e,0,sizeof(e));
    e[0][1]=e[0][5]=1;
    e[1][0]=e[1][2]=e[1][6]=1;
    e[2][1]=e[2][3]=e[2][6]=1;
    e[3][2]=e[3][4]=1;
    e[4][3]=e[4][5]=e[4][6]=1;
    e[5][0]=e[5][4]=e[5][6]=1;
    e[6][1]=e[6][2]=e[6][4]=e[6][5]=1;

    dfs(0);

    cout<<ans;

    return 0;
}

