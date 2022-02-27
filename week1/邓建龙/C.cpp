#include<bits/stdc++.h>
#define LL long long
using namespace std;
const long long N = 2021041820210418;
int main()
{
	vector<LL> vec;
	for(LL i = 1; i <= sqrt(N); i++) {
		if(N % i == 0)vec.push_back(i), vec.push_back(N/i);
	}
	LL res = 0;
	for(LL i = 0; i < vec.size(); i++) {
		for(LL j = 0; j < vec.size(); j++) {
			if(N % (vec[i] * vec[j]) == 0) res++;
		}
	}
	cout << res << endl;
	return 0;
} 