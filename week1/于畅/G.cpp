#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef long long LL;

int main()
{
    int T;

    cin>>T;

    while(T--){
        int n,num[100];
        memset(num,0,sizeof(num));
        LL sum=0;
        cin>>n;
        for(int i=0;i<n;i++){
            LL x;
            cin>>x;
            sum^=x;
            int j=0;
            while(x){
                if(x&1) num[j]++;
                j++;
                x>>=1;
            }
        }

        if(!sum){
            cout<<0<<endl;
            continue;
        }
        for(int j=99;j>=0;j--){
            if(!num[j]) continue;
            else if(num[j]==1){
                cout<<1<<endl;
                break;
            }
            else if(num[j]&1){
                if(n&1){
                    cout<<1<<endl;
                    break;
                }
                else{
                    cout<<-1<<endl;
                    break;
                }
            }
        }
    }

    return 0;
}

