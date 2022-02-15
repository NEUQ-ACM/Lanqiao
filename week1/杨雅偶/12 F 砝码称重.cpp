#include<bits/stdc++.h>
using namespace std;
int n,f[101][100001],a[101],sum=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	memset(f,0,sizeof(f));
	f[1][a[1]]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(f[i-1][j]==1){
				f[i][j]=1;
				f[i][a[i]]=1;
				f[i][a[i]+j]=1;
				f[i][abs(a[i]-j)]=1;
			}
		}
	}
	int flag=0;
	for(int i=1;i<=sum;i++){
		if(f[n][i]==1)	flag=flag+1;
	}
	cout<<flag;
	return 0; 
}
