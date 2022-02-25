#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=21,M=1<<N;
//22位二进制  M-1 = 21个1 
ll f[M][N];
bool g[N][N];
int gcd(int a,int b)
{return b?gcd(b,a%b):a;}
ll dp()
{
    f[1][0]=1;//最初从0点开始，状态为00000....1 
    for(int i=1;i<=M-1;i++)//状态 
         for(int j=0;j<=20;j++)//点 
             if(i>>j&1) //找到状态i中走过的点j,等价于i除以2的j次方，然后与1做与运算，
			 //也就是如果i/(2^j)得到的数装换为2进制后，如果最后一位为1，就输出1，最后一位为0就输出0
                for(int k=0;k<=20;k++)//对于j点，找能转移到j的点k
                //在未走j之前，状态为 i-(1<<j) 判断是否走过k点 
                    if( (i-(1<<j)) >>k&1 && g[k][j])
                        f[i][j]+=f[(i-(1<<j))][k]; 
    
    ll res=0;
    for(int i=1;i<=20;i++)//倒数第二步在2~21点的情况(对应1~20) 
        res+=f[M-1][i];
    return res;
}
int main()
{
    for(int i=1;i<=21;i++)
        for(int j=1;j<=21;j++)
            if(gcd(i,j)==1)//将1~21映射到0~20 
                g[i-1][j-1]=true;
    cout<<dp();
} 
