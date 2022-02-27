#include <bits/stdc++.h>
#define maxm 100000
using namespace std;
int b[maxm]={0},book[maxm]={0},book2[maxm]={0};
struct wm{
	int ts,id;
}a[maxn];
bool cmp(wm a,wm b){
	return a.ts<b.ts;
}
int main(){
	int n,m,t,count=0;
	cin>>n>>m>>t;
	for(int i=1;i<=m;i++) cin>>a[i].ts>>a[i].id;
	sort(a+1,a+m+1,cmp); 
	for(int i=1;i<=t;i++){
		int x;
		for(int j=1;j<=m;j++){
			if(i==a[j].ts){
				x=a[j].id;
				b[x]+=2;
				book2[x]=1; 
			}
			
		}
		for(int l=1;l<=n;l++){
			if(book2[l]!=1){
				if(b[l]>0) b[l]--;
				else b[l]=0;
			}
		}
		if(b[x]>5) book[x]=1; 
		memset(book2,0,sizeof(book2));
	}	
	cout<<count<<endl;	
	return 0;
}
