#include <bits/stdc++.h>
using namespace std;
const int maxn=123456;
int pre[maxn]={0},st[maxn],vl[maxn];

struct Node{
  int t,i;
}node[maxn];

bool cmp(Node a,Node b){
  if(a.i==b.i) return a.t<b.t;
  return a.i<b.i;
}

int main(){
  int N,M,T;
  cin>>N>>M>>T;
  int ans=0;
  for(int k=0;k<M;k++){
    cin >> node[k].t >> node[k].i;
  }
  sort(node,node+M,cmp);
  for(int j=0;j<M;j++){
  	int ts=node[j].t;
  	int id=node[j].i;
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
  		if(vl[j]<=3){
  			st[j]=0;
		  }
	  }
  }
  for(int j=1;j<=N;j++){
  	if(st[j]){
  		ans++;
	  }
  }
  cout << ans << endl;
  return 0;
}
