#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll num[23];
ll a;
void pre(ll a){
	ll cnt=1;
	while(a){
		if(a&1) num[cnt]++;
		cnt++;
		a/=2;
	}
}
int main(){
	int t;
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
		memset(num,0,sizeof(num));
		int n,sum=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a;
			pre(a);
			sum^=a;
		}
		if(!sum)cout<<0<<endl;
		else{
			for(int i=20;i>0;i--){
				if(num[i]==1){
					cout<<1<<endl;
					break;
				}
				else if(num[i]%2==1){
					if(n%2==1){
						cout<<1<<endl;
						break;
					}
					else {
						cout<<-1<<endl;
						break;
					}
				}
				}
			}
		}
	} 
