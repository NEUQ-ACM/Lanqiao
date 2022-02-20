#include <bits/stdc++.h>
using namespace std;
int main()
{
int a[10001],n,s=0,maxt=-1,mint=101;
double ave;
cin>>n;
for(int i=1;i<=n;i++)
{
cin>>a[i];
s++;
maxt=max(maxt,a[i]);
mint=min(mint,a[i]);
}
ave=s/double(n);
printf("%d\n%d\n%2.lf",maxt,mint,ave);
return 0;
}
