#include<bits/stdc++.h>
using namespace std;

int a[100][100],v[100][100];//地图，访问数组

struct point
{
    int x;
    int y;
    int step;
};
queue<point> r;//申请队列，入队和出队
//方向，分别为右下左上
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int main()
{

    //输入
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    int startx,starty,p,q;
    cin>>startx>>starty>>p>>q;
    //bfs

    point start;
    start.x=startx;
    start.y=starty;
    start.step=0;

    r.push(start);//将起点入队，push是一个方法
    v[startx][starty]=1;
    int flag = 0;
    while(!r.empty())
    {
        int x = r.front().x;
        int y = r.front().y;
        if(x == p && y == q)//终点坐标
        {
            flag = 1;
            cout<<r.front().step;
            //找到了马上退出，所以一定是最小的
            break;
        }
        for(int k=0;k<=3;k++)//四个方向
        {
            int tx,ty;
            tx = x + dx[k];
            ty = y + dy[k];
            if(a[tx][ty] == 1 /*空点*/ && v[tx][ty] == 0/*未访问*/)
            {
                //入队
                point temp;
                temp.x = tx;
                temp.y = ty;
                temp.step = r.front().step + 1;
                r.push(temp);
                v[tx][ty]=1;
            }
        }
        r.pop();//拓展完了将对首元素出队
    }
    if(!flag)
    {
        cout<<"no answer!";
    }
    return 0;
}
