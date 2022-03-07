#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int n;
int a[MAXN];
int sum[MAXN];
int maxSum;
int ans;
void getSum(){
    int cnt = 1;
    maxSum = a[1];
    sum[1] = a[1];
    for(int i = 1 ;i<MAXN;i++){
        int temp=pow(2,i);
        for(int j = cnt+1;j<=cnt+temp;j++){
            sum[i+1]+=a[j];
        }
        if(maxSum<sum[i+1]){
                ans=i+1;
                maxSum=sum[i+1];
            }
        cnt+=temp;
        if(cnt>=n){return ;}
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    getSum();
    cout<<ans<<endl;
    
    return 0;
}