#include<bits/stdc++.h>
using namespace std;
struct Node{
	int st;
	int num;
}node[100005];
bool cmp(Node a,Node b){
	if(a.num==b.num)return a.st<b.st;
	return a.num<b.num;
}
int main(){	
	int N,M,T;
	cin>>N>>M>>T;
	for(int i=1;i<=M;i++){
		cin>>node[i].st>>node[i].num;
	}
	int cnt=0;
	int ans[100005];
	int sum[100005];
	memset(sum,0,sizeof(sum));
	sort(node+1,node+M+1,cmp);
	int last_st[M+5];
	for(int i=1;i<=M;i++){
		if(node[i].st<=T){//超过所求时间不处理 
	
		if(sum[node[i].num]<=0)             sum[node[i].num]=0;
		int past=node[i].st-last_st[node[i].num];
		if(past>1)sum[node[i].num]-=past-1;
		if(sum[node[i].num]<=0)             sum[node[i].num]=0;//低于0取0 
		if(sum[node[i].num]<=3)ans[node[i].num]=0;
	 	sum[node[i].num]=sum[node[i].num]+2;
		if(sum[node[i].num]>5)ans[node[i].num]=1;
	
		last_st[node[i].num]=node[i].st;
	}	
}
   for(int i=1;i<=N;i++){
   	if(last_st[i]){
   		sum[i]-=T-last_st[i];
		if(sum[i]<=3)ans[i]=0;
	   }
   }
   for(int i=1;i<=N;i++){
   	if(ans[i])cnt++;
   }
   cout<<cnt;
   return 0;
}
