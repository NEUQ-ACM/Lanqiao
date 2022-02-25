#include<bits/stdc++.h>
#define ll long long
using namespace std;
int max_,n,min_=INT_MAX,ans;
double ave;

int main()
{
	cin >> n;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		ans += x;
		min_ = min(min_,x);
		max_ = max(max_,x);
	}
	ave = (double)ans/n;
	cout << max_ << endl << min_ << endl;
	printf("%.2lf",ave);
}

