#include<bits/stdc++.h>
using namespace std;
int f[40];

int main(){
    f[1]=1;
    for(int i=2;i<=39;i++){
        f[i]=f[i-1]+i;
}
    int x=(f[39]+f[38]+1)/2;
    cout<<x<<endl;
    return 0;
}

