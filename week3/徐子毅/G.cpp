#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
struct D{
	int ts;
	int id;
};
bool cmp(const D &d1,const D &d2){
	if(d1.ts<d2.ts) return true;
	else return false;
}
int main(){
	int N,M,T;
	cin >> N >> M >> T;
	int a[N];
	int vip[N];
	D dd[M];
	for(int i=0;i<N;i++) a[i]=0;
	for(int i=0;i<M;i++){
		int ts,id;
		cin >> ts >> id;
		dd[i].ts=ts;
		dd[i].id=id-1;
	}
	for(int i=1;i<=T;i++){
		for(int j=0;j<M;j++){
			if(dd[j].ts==i) {
				a[dd[j].id]+=3;
				if(a[dd[j].id]>6) vip[dd[j].id]=1;
			}
		}
		for(int j=0;j<N;j++){
			if(a[j]>0) a[j]--;
			if(a[j]<=3) vip[j]=0;
		}
	}
	int sum=0;
	for(int i=0;i<N;i++) if(vip[i]==1) sum++;
	cout << sum << endl;
}