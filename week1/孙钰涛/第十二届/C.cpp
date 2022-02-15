#include<bits/stdc++.h>
using namespace std;
long long n=2021041820210418,res=0;
vector<long long>vec;
int main()
{
    for(long long i=1;i<=sqrt(n);i++)
        if(n%i==0) 
        {
            vec.push_back(i);
            vec.push_back(n/i);
        }
    for(int i=0;i<vec.size();i++)
        for(int j=0;j<vec.size();j++)
            for(int k=0;k<vec.size();k++)
                if(vec[i]*vec[j]*vec[k]==n) res++;
    cout<<res;
    return 0;
}
//2430