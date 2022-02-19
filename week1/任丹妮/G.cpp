#include <bits/stdc++.h>
using namespace std;
const int maxn=123456;
struct pos{
  int t,i;
}wm[maxn];
int pre[maxn]={0},st[maxn],vl[maxn];
bool cmp(pos a,pos b){
  if(a.i==b.i) return a.t<b.t;
  return a.i<b.i;
}
int main()
{
  int N,M,T;
  cin>>N>>M>>T;
  int ans=0;
  for(int k=0;k<M;k++){
    cin>>wm[k].t>>wm[k].i;
  }
  sort(wm,wm+M,cmp);
  for(int j=0;j<M;j++){
  	int ts=wm[j].t;
  	int id=wm[j].i;
  	if(pre[id]!=ts) vl[id]-=ts-pre[id]-1;
  	vl[id]=max(0,vl[id]);
  	if(vl[id]<=3) st[id]=0;
  	vl[id]+=2;
  	if(vl[id]>5) st[id]=1;
    pre[id]=ts;
  }
  for(int j=1;j<=N;j++){
  	if(pre[j]<T){
  		vl[j]-=T-pre[j];
  		if(vl[j]<=3) st[j]=0;
	  }
  }
  for(int j=1;j<=N;j++){
  	if(st[j]) ans++;
  }
  cout<<ans<<endl;
  return 0;
}
