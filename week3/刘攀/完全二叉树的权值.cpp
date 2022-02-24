#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=0;
ll depth=1;
ll length=1;
int n;
ll sum=0;
int main(){
	cin>>n;
	int maxn=-1e9;
	for(int i=0;i<n;){
		sum=0;
		for(int j=0;j<length&&i<n;i++,j++){
			int x;
			cin>>x;
			sum+=x;
		}
		if(sum>maxn){
			maxn=sum;
			ans=depth;
		}
		depth++;
		length*=2;
	}
	cout<<ans<<endl;
}
