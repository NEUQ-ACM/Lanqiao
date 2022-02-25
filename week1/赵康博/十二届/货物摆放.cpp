#include<iostream>
#include<vector>
 
using namespace std;
 
int main()
{
    long long ret=0;
    int n=2021041820210418;
    vector<long long> yins;
    for(long long  i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            yins.push_back(i);
            yins.push_back(n/i);
        }
    }
    for(auto i:yins)
    {
        for(auto j: yins)
        {
            for(auto k:yins)
            {
                if(i*j*k==n)
                {
                    ret++;
                }
            }
        }
    }
    char str[50];
    time_t now = time(NULL);
    strftime(str, 50, "%x %X", localtime(&now));
    cout << str << endl;
    cout<<ret<<endl;
    return 1;
}