#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int F=10000;
int main()
{
LL a=1,b=1,c=1;
LL s=0;
for(int i=4;i<=20190324;i++)
{
s=(a+b+c)%F;
a=b,b=c,c=s;
}
cout<<s;
return 0;
}
