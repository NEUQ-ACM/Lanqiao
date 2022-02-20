#include<bits/stdc++.h>
using namespace std;
const int N=1e9+10;
int a[N];
int sum[N];
int main(){
	int n;
	cin>>n;
	int a;
	int cnt=1;
	for(int i=1;i<=n;i++){
		cin>>a;
		sum[cnt]+=a;
		if(i==pow(2,cnt)-1)cnt++;
	}
	int index=1;
	int maxx=-100;
	for(int i=1;i<=cnt;i++){
		if(sum[i]>maxx){
			maxx=sum[i];
			index=i;
		}
	}
	cout<<index;
	return 0;
}
