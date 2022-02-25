#include<iostream>
#include<vector>
using namespace std;

long long n;
int main()
{
    n = 2021041820210418;
    vector<long long> v;

    for(long long i=1;i*i<=n;i++)
    {
        if(n%i == 0)
        {
            v.push_back(i);
            v.push_back(n/i);
        }
    }

    int ans = 0;
    for(auto i:v)
    {
        for(auto j:v)
        {
            for(auto k:v)
            {
                if(i*j*k == n)
                {
                    ans++;
                }
            }
        }
    }
    cout<<ans;

    return 0;
}