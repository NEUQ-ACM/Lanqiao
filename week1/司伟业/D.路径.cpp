#include<iostream>
#define int long long
#define maxn 6000005
using namespace std;
int f[maxn][23],ans,t[maxn],g[30][30];
int gcd(int a,int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}

signed main()
{
	for(int i=1;i<=21;i++)
	for(int j=i+1;j<=21;j++)
		if(gcd(i,j)==1) g[i][j]=g[j][i]=1;
	f[1][1]=1;
	for(register int i=2;i<=21;i++){
		for(register int k=1;k<=2097152;k++){
			int tot=0,x=k;
			if(t[k]) tot=t[k];
			else{
				while(x){tot+=x%2;x=x/2;}
				t[k]=tot;
			}
			if(tot!=i-1) continue;
			for(register int j=2;j<=21;j++){
				if(k&(1<<(j-1))) continue;
				for(register int l=1;l<=21;l++){
					if(g[l][j]==0) continue;
					if((1<<(l-1))&k==0) continue;
					f[k|(1<<(j-1))][j]+=f[k][l];
				}
			}
		}
	}
	for(int i=1;i<=21;i++) ans+=f[2097151][i];
	cout<<ans;
}