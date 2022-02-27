#include<bits/stdc++.h>
using namespace std;
int n,m,way[31][51];
char MAP[31][51];
int dx[5]={0,1,0,0,-1};
int dy[5]={0,0,-1,1,0};
char d[5]={'0','D','L','R','U'};

struct POINT
{
    int x;
    int y;
};

queue<POINT> a;

int main()
{
    memset(way,0,sizeof(way));
    memset(MAP,0,sizeof(MAP));
    for(int i=1;i<=30;i++)
        for(int j=1;j<=50;j++)
            cin>>MAP[i][j];

    POINT start;
    start.x=1;
    start.y=1;
    way[1][1]=100;
    a.push(start);

    while(!a.empty())
    {
        int tx=a.front().x;
        int ty=a.front().y;
        if(tx==30 && ty==50)
            break;
        for(int i=1;i<=4;i++)
        {
            int xx=tx+dx[i];
            int yy=ty+dy[i];
            if(xx<1 || xx>30 || yy<1 || yy>50 || way[xx][yy] || MAP[xx][yy]=='1')
                continue;
            POINT temp;
            temp.x=xx;
            temp.y=yy;
            a.push(temp);
            way[xx][yy]=i;
        }
        a.pop();
    }
    int x=30,y=50;
    vector<int>w;
    while(1)
    {
        w.push_back(way[x][y]);
        if(x==1 && y==1) break;
        int tx=x,ty=y; 
        x=x-dx[way[tx][ty]];
        y=y-dy[way[tx][ty]];
    }
    for(int i=w.size()-1;i>=0;i--)
        cout<<d[w[i]];
    return 0;
}
//DDDDRRURRRRRRDRRRRDDDLDDRDDDDDDDDDDDDRDDRRRURRUURRDDDDRDRRRRRRDRRURRDDDRRRRUURUUUUUUULULLUUUURRRRUULLLUUUULLUUULUURRURRURURRRDDRRRRRDDRRDDLLLDDRRDDRDDLDDDLLDDLLLDLDDDLDDRRRRRRRRRDDDDDDRR