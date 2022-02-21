#include<bits/stdc++.h>
using namespace std;
int ma=0,mi=100;
double avera=0,sum=0;
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int temp;
        cin>>temp;
        ma=max(ma,temp);
        mi=min(mi,temp);
        sum+=(double)temp;
    }
    avera=sum/n;
    cout<<ma<<endl<<mi<<endl;
    printf("%.2f\n",avera);
    return 0;
}