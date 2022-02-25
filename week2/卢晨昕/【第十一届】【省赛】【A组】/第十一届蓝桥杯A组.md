# 第十一届蓝桥杯A组

## 回文日期

看一下数据范围10000101<n<89991231

如果是数字的话，一个一个遍历时间上悬，但这是日期

8999-1000=7999

7999*365=2919635

这样一来，只遍历日期的话时间是够的

~~~cpp
//100
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;
string s;
ll ans1,ans2;
int v1,v2;
bool run(int y)//判断闰年
{
	if(y%4==0&&y%100!=0||y%400==0)return true;
	return false;
}
bool hui(int y,int m,int d)//判断回文
{
	if(y%10!=m/10)return false;
	if(y%100/10!=m%10)return false;
	if(y%1000/100!=d/10)return false;
	if(y/1000!=d%10)return false;
	return true;
}
bool tehui(int y,int m,int d)//判断第二种回文
{
	int a[10];
	a[1]=y/1000;a[2]=y%1000/100;a[3]=y%100/10;a[4]=y%10;
	a[5]=m/10;a[6]=m%10;a[7]=d/10;a[8]=d%10;
	if(a[1]==a[3]&&a[3]==a[6]&&a[6]==a[8]&&a[2]==a[4]&&a[4]==a[5]&&a[5]==a[7])
	{
		return true;
	}
	return false;
}
//0是平年,1是闰年 
//用来存储每月的天数
int days[2][15]=
{
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}
};
int main()
{
	cin>>s;
	int year=(s[0]-'0')*1000+(s[1]-'0')*100+(s[2]-'0')*10+s[3]-'0';
	int month=(s[4]-'0')*10+s[5]-'0';
	int day=(s[6]-'0')*10+s[7]-'0';
	while(1)
	{
		int now;
		if(run(year))now=1;
		else now=0;
		day++;
		if(day>days[now][month])//该月到头了，进位
		{
			day=1;
			month++;
		}
		if(month>12)//该年到头了，进位
		{
			month=1;
			year++;
		}
		if(hui(year,month,day)&&v1==0)
		{
			ans1=year*10000+month*100+day;
			v1=1;
		}
		if(tehui(year,month,day)&&v2==0)
		{
			ans2=year*10000+month*100+day;
			v2=1;
		}
		if(v1==1&&v2==1)break;
	}
	cout<<ans1<<endl<<ans2;
	return 0;
}
~~~



## 成绩分析

emmm

~~~cpp
//100
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;
int n;
double ave;
int maxn=0,minn=105;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		if(a>maxn)maxn=a;
		if(a<minn)minn=a;
		ave+=a;
	}
	cout<<maxn<<endl<<minn<<endl;
	printf("%0.2lf",ave/n);
	return 0;
}
~~~



## 子串分值

刚开始想的是前缀和，但是只有60分

**看到了大佬的思路**：

关键是仔细手推并且想到单独计算每一个点的贡献

回到样例 ababc 21
位置1上的a对答案有贡献的子串是 a ab 贡献为2
位置2上的b对答案有贡献的子串是 ab aba b ba 贡献为4
位置3上的a对答案有贡献的子串是 ba bab babc a ab abc 贡献为6
位置4上的b对答案有贡献的子串是 ab abc b bc 贡献为4
位置5上的c对答案有贡献的子串是 ababc babc abc bc c 贡献为5
2+4+5+4+5=21
推的时候可以认真想一下为什么这些有贡献而其他的没有，有什么特点，如果还是没什么思路可以自己再找一组样例推推看，如果还是没有那就暴力拿了50分下一题吧==

那到底特点是什么呢
对位置i的贡献，会发现有两部分。
设：位置i后出现s[i]的位置为nex[i]，位置i前出现s[i]的位置为pre[i]。
那么从pre[i]到i ，它们中的每一个都会有nex-[i]个子串含有s[i]且有贡献。
所以位置i的贡献就是(nex[i]-i)*(i-pre[i])，需要预处理出来nex与pre数组。
如果前面没出现过s[i]，pre[i]应该为0；如果后面没出现过s[i]，nex[i]应该为n+1。

注意答案应该需要开long long (5e4*5e4就已经爆了)
时间复杂度为O(n)

~~~cpp
//100
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;
string s;
ll pre[100005],nex[100005];
ll pos[30];
ll ans;
int main()
{
	cin>>s;
	for(int i=0;i<=26;i++)pos[i]=-1;
	for(int i=0;i<s.length();i++)
	{
		pre[i]=pos[s[i]-'a'];
		pos[s[i]-'a']=i;
	}
	for(int i=0;i<=26;i++)pos[i]=s.length();
	for(int i=s.length()-1;i>=0;i--)
	{
		nex[i]=pos[s[i]-'a'];
		pos[s[i]-'a']=i;
	}
	for(int i=0;i<s.length();i++)
	{
		ans+=(i-pre[i])*(nex[i]-i);
	}
	cout<<ans;
	return 0;
}
~~~



## 荒岛探险

扫描线，就是运用数学上的积分，精度设为0.001，计算每块小矩形的面积（用线的长度代替），最后加一起

由于椭圆可能是斜的，不好运用已学的知识，可以从新建立坐标系进行计算

然鹅~~~我又不会写

先粘贴个大佬的题解

~~~cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const double pi=acos(-1);
const double eps=1e-8;
double xa,ya,xb,yb,l,x[5],y[5],_y[5],res=0,site;
double dis(double a,double b,double c,double d){
    return sqrt((c-a)*(c-a)+(d-b)*(d-b));
}
bool findtuo(double now){
    double jx=(xa+xb)/2,jy=(ya+yb)/2;
    double aa=l/2;
    double cc=dis(xa,ya,xb,yb)/2;
    double bb=sqrt(aa*aa-cc*cc);
    double mid=1.0-(now-jx)*(now-jx)/(aa*aa);
    if(mid<=0) return 0;
    mid=sqrt(mid)*bb;
    _y[1]=jy-mid,_y[2]=jy+mid;
    return 1;
}
double check(double now,int pos1,int pos2){
    if( fabs(x[pos1]-x[pos2])<=eps && fabs(x[pos1]-now)<=eps ) return 1001.0;
    if(now<=min(x[pos1],x[pos2])||now>=max(x[pos1],x[pos2])) return 1001.0;
    double k=(y[pos2]-y[pos1])/(x[pos2]-x[pos1]);
    return k*(now-x[pos2])+y[pos2];
}
bool findsan(double now){
    int cnt=2;
    for(int i=1;i<=3;i++)
    {
        int nx=i+1;
        if(nx==4) nx=1;
        double mid=check(now,i,nx);
        if(mid>=1000.5) continue;
        if(cnt==3&&fabs(mid-_y[cnt])<=eps) continue;
        _y[++cnt]=mid;
    }
    if(cnt!=4) return 0;
    return 1;
}
//1 0 0 1 2          -1 0 1 0 0 1.732
double anglee(double a,double b,double c,double d){
    double now=acos( (c-a) / dis(a,b,c,d) );
    if(d-b<0) return pi+pi-now;
    return now;
}
void zhuan(int pos)
{
    double sitepos=anglee(0,0,x[pos],y[pos]);
    double val=dis(0,0,x[pos],y[pos]);
    double diff=sitepos-site;
    x[pos]=val*cos(diff);
    y[pos]=val*sin(diff);
    //printf("%lf %lf\n",x[pos],y[pos]);
}
void zhuantuo()
{
    double sitepos1=anglee(0,0,xa,ya),sitepos2=anglee(0,0,xb,yb);
    double val1=dis(0,0,xa,ya),val2=dis(0,0,xb,yb);
    double diff1=sitepos1-site,diff2=sitepos2-site;
    //printf("%lf %lf %lf\n",site,sitepos1,sitepos2);
    xa=val1*cos(diff1); ya=val1*sin(diff1);
    xb=val2*cos(diff2); yb=val2*sin(diff2);
    //printf("%lf %lf %lf %lf\n",xa,ya,xb,yb);
}
double solve(double now)
{
    if(findtuo(now)==0) return 0;
    if(findsan(now)==0) return 0;
    double mx=max(min(_y[1],_y[2]),min(_y[3],_y[4]));
    double mn=min(max(_y[1],_y[2]),max(_y[3],_y[4]));
    //printf("%.4lf %.4lf %.4lf %.4lf %.4lf %.4lf\n",now,_y[1],_y[2],_y[3],_y[4],mn-mx);
    if(mn-mx<=eps) return 0;
    return mn-mx;
}

int main()
{
    scanf("%lf%lf%lf%lf%lf",&xa,&ya,&xb,&yb,&l);
    site=anglee(xa,ya,xb,yb);
    for(int i=1;i<=3;i++) scanf("%lf%lf",&x[i],&y[i]),zhuan(i);
    zhuantuo();
    if(l<=eps||dis(xa,ya,xb,yb)>=l) return 0*printf("0.00\n");
    for(double i=-1000;i<=1000;i+=0.001)
        res+=solve(i)*0.001;
    printf("%.2lf\n",res);
    return 0;
}

~~~



## 字串排序

找规律

~~~cpp
//70
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;
int v;
string s;
int ans1,ans2;
int main()
{
	cin>>v;
	for(int i=1;i<=26;i++)
	{
		for(int j=0;j<=i;j++)
		{
			int now=0;
			for(int k=0;k<j;k++)
			{
				now+=2*2*k;
			}
			for(int k=j*2;k<=j+i-1;k++)
			{
				now+=k;
			}
			if(now==v)
			{
				ans1=i;
				ans2=j;
				break;
			}
		}
		if(ans1!=0||ans2!=0)break;
	}
	for(int i=ans1;i>=1;i--)
	{
		if(i>ans2)cout<<(char)(i+'a'-1);
		else cout<<(char)(i+'a'-1)<<(char)(i+'a'-1);
	}
	return 0;
}
~~~

