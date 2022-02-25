#include <iostream>

using namespace std;
#define ll long long

//n=pq
//
ll n=1001733993064167141;

int main()
{

    cout<<n;
    ll p,q,i;
    for(i=3;i<n;i=i+2)
    {
        if(n%i==0)
        {
            p=i;q=n/p;
            break;
        }
    }
    cout<<endl;

    cout<<p<<" "<<q;
    return 0;
}
