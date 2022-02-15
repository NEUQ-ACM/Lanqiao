#include <bits/stdc++.h>
using namespace std;
int GCD(int x,int y)
{
    return y?gcd(y,x%y):x;
}
int main()
{
int s=0;
for(int i=1;i<=2020;i++)
	for(int j=1;j<=2020;j++)
	if(GCD(i,j)==1)s++;
cout<<s;
return 0;
}
