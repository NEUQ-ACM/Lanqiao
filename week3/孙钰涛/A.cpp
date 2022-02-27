#include<bits/stdc++.h>
using namespace std;

bool judge(long long x)
{
    while(x)
    {
        if(x%10==2||x%10==0||x%10==1||x%10==9)
            return 1;
        x=x/10;
    }
    return 0;
}
int main()
{
    long long sum=0;
    for(long long i=1;i<=2019;i++)
        if(judge(i)==1)
            sum=sum+i*i;
    cout<<sum;
    return 0;
}
//2658417853