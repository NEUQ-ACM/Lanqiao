#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef long long LL;

bool v[30][50];
char g[30][50],n[4]={'D','L','R','U'};
int d[4][2]={{1,0},{0,-1},{0,1},{-1,0}};

struct point
{
    int x;
    int y;
    string s;
};

int main()
{
    memset(v,0,sizeof(v));
    for(int i=0;i<30;i++)
        for(int j=0;j<50;j++)
            cin>>g[i][j];
    point p;
    p.x=0;p.y=0;p.s="";
    queue<point> q;
    q.push(p);
    v[0][0]=1;
    while(!q.empty()){
        point now=q.front();
        if(now.x==29&&now.y==49){
            cout<<now.s;
            break;
        }
        for(int i=0;i<4;i++){
            point temp;
            temp.x=now.x+d[i][0];
            temp.y=now.y+d[i][1];
            if(g[temp.x][temp.y]=='0'&&!v[temp.x][temp.y]&&
               (temp.x>=0&&temp.x<30)&&(temp.y>=0&&temp.y<50)){
                temp.s=now.s+n[i];
                q.push(temp);
                v[temp.x][temp.y]=1;
            }

        }
        q.pop();
    }

    return 0;
}

