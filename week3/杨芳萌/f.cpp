#include<bits/stdc++.h>
using namespace std;
int a[100001],n,maxx=-1,minn=101;
long long s=0;
double ave;

void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

int main() {
	read(n);
	for(int i=1; i<=n; i++) {
		read(a[i]);
		s+=a[i];
		maxx = max(maxx,a[i]);
		minn = min(minn,a[i]);
	}
	ave = s/double(n);
	printf("%d\n%d\n%.2lf",maxx,minn,ave);	
}

