#include <bits/stdc++.h>
using namespace std;
int main()
{
int s=0,q;
for(int i=1;i<=2020;i++)
{
q=i;
while(q)
{
if(q%10==2)s++;
q/=10;
}
}
cout<<s;
return 0;
}

