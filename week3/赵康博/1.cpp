#include <bits/stdc++.h>
using namespace std;
#define LL long long
bool ok(int x)
{
    int y;
    while(x)
    {
        y = x%10;
        if(y==2||y==0||y==1||y==9) return true;
        x /= 10;
    }
    return false;
}
//2658417853
int main()
{
    LL sum = 0;
    for(int i=1;i<=2019;++i)
    {
        if(ok(i)) sum += 1ll*i*i;
    }
    cout<<sum<<endl;
    return 0; 
} 
