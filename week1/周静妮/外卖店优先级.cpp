#include<bits/stdc++.h>
using namespace std;
struct dianpu{
	int level;
	bool is; 
}dp[100001];
int main(){
	int n,m,t,dd[100001][2],lev[100001]={0};
	cin>>n>>m>>t;
	for(int i=0;i<m;i++)
	{
		cin>>dd[i][0]>>dd[i][1];
	}
	for(int i=0;i<m;i++){
		for(int j=i;j<m;j++){
			int temp0,temp1;
			if(dd[i][0]>dd[j][0]){
				temp0=dd[i][0];
				temp1=dd[i][1];
				dd[i][0]=dd[j][0];
				dd[i][1]=dd[j][1];
				dd[j][0]=temp0;
				dd[j][1]=temp1;
			}
		}
		
	}

	int ddtime=0,sum=0;
	for(int time=1;time<=t;time++){
		if(dd[ddtime][0]==time){
			dp[dd[ddtime][1]].level+=2;
			if(dp[dd[ddtime][1]].level>5){
				sum++;
				dp[dd[ddtime][1]].is=true;
			}
			dp[dd[ddtime][1]].level+=1; 
			ddtime++;
		}
		else{
			for(int i=1;i<=n;i++){
				dp[i].level--;
				if(dp[i].is==true&&dp[i].level<3){
					dp[i].is=false; 
					sum--;
				}
			}
			ddtime++;
		}
	}
	cout<<sum;
	return 0;
}

