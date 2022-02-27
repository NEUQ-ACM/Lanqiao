#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
struct pos{
	int x,y;
};
int d[100010];
int main(){
	pos a[1001];
	int k=0;
	for(int i=0;i<20;i++){
		for(int j=0;j<21;j++)
		{
			a[k].x=i;
			a[k].y=j;
			k++;
		}
	}
	int m=0;
	for(int i=0;i<k;i++){
		for(int j=i+1;j<k;j++){
			if(a[j].x==a[i].x) d[m]=inf;
			else if(a[j].y==a[i].y) 
				d[m]=0;
			else d[m]=(a[j].y-a[i].y)/(a[j].x-a[i].x);
			m++;
		} 
	}
	int n = unique(d, d + m) - d;
	cout<<n<<endl;
}
