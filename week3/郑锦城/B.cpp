#include<bits/stdc++.h>
using namespace std;
//long long getnum(long long n)
//{
//    if(n<=3)
//    {
//        return 1;
//    }
//    else
//    {
//        return ((getnum(n-1)+getnum(n-2))%10000+getnum(n-3))%10000;
//    }
//}
int main()
{
    long long a,b,c;
    a=b=c=1;
    long temp;
    for(int i=4;i<=20190324;i++)
    {
        temp=((a+b)%10000+c)%10000;
        a=b;
        b=c;
        c=temp;

    }
    cout<<temp;
    return 0;
}
