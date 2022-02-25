#include<bits/stdc++.h>
using namespace std;
int main(){
    double n;
    cin>>n;
    double maxx=0,minn=100,sum=0;
    for(int i=1;i<=n;i++){
        double x;
        cin>>x;
        sum+=x;
        if(x>maxx) maxx=x;
        if(x<minn) minn=x;
    }
    double ave=sum/n+0.005;
    cout<<maxx<<endl;
    cout<<minn<<endl;
    cout<<fixed<<setprecision(2)<<ave;
    return 0;
}
