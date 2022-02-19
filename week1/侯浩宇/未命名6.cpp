#include<bits/stdc++.h>
using namespace std;

int n,num[100005],ans=0;

class work{
	public:
	int zheng,fu,ling=0;
}w[105];

void found(int x){
	
	
	int temp=num[x];
	
	num[++x]=temp+w[x].zheng;
	num[++x]=temp+w[x].fu;
	num[++x]=temp+w[x].ling;
	ans++;
	
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>w[i].zheng;
		w[i].fu=-w[i].zheng;		
	}
	
	cout<<ans;
	
	return 0;
}
