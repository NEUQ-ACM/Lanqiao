#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef long long LL;

int main()
{
    long long sum=0;

    for(int i=1;i<=2019;i++){
        int x=i;
        while(x){
            if(x%10==2||x%10==0||x%10==1||x%10==9){
                sum=sum+i*i;
                break;
            }
            x/=10;
        }
    }

    cout<<sum;

    return 0;
}

