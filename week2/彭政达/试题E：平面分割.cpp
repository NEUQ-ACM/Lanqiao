#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=20,m=20;
    int ans=1+(n*(n+1))/2+(m*(2*n+2*n+2*(m-1)))/2;
    cout<<ans<<endl;
}
