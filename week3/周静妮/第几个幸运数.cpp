#include <bits/stdc++.h>
using namespace std;
const int a[] = {3,5,7};
const long long maxn = 59084709587505;
priority_queue<long long,vector<long long>,greater<long long> >p;
set<long long>s;
int res;
int main(){
	long long n,m;
	for(int i = 0;i < 3;i++)p.push(a[i]);
	while((n = p.top())<=maxn){
		p.pop();
		res++;
		for(int i = 0;i < 3;i++){
			m = n*a[i];
			if(!s.count(m)){
				s.insert(m);
				p.push(m);
			}
		}	
	}
	cout << res;
	return 0;
}
