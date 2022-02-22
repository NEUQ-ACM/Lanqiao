#include<iostream>
using namespace std;
int get(int n)
{
    if(n==1)
    {
        return 1;
    }
    else
    {
        return get(n-1)+4*(n-1);
    }
}
int main()
{
    int a=20;
    cout<<get(a);
    return 0;
}
