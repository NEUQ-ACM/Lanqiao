#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=21,M=1<<N;
int gcd(int a,int b){
	return b?gcd(b,a%b):a; 
}
int edge[22][22]={0};
ll f[M][N]={0};
int main(){
	for(int i=0;i<21;i++)
	for(int j=0;j<21;j++)
	if(gcd(i+1,j+1)==1) edge[i][j]=1;
	f[1][0]=1;
	for(int i=1;i<=M-1;i++)
	{
		for(int j=0;j<21;j++)
			if(i>>j&1)
				for(int k=0;k<21;k++)
					if((i-(1<<j))>>k&1&&edge[k][j])
					f[i][j]+=f[i-(1<<j)][k];
	}
	ll ans=0;
	for(int i=1;i<21;i++)
		ans+=f[M-1][i];
	cout<<ans<<endl;
}
