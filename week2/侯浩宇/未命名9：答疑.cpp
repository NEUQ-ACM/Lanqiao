#include<bits/stdc++.h>
using namespace std;

class timee{
	public:
		int x,y,a,b,c;
	//x:进入时间 
	//y:答疑时间 
	//a:发消息前时间 
	//b:出门时间 
	//c:总时间 
	
	
}; 

timee t[100001];

int n;

void px(){
	int tem=0,p=0;
	while(1){
		p=0;
		for(int i=1;i<n;i++){
			if(t[i].c<t[i-1].c){
				swap(t[i],t[i-1]);
				tem=i;
				p=1;
			}
			
		}
		if(p){
			tem=0;
		}
		else{
			tem++;
			break;
		}
	}
	return;
} 

void qh(){
	int sum,ans;
	sum=ans=0;
	for(int i=0;i<n;i++){
		sum+=(t[i].a+t[i-1].b);
		ans+=sum;
	}
	cout<<ans;
}

int main(){
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t[i].x>>t[i].y>>t[i].b;
		t[i].a=t[i].x+t[i].y;
		t[i].c=t[i].a+t[i].b;
	}
	
	px();
	
	qh();
	
	return 0;
}
