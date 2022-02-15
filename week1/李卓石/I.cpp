#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const double pi=acos(-1);//反余弦函数
const double eps=1e-8;//最下限
double xa,ya,xb,yb,l,x[5],y[5],_y[5],res=0,site;
double dis(double a,double b,double c,double d){//距离函数
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
    _y[1]=jy-mid,_y[2]=jy+mid;//椭圆方程，交点y值
    return 1;
}
double check(double now,int pos1,int pos2){//几何+代数
    if( fabs(x[pos1]-x[pos2])<=eps && fabs(x[pos1]-now)<=eps ) return 1001.0;//防止出现竖直线，没有交点
    if(now<=min(x[pos1],x[pos2])||now>=max(x[pos1],x[pos2])) return 1001.0;//
    double k=(y[pos2]-y[pos1])/(x[pos2]-x[pos1]);
    return k*(now-x[pos2])+y[pos2];//爬坡找交点的y值
}
bool findsan(double now){
    int cnt=2;
    for(int i=1;i<=3;i++)
    {
        int nx=i+1;
        if(nx==4) nx=1;
        double mid=check(now,i,nx);
        if(mid>=1000.5) continue;
        if(cnt==3&&fabs(mid-_y[cnt])<=eps) continue;//避免交点重合
        _y[++cnt]=mid;
    }
    if(cnt!=4) return 0;
    return 1;
}
double anglee(double a,double b,double c,double d){//余弦表达角度基准值
    double now=acos( (c-a) / dis(a,b,c,d) );
    if(d-b<0) return pi+pi-now;//分类角度
    return now;
}
void zhuan(int pos)//转三角的顶点
{
    double sitepos=anglee(0,0,x[pos],y[pos]);
    double val=dis(0,0,x[pos],y[pos]);
    double diff=sitepos-site;
    x[pos]=val*cos(diff);
    y[pos]=val*sin(diff);
}
void zhuantuo()//转椭圆到规范方便解方程的象限
{
    double sitepos1=anglee(0,0,xa,ya),sitepos2=anglee(0,0,xb,yb);
    double val1=dis(0,0,xa,ya),val2=dis(0,0,xb,yb);
    double diff1=sitepos1-site,diff2=sitepos2-site;
    xa=val1*cos(diff1); ya=val1*sin(diff1);
    xb=val2*cos(diff2); yb=val2*sin(diff2);
}
double solve(double now)//寻找重合部分，确定关键面积区域
{
    if(findtuo(now)==0) return 0;
    if(findsan(now)==0) return 0;
    double mx=max(min(_y[1],_y[2]),min(_y[3],_y[4]));
    double mn=min(max(_y[1],_y[2]),max(_y[3],_y[4]));
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
