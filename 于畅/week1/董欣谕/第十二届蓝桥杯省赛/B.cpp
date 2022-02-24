#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const double eps=1e-7;
struct line{
	double k,b;
	bool operator < (const line &o) const {
		if (fabs(k-o.k)<eps&&fabs(b-o.b)<eps) return false;
		if (fabs(k-o.k)>eps)return k<o.k;
		return b<o.b; 
	}
};
set<line>s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	for (int x1=0;x1<20;x1++)
		for (int y1=0;y1<21;y1++)
			for (int x2=0;x2<20;x2++)
				for (int y2=0;y2<21;y2++){
					double k,b;
					if (x1!=x2) k=(double)(y1-y2)/(double)(x1-x2),b=y1-k*x1;
					else k=INF,b=x1;
					s.insert({k,b});
				}
	cout<<s.size();
//	for (auto x:s) cout<<x.k<<' '<<x.b<<"\n";
	return 0;
} 
