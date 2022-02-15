#include <bits/stdc++.h>
using namespace std;
int main()
{
int d=4,v=1;
for(int i=2;i<=20;i++)
{v+=d;d+=4;}
cout<<v;
return 0;
}
