#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll n=2021041820210418;
ll ys[100010];
int main(){
	int k=0;
	for(ll i=1;i<=sqrt(n);i++){
		if(n%i==0) {
			ys[k++]=i;
			if(n/i!=i) ys[k++]=n/i;
		}
	}
	int cnt=0;
	for(ll i=0;i<k;i++)
	for(ll j=0;j<k;j++)
	for(ll m=0;m<k;m++)
	if(ys[i]*ys[j]*ys[m]==n) cnt++;
	cout<<cnt<<endl;
} 

