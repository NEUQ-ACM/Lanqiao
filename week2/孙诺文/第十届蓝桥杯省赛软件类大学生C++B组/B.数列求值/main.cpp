#include <iostream>

using namespace std;

long long m[5];
int main()
{
    int a1,a2,a3,a4;
    long long i=4;
    m[1]=1;
    m[2]=1;
    m[3]=1;
    while(i!=20190325)
    {
        m[4]=m[1]+m[2]+m[3];
        m[4]=m[4]%10000;
        m[1]=m[2];
        m[2]=m[3];
        m[3]=m[4];
        i++;
    }

    a1=m[4]%10;
    m[4]=m[4]/10;

     a2=m[4]%10;
    m[4]=m[4]/10;

     a3=m[4]%10;
    m[4]=m[4]/10;

     a4=m[4]%10;

    cout<<a4<<a3<<a2<<a1;
    return 0;
}
//答案：4659
//方法：暴力递推（和的最后四位数字只与加数的后四位数有关）
