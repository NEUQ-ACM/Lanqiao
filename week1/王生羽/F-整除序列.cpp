 #include<bits/stdc++.h>

using namespace std;

#define ll unsigned long long

int main(){
	ll n;
	cin >> n;
	vector<ll> a;
	while(n){
		a.push_back(n);
		n >>= 1;
	}
	
	for(int i = 0; i < a.size(); i++) if(a[i] > 0) cout << a[i] << " ";
	cout << endl;
	return 0;
} 

