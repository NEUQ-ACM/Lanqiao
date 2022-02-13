#include<iostream>
using namespace std;
class num
{
    public:
    int b;
    int count1=2021;
     static int flag;
};
int num::flag=1;
int main()
{

    num a[10];
    for(int i=0;i<10;i++)
    {
        a[i].b=i;
    }
    int c=0;
    int cc;
    int m;
    while(num::flag)
    {

        c++;
        cc=c;
        while(cc>0)
        {
            m=cc%10;
            a[m].count1--;
            if(a[m].count1<0)
            {
                num::flag=0;
            }
            cc/=10;
        }
    }
    c--;
    cout<<c;


    return 0;
}
