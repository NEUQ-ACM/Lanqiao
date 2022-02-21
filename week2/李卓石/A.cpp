#include <bits/stdc++.h>
using namespace std;
int a[10],t;
int main()
{
for(int i=1;;i++)
{
t=i;
while(t)
{
a[t%10]++;//逆序统计
if(a[t%10]==2021)
{cout<<i;return 0;}//程序终止的设置
t/=10;
}
}
return 0;
}
