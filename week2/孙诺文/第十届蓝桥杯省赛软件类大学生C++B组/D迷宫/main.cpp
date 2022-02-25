#include <iostream>

using namespace std;

#define xx que[head].x
#define yy que[head].y
int m[99][99];
char n[99][99];
int book[99][99];
int head=1,tail=1;
int head_1=1;int tail_1=1;

struct step
{
    int s;
    char dir;
    int x;
    int y;
    int re_x;
    int re_y;
};

struct f
{
    int re_x;
    int re_y;
    char come;
};

struct f from[99][99];

struct step que[9999];
struct f que_1[999];

int main()
{
    int f=0;
    int i,j;
    for(i=1;i<=30;i++)
    {
        for(j=1;j<=50;j++)
        {
            cin>>n[j][i];
            m[j][i]=n[j][i]-48;
        }
    }

    que[tail].s=0;
    book[1][1]=1;
    que[tail].x=1;
    que[tail].y=1;
    tail=2;

    int flag=1;
    //已知que[head].x que[head].y 的值，枚举每一个相邻的点是否可以到达
    ////D<L<R<U
    while(head!=tail)
    {
        //D
            if(yy+1<=30)
            {
                if(book[xx][yy+1]!=1&&m[xx][yy+1]!=1)
                {
                        que[tail].x=xx;
                        que[tail].y=yy+1;
                        que[tail].s=que[head].s+1;
                        book[que[tail].x][que[tail].y]=1;

                        from[que[tail].x][que[tail].y].re_x=que[head].x;
                        from[que[tail].x][que[tail].y].re_y=que[head].y;
                        from[que[tail].x][que[tail].y].come='D';

                        if(que[tail].x==50&&que[tail].y==30)
                        {
                            head=tail;
                            break;
                        }
                        tail++;
                }
            }

        //L
            if(xx-1>=1)
            {
                if(book[xx-1][yy]!=1&&m[xx-1][yy]!=1)
                {
                        que[tail].x=xx-1;
                        que[tail].y=yy;
                        que[tail].dir='L';
                        que[tail].s=que[head].s+1;
                        book[que[tail].x][que[tail].y]=1;
                        from[que[tail].x][que[tail].y].re_x=que[head].x;
                        from[que[tail].x][que[tail].y].re_y=que[head].y;
                        from[que[tail].x][que[tail].y].come='L';
                        if(que[tail].x==50&&que[tail].y==30)
                        {
                            head=tail;
                            break;
                        }
                        tail++;
                }
            }

            //R
            if(xx+1<=50)
            {
                if(book[xx+1][yy]!=1&&m[xx+1][yy]!=1)
                {
                        que[tail].x=xx+1;
                        que[tail].y=yy;
                        que[tail].dir='R';
                        que[tail].s=que[head].s+1;
                        book[que[tail].x][que[tail].y]=1;
                        from[que[tail].x][que[tail].y].re_x=que[head].x;
                        from[que[tail].x][que[tail].y].re_y=que[head].y;
                        from[que[tail].x][que[tail].y].come='R';
                        if(que[tail].x==50&&que[tail].y==30)
                        {
                            head=tail;
                            break;
                        }
                        tail++;
                }
            }

            //U
            if(yy-1>=1)
            {
                if(book[xx][yy-1]!=1&&m[xx][yy-1]!=1)
                {
                        que[tail].x=xx;
                        que[tail].y=yy-1;
                        que[tail].dir='U';
                        que[tail].s=que[head].s+1;
                        book[que[tail].x][que[tail].y]=1;
                        from[que[tail].x][que[tail].y].re_x=que[head].x;
                        from[que[tail].x][que[tail].y].re_y=que[head].y;
                        from[que[tail].x][que[tail].y].come='U';
                        if(que[tail].x==50&&que[tail].y==30)
                        {
                            head=tail;
                            break;
                        }

                        tail++;
                }
            }

           head++;
    }

    cout<<que[tail].s<<endl;
    que_1[tail_1]=from[50][30];
    tail_1++;
    while(head_1!=tail_1)
    {
        que_1[tail_1]=from[que_1[head_1].re_x][que_1[head_1].re_y];

        if(que_1[tail_1].re_x==1&&que_1[tail_1].re_y==1)
        {
            break;
        }
        tail_1++;
        head_1++;
    }
    for(i=tail_1-1;i>=1;i--)
    {
        cout<<que_1[i].come;
    }
    system("pause");
    return 0;
}
