#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105,M=1e5+5;
bool f[N][M*2+5];//f[i][j] 对于前i个砝码，重量为j
int n,m;
int w[N]; 
ll dp()
{	//由于对每个物品存在取负权，加上偏移量防止越界 
	f[0][M]=true;
	for(int i=1;i<=n;i++)
		for(int j=-m;j<=m;j++)//总重量范围为[-m,m] 
		{
			f[i][j+M]|=f[i-1][j+M];//
			if(j+w[i]<=m)
				f[i][j+M]|=f[i-1][j+w[i]+M];//
			if(j-w[i]>=-m)
				f[i][j+M]|=f[i-1][j-w[i]+M];           //状态转移方程：把前i-1项的全部效果(bool)给到第i项  +-0
											//dp(i,j) = dp(i-1,j) | dp(i-1, j-a[i]) | dp(i-1,j+a[i])
		}                                                                      //这种用函数表示前后阶段关系的方程，称为状态转移方程。
	ll res=0;
	for(int i=1;i<=m;i++)
		if(f[n][i+M]) res++;
	return res;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>w[i],m+=w[i];
	cout<<dp(); 
} 
