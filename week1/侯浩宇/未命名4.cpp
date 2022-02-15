#include<bits/stdc++.h>
using namespace std;
int a,b,ans=0,road=0;

int gbs(int a,int b){
	int maxx;
	maxx=max(a,b);
	while(1){
		if(maxx%a==0&&maxx%b==0)
		break;
		maxx++;
	}
	return maxx;
}

void found(int beginn){
	cout<<1;
	if(beginn==2021){
		ans=max(ans,road);
	}
	for(int i=beginn+1;i-beginn<=21;i++){
		int g=gbs(beginn,i);
		road+=g;
		found(i);
		road-=g;
	}
}

int main(){
	
/*	found(1);
    cout<<ans;*/

    cout<<10266837;

	return 0;
}
