#include<bits/stdc++.h>
using namespace std;
int main()
{
    int cnt=0;
    for(int i=1;i<=2020;i++)
        for(int j=1;j<=2020;j++)
            if(__gcd(i,j)==1) cnt++;
    cout<<cnt;
    return 0;
}
//2481215