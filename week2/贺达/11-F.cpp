#include<bits/stdc++.h>
using namespace std;
long long n;
long long zb(long long a,long long n)
{
	long long ans=1;
	while(n)
	{
		if(n%2==1)
        {
			ans*=a;
			n--;
		}
		
		a*=a;
		n/=2;
	}
	return ans;
}
long long dfs(long long n,long long xx,long long yy)
{
	if(n==0) return 1;
	if(n>=40) n=39;
	long long k,x,y,a,b;
	k=zb(3,n-1);//(n-1)阶时的边长，也就是n阶时，分成9个（n-1）阶时每一块的边长
	x=xx%k;//判断该点在所在块内的横纵坐标
	y=yy%k;//判断该点在所在块内的横纵坐标
	a=xx/k;//判断所在块的横纵坐标
	b=yy/k;//判断所在块的横纵坐标
	if(a==0&&b==0)     return 0*k*k+dfs(n-1,x,y);
	else if(a==0&&b==1)return 1*k*k+dfs(n-1,k-1-x,y);
	else if(a==0&&b==2)return 2*k*k+dfs(n-1,x,y);
	else if(a==1&&b==2)return 3*k*k+dfs(n-1,x,k-1-y);
	else if(a==1&&b==1)return 4*k*k+dfs(n-1,k-1-x,k-1-y);
	else if(a==1&&b==0)return 5*k*k+dfs(n-1,x,k-1-y);
	else if(a==2&&b==0)return 6*k*k+dfs(n-1,x,y);
	else if(a==2&&b==1)return 7*k*k+dfs(n-1,k-1-x,y);
	else if(a==2&&b==2)return 8*k*k+dfs(n-1,x,y);
	//根据二阶图，找出其中每一个一阶的与一阶图的横纵坐标关系
}
int main()
{
	long long x1,x2,y1,y2;
	cin>>n;
	cin>>x1>>y1;
	cin>>x2>>y2;
	//找出两点到（0，0）间的距离
	long long ans=dfs(n,x1,y1)-dfs(n,x2,y2);
	if(ans<0)ans=-ans;
	cout<<ans<<endl;
	return 0;
}
