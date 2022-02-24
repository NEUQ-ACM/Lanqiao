#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const int maxn=1e9;
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool checkvalid(int year,int month,int day){
	if (month>12||month==0) return 0;
	if ((year%4==0&&year%100!=0)||year%400==0) a[2]=29;
	else a[2]=28;
	if (day>a[month]||day==0) return 0;
	return 1;
}
bool checkpali(int x){
	int temp=0,m=x;
	while (m){
		temp=temp*10+m%10;
		m/=10;
	}
	if (temp==x) return 1;
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,flag=0;
	cin>>n;
	for (int i=n+1;i<maxn;i++){
		int day=i%100;
		int month=i%10000/100;
		int year=i/10000;
		if (!checkvalid(year,month,day)) continue;
		if (!checkpali(i)) continue;
		if (!flag) {
			cout<<i<<"\n";
			flag=1;
		}
		int x=i/1000000;
		int y=(i/10000)%100;
		if (x!=y) continue;
		if (x/10!=x%10) {
			cout<<i;
			return 0;
		}
	}
	return 0;
}