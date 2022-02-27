#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d;
    a = b = 1; c = 3; 
    for(int i=4;i<=20190324;++i)
    {
        d = (a+b+c)%10000;
        a = b; 
        b = c;
        c = d;
    }
   // 6293
    cout<<d<<endl;
    return 0; 
} 
