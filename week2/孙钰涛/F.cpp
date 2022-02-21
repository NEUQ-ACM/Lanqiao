
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,mmax=0,mmin=999;
    double sum=0;
    cin>>n;
    while(cin>>x)
    {
        mmax=max(x,mmax);
        mmin=min(x,mmin);
        sum=sum+x;
    }
    printf("%d\n%d\n%.2lf",mmax,mmin,sum/n);
    return 0;
}