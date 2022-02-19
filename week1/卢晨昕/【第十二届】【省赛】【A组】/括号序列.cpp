#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using LL=long long;
const int N = 5005;
int f[N][N];
int mod=1e9+7;
string s;
int n;
LL get(){
    memset(f,0,sizeof f);
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        if(s[i-1]=='('){
            for(int j=1;j<=n;j++)
                f[i][j]=f[i-1][j-1];
        }
        else{
            f[i][0]=(f[i-1][1]+f[i-1][0])%mod;
            for(int j=1;j<=n;j++)
                f[i][j]=(f[i-1][j+1]+f[i][j-1])%mod;
        }
    }
    for(int i=0;i<=n;i++)
        if(f[n][i])
            return f[n][i];
    return -1;
}
int main(){
    cin>>s;
    n=s.size();
    LL x=get();
    reverse(s.begin(),s.end());
    for(int i=0;i<n;i++){
        if(s[i]==')')
            s[i]='(';
        else
            s[i]=')';
    }
    LL y=get();
    cout<<(x*y)%mod;
}

