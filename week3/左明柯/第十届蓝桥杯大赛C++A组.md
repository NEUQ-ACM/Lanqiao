### 第十届蓝桥杯大赛C++A组

#### A.平方和

暴力遍历就可以

```c++
#include <bits/stdc++.h>
using namespace std;
int f(int num){
	int x=num;
	int y;
	int flag=0;
	while(x){
		y=x%10;
		if(y==2||y==0||y==1||y==9){
			flag=1;
			return 1;
		}
		x/=10;
	}
	if(flag==0) return 0;
} 
int main(){
long long sum=0;
for(int i=1;i<=2019;i++){
	if(f(i)) sum+=i*i;
}
cout<<sum;
return 0;

}

```

#### B.数列求值

递归加取余

```c++
#include <bits/stdc++.h>
using namespace std;
int main(){
int a,b,c;
a=1;b=1;c=1;
for(int i=4;i<=20190324;i++){
	int temp=(a+b+c)%10000;
	a=b;
	b=c;
	c=temp;
}
cout<<c;

return 0;

}
```

#### C.最大降雨量

推理

```c++
#include <bits/stdc++.h>
using namespace std;
int main(){

cout<<34;

return 0;

}

```

#### D.迷宫

bfs+记录路径

```c++
#include<bits/stdc++.h>
using namespace std;
int n=30,m=50;
int minn=0x3f3f3f3f;//定义一个最大值
int mins[80][80];//存储到达每个点最短步数
int ax[5]={0,-1,1,0};
int ay[5]={1,0,0,-1};//题上要求字典序最小给定的顺序为D<L<R<U,即下，左，右，上
char map1[80][80];
char a[2000],str[5]={'D','L','R','U'};//此处同理要字典序最小
int book[80][80];

void dfs(int x,int y,int step){
	int i,k,tx,ty;
	if(x==n-1&&y==m-1){
		minn=min(minn,step);
		for(i=0;i<minn;i++)
			printf("%c",a[i]);//输出所走的最短路径
		printf("\n");
		return;
	}
	for(k=0;k<4;k++){
		tx=x+ax[k];
		ty=y+ay[k];
		if(tx<0||ty<0||tx>n-1||ty>m-1||step+1>=mins[tx][ty])
			continue;
		if(book[tx][ty]==0 && map1[tx][ty]=='0'){
			book[tx][ty]=1;
			mins[tx][ty]=step+1;//存储到达每个点的最短步数
			a[step]=str[k];//存储相应的走的字母，因为我的next数组与str数组是对应的所以此处可以用str[k]表示当前走的方向
			dfs(tx,ty,step+1);
			book[tx][ty]=0;
		}
	}
}
int main(){
	int i,j;
	for(i=0;i<n;i++)
		scanf("%s",map1[i]);
	memset(book,0,sizeof(book));
	memset(mins,0x3f3f3f3f,sizeof(mins));
	book[0][0]=1;
	dfs(0,0,0);
	return 0;
}

```

#### E.RSA解密

fxf

```c++
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e8+10;
const LL n = 1001733993063167141ll;
const LL p = 891234941ll;
const LL q = 1123984201ll;
const LL d = 212353;
const LL c = 20190324;
int a[maxn];
int sushu[maxn/10];
bool notPrime[maxn]; ///筛素数分解不出来，目测是9位数*10位数 
int cnt;
void getPrime(int n)
{
	for(int i=2;i<=n;++i)
	{
		if(!notPrime[i]) sushu[cnt++] = i;
		for(int j=0;j<cnt&&1ll*i*sushu[j]<=n;++j)
		{
			notPrime[i*sushu[j]] = true;
			if(i%sushu[j]==0) break; 
		} 
	}
	for(int i=0;i<20;++i) cout<<sushu[i]<<" ";cout<<endl;
}
void fenjie(LL x)
{
	cout<<x<<" = 1";
	for(int i=0;i<cnt&&sushu[i]<=x/sushu[i];++i)
	{
		while(x%sushu[i]==0)
		{
			cout<<" * "<<sushu[i];
			x /= sushu[i];
		}
	}
	if(x>1) cout<<" * "<<x;
	cout<<endl;
}
void BF(LL x)
{
	cout<<x<<" = "; 
	for(LL i=1e8+1;i<x;i+=2)
	{
		if(x%i==0)
			cout<<i<<" * ",x/=i;
	}
	cout<<x<<endl;
}
void exgcd(LL a,LL b,LL &d,LL &x,LL &y)
{
	if(b==0)
	{
		d = a; x = 1; y = 0; return;
	}
	exgcd(b,a%b,d,y,x);
	y -= (a/b)*x;
}
LL rev(LL t,LL m)
{
	LL d,x,y;
	exgcd(t,m,d,x,y);
	return (x%m+m)%m;
}
LL fast_product(LL a,LL b,LL mod)
{
	LL ans = 0;
	while(b)
	{
		if(b&1) ans = (ans+a)%mod;
		a = (a+a)%mod;
		b>>=1;
	}
	return ans;
} 
LL fast_pow(LL a,LL b,LL mod)
{
	LL ans = 1;
	while(b)
	{
		if(b&1) ans = fast_product(ans,a,mod);
		a = fast_product(a,a,mod);
		b>>=1;		
	} 
	return ans;
}
int main()
{
	//getPrime(maxn-5);
	//fenjie(n);
	BF(n);
	LL y = (p-1)*(q-1);
	LL e = rev(d,y);
	LL answer = fast_pow(c,e,n);
	cout<<answer<<endl;

	return 0;
}


```

#### 完全二叉树

简单结构题

```c++
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e8+10;
const LL n = 1001733993063167141ll;
const LL p = 891234941ll;
const LL q = 1123984201ll;
const LL d = 212353;
const LL c = 20190324;
int a[maxn];
int sushu[maxn/10];
bool notPrime[maxn]; ///筛素数分解不出来，目测是9位数*10位数 
int cnt;
void getPrime(int n)
{
	for(int i=2;i<=n;++i)
	{
		if(!notPrime[i]) sushu[cnt++] = i;
		for(int j=0;j<cnt&&1ll*i*sushu[j]<=n;++j)
		{
			notPrime[i*sushu[j]] = true;
			if(i%sushu[j]==0) break; 
		} 
	}
	for(int i=0;i<20;++i) cout<<sushu[i]<<" ";cout<<endl;
}
void fenjie(LL x)
{
	cout<<x<<" = 1";
	for(int i=0;i<cnt&&sushu[i]<=x/sushu[i];++i)
	{
		while(x%sushu[i]==0)
		{
			cout<<" * "<<sushu[i];
			x /= sushu[i];
		}
	}
	if(x>1) cout<<" * "<<x;
	cout<<endl;
}
void BF(LL x)
{
	cout<<x<<" = "; 
	for(LL i=1e8+1;i<x;i+=2)
	{
		if(x%i==0)
			cout<<i<<" * ",x/=i;
	}
	cout<<x<<endl;
}
void exgcd(LL a,LL b,LL &d,LL &x,LL &y)
{
	if(b==0)
	{
		d = a; x = 1; y = 0; return;
	}
	exgcd(b,a%b,d,y,x);
	y -= (a/b)*x;
}
LL rev(LL t,LL m)
{
	LL d,x,y;
	exgcd(t,m,d,x,y);
	return (x%m+m)%m;
}
LL fast_product(LL a,LL b,LL mod)
{
	LL ans = 0;
	while(b)
	{
		if(b&1) ans = (ans+a)%mod;
		a = (a+a)%mod;
		b>>=1;
	}
	return ans;
} 
LL fast_pow(LL a,LL b,LL mod)
{
	LL ans = 1;
	while(b)
	{
		if(b&1) ans = fast_product(ans,a,mod);
		a = fast_product(a,a,mod);
		b>>=1;		
	} 
	return ans;
}
int main()
{
	//getPrime(maxn-5);
	//fenjie(n);
	BF(n);
	LL y = (p-1)*(q-1);
	LL e = rev(d,y);
	LL answer = fast_pow(c,e,n);
	cout<<answer<<endl;

	return 0;
}


```



```c++
#include <bits/stdc++.h>
using namespace std;
int main(){
int a,b,c;
a=1;b=1;c=1;
for(int i=4;i<=20190324;i++){
	int temp=(a+b+c)%10000;
	a=b;
	b=c;
	c=temp;
}
cout<<c;

return 0;

}
```