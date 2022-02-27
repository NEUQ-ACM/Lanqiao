#include<iostream>
#include<cmath>
using namespace std;
bool judge(int n)
{
    int m;
    while(n>0)
    {
        m=n%10;
        switch (m)
        {
        case 1:
            return true;
            break;
        case 2 :
            return true;
            break;
        case 0:
            return true;
            break;
        case 9:
            return true;
            break;
        default:
            break;
        }
        n/=10;
    }
}
int main()
{
    long long sum=0;
    //拿到一个数
    for(int i=1;i<=2019;i++)
    {
        //判断是否含有2，0，1，9
        if(judge(i))
        {
            //是的话将这个数平方
            //将所有的平方加起来
            sum=sum+pow(i,2);
        }
    }
    cout<<sum;
    //有个溢出的坑，把sum的类型改为long long 即可

    return 0;
}
