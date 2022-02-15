#include<bits/stdc++.h>//前一半定全部
using namespace std;
int n,y[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool print(int x)
{
    int a[5],now=x,t=1;
    for(int i=1;i<=4;i++)
        a[i]=now%10,now/=10;
    x*=10000;
    for(int i=4;i>=1;i--)
        x+=t*a[i],t*=10;
    if(x<=n) return 0;
    printf("%d\n",x);
    return 1;
}
bool run(int x)
{
    if(x%400==0) return 1;
    if(x%100!=0&&x%4==0) return 1;
    return 0;
}
bool check1(int x)  //检查日期是否合法
{//已经保证了回文 只需要保证日期合法即可
    int yue=(x%10)*10+(x/10)%10; //提取日期
    int day=((x/100)%10)*10+(x/1000);
    if(yue<=0||yue>=13) return 0; //检查yue是否合法
    if(yue==2&&run(x))  //检查day是否合法
    {
        if(day<=29) return 1;
        return 0;
    }
    else if(day<=y[yue]&&day>=1) return 1;
    return 0;
}
bool check2(int x)
{//同样已经保证了回文  可以利用check1检查合法日期
    if(check1(x)==0) return 0;  //首先保证日期合法
    int a=(x/10)%10,b=x%10;     //检查ABAB
    if( x/1000==a && ((x/100)%10)==b ) return 1;
    return 0;
}
void solve(int x)
{
    for(int i=x;i<=9999;i++)
        if(check1(i)){ //找回文
            if(print(i)==0) continue;
            break;
        }
    for(int i=x;i<=9999;i++)
        if(check2(i)){  //找ABAB
            if(print(i)==0) continue;
            break;
        }
}
int main()
{
    scanf("%d",&n);
    solve(n/10000);
    return 0;
}
