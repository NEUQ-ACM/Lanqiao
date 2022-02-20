#include<bits/stdc++.h>
using namespace std;

const int maxn = 21;
long long int dp[1<<maxn][maxn];

bool isPosVis(int state,int pos)
{
    if((state & (1<<pos)) != 0)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool isConnect(int x,int y)
{
    if(x == 0||y == 0)
    {
        return true;
    }
    if(__gcd(x+1,y+1) == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

long long int fx(int state,int finalPos)
{
    if(dp[state][finalPos] != -1)
    {
        return dp[state][finalPos];
    }
    if(!isPosVis(state,finalPos))
    {
        return dp[state][finalPos] = 0;
    }
    long long int re = 0;
    for(int net=0;net<maxn;net++)
    {
        if(!isPosVis(state,net))
        {
            continue;
        }
        if(!isConnect(net,finalPos))
        {
            continue;
        }
        re = re + fx(state-(1<<finalPos),net);
    }

    return dp[state][finalPos] = re;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    long long int ans = 0;
    int finalState = (1<<maxn) - 1;
    dp[1][0] = 1;
    for(int i=0;i<maxn;i++)
    {
        long long int temp = fx(finalState,i);
        cout<<isConnect(i,0)<<" "<<finalState<<" "<<i<<" "<<temp;
        ans = ans + temp;
    }
    cout<<ans;

    return 0;
}