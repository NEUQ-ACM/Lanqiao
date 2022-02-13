#include<bits/stdc++.h> 
using namespace std;
int main()
{
    long long n,h,m,s;
    cin>>n;
    n/=1000;
    h=n/3600%24;
    n=n%3600;
    m=n/60%60;
    n=n%60;
    s=n%60;
    cout<<h<<":"<<m<<":"<<s<<":";

}

