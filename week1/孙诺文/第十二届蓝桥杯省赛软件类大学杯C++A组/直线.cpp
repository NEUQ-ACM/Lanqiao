#include <iostream>

using namespace std;
//一共有2*3个点的时候有11条直线

struct node
{
    int x;
    int y;
};

struct line
{
    double k;
    double b;
};


class node m[500];
class line n[99999];

int main()
{
    int i,j,k=1,head=1,tail=1;
    for(i=0;i<=20;i++)
    {
        for(j=0;j<=19;j++)
        {
            m[k].x=i;
            m[k].y=j;
            k++;
        }
    }

    //b=(Yx-yX)/(x-X)

    for(i=1;i<=21*20;i++)
    {
        for(j=i+1;j<=21*20;j++)
        {
            int flag=0;
            if(m[i].x==m[j].x)
             {
                 n[tail].k=999999;
                 n[tail].b=m[i].x;
             }

            else{
                    n[tail].k=double(m[i].y-m[j].y)/double(m[i].x-m[j].x);
                    n[tail].b=double(m[i].y*m[j].x-m[i].x*m[j].y)/double(m[j].x-m[i].x);
                    }

            for(int t=head;t<tail;t++)
            {
                if(n[t].k==n[tail].k&&n[t].b==n[tail].b)
                    flag=1;
            }

            if(flag==0)
            {
            tail++;
            }

        }
    }

    cout<<(tail-1);
    return 0;
}
