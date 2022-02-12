#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=21,M=1<<N;
LL st[N][N];
LL f[M][N];
int n;
int main()
{
	  for(int i=0;i<N;i++)
	    for(int j=0;j<N;j++)
	      if(__gcd(i+1,j+1)==1)st[i][j]=1;
	      
	  f[1][0]=1;//集合为{1},停留在点1（在数组中处理将其减一故第二维为0）
	  
	  for(int i=0;i<(1<<N);i++)//集合状态
	    for(int j=0;j<N;j++)//走过当前集合且最后停留在点j
	      if(i>>j&1)//看j点有没有到（在不在编码i代表的集合S中），这里为真代表在
	        for(int k=0;k<N;k++)//要往点k走
	          if(!(i>>k&1))//k不在S中
	          	if(st[j][k])f[i|(1<<k)][k]+=f[i][j];//
	  LL ans=0;
	  for(int i=0;i<N;i++)ans+=f[(1<<N)-1][i];//全集对应的编码为(1<<N)-1,这里i全循环一遍是因为教学楼1和所有教学楼都连边
	  cout<<ans<<endl;
	
	  return 0;
}
