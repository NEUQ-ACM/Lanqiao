#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n;
	ll a,b,c,s=0,w=1;
	cin>>n;
	while(n--){
		s=0;
		for(int i=0;i<w;i++){
			cin>>c;
			s+=c;
		}
		if(s>b){
			b=s;
			a=w/2+1;
		}
	}
	cout<<a<<endl;
} 
