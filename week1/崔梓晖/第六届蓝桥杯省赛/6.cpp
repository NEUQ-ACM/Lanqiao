#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
using namespace std;
#include<queue>
#include<stack>

#define mod 1000000007
typedef __int64 LL;

struct marx     //定义矩阵
{
    int d[6][6];
    marx() {}
    marx(int x) //构造：对角线赋值为x
    {
        memset(d,0,sizeof(d));
        for(int i=0; i<6; i++)
            d[i][i]=x;
    }
};

marx mul(marx a,marx b) //矩阵乘法
{
    marx res=marx(0);   //零
    for(int i=0; i<6; i++)
        for(int j=0; j<6; j++)
            for(int s=0; s<6; s++)
                res.d[i][j]=((a.d[i][j]*b.d[j][s])%mod+res.d[i][j])%mod;
    return res;
}

LL sb;
marx mult(marx t,LL n)  //矩阵快速幂 t^n
{
    marx res=marx(1);   //单位矩阵
    LL ans=1,ss=4*4;    //顺便计算了一下 4^n
    while(n)
    {
        if(n&1)res=mul(res,t),ans=(ans*ss)%mod;
        t=mul(t,t);
        ss=(ss*ss)%mod;
        n>>=1;
    }
    sb=ans;
    return res;
}

int main()
{
    LL n,m;
    while(~scanf("%I64d%I64d",&n,&m))
    {
        marx isc,ans;
        for(int i=0; i<6; i++)
        {
            for(int j=0; j<6; j++)
                isc.d[i][j]=1;  //初始化矩阵
            ans.d[1][i]=1;  //第一层各面情况
        }
        int a,b;
        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&a,&b);
            isc.d[a-1][b-1]=isc.d[b-1][a-1]=0;  //标记互斥面
        }
        LL sum=0;
        ans=mul(ans,mult(isc,n-1)); //计算矩阵幂以及与第一层结果的乘积
        for(int i=0; i<6; i++)
            sum=(sum+ans.d[1][i])%mod;  //最终求和
        printf("%I64d\n",(sb*sum)%mod); //每一层可以四面旋转
    }
    return 0;
}
