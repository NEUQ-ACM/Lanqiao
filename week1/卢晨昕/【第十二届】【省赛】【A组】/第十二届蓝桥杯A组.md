# 第十二届蓝桥杯A组

这、这不对吧，今天谁要陷害我

TNND，给我玩阴的是吧，直接来吧

感觉蓝桥杯全是DP，看来得苦练DP了

## 砝码称重

我用dfs只做出了90分，最后10分超时了。。。等等再研究正确做法，应该是DP

```cpp
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int n;
int ans=0;
int w[105];
int v[100005];//记录某个重量可否称到
map<int,int>lo[105];//用于剪枝
//now表示当前处理到第now个砝码
//suml表示当前左边重量
//sumr表示当前左边重量
void dfs(int now,int suml,int sumr)
{
	if(suml-sumr>0)v[suml-sumr]=1;
	if(lo[now][suml-sumr]==1)return;
    //若到第now个砝码时左右相差suml-sumr的情况出现过就不用再往下重复计算了
	lo[now][suml-sumr]=1;
	if(now==n)return;
	dfs(now+1,suml,sumr);//不选择当前砝码
	dfs(now+1,suml+w[now+1],sumr);//将当前砝码加到左边
	dfs(now+1,suml,sumr+w[now+1]);//将当前砝码加到右边
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	sort(w+1,w+1+n);//不排序只有80
	dfs(1,0,0);
	dfs(1,w[1],0);
	dfs(1,0,w[1]);
	for(int i=1;i<=100000;i++)
	{
		if(v[i]==1)ans++;
	}
	cout<<ans;
	return 0;
}
```



## 异或数列

博弈论，emmm

**1.平局**

如果平局，则A=B

而A=0^xa^xb^......

B=0^xc^xd^...

所以此时x1^x2^x3^......^xn=0

**2.先手胜**

此时需要A和B从高到低第一个不相同的二进制位上，A为1，B为0

所以再这一位上，A要取得奇数个1，B要取得偶数个1

若某一位有偶数个1，则二人都拿一半的1，无法分出胜负

所以从奇数个1的位数突破

如果有奇数个1且n为奇数,则A一定可以最终取到奇数个1，A必胜

如果有奇数个1且n为偶数,则B一定可以最终取到奇数个1，A必败

~~~cpp
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int t;
int n,sum;
int x;
int num[23];
int main()
{
	cin>>t;
	while(t--)
	{
        memset(num,0,sizeof(num));
        sum=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>x;
			sum^=x;
			int cnt=1;
			while(x)
			{
				if(x&1)num[cnt]++;//统计第cnt二进制位上1的个数
				cnt++;
				x>>=1;
			}
		}
		if(!sum)cout<<"0"<<endl;
		else
		{
			for(int i=20;i>0;i--)
			{
				if(num[i]==1)
				{
					cout<<"1"<<endl;
					break;
				}
				else if(num[i]%2==1)
				{
					if(n%2==1)
					{
						cout<<"1"<<endl;
						break;
					}
					else
					{
						cout<<"-1"<<endl;
						break;
					}
				}
			}
		}
	}
	return 0;
}
~~~



## 左孩子右兄弟

dfs，从后代向父代计算，某个人的最大深度=儿子个数+最深的儿子的深度

就是把最深的儿子放在所有兄弟的最下边

~~~cpp
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int n;
int f[100005];
int num[100005];
int v[100005];
int d[100005];
void dfs(int now)
{
	if(now==1)return;
	int fa=f[now];
	d[fa]=max(d[fa],num[fa]+d[now]);
	dfs(fa);
}
int main()
{
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&f[i]);
		num[f[i]]++;
		v[f[i]]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(!v[i])
		{
			d[i]=1;
			dfs(i);
		}
	}
	cout<<d[1]-1;
	return 0;
}
~~~



## 括号序列

DP，不太会，先粘个答案

~~~cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using LL=long long;
const int N = 5005;
int f[N][N];
int mod=1e9+7;
string s;
int n;
LL get(){
    memset(f,0,sizeof f);
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        if(s[i-1]=='('){
            for(int j=1;j<=n;j++)
                f[i][j]=f[i-1][j-1];
        }
        else{
            f[i][0]=(f[i-1][1]+f[i-1][0])%mod;
            for(int j=1;j<=n;j++)
                f[i][j]=(f[i-1][j+1]+f[i][j-1])%mod;
        }
    }
    for(int i=0;i<=n;i++)
        if(f[n][i])
            return f[n][i];
    return -1;
}
int main(){
    cin>>s;
    n=s.size();
    LL x=get();
    reverse(s.begin(),s.end());
    for(int i=0;i<n;i++){
        if(s[i]==')')
            s[i]='(';
        else
            s[i]=')';
    }
    LL y=get();
    cout<<(x*y)%mod;
}

~~~



## 双向排序

由题意知，100分的数据中，有些排序的操做其实是包含再其他操作中的，可以舍去

但是，我不会舍，=_=，60分拿走不谢

~~~cpp
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define mod 1000000007
using namespace std;
int n,m;
int a[100005];
int w[100005];
void mergeSortHigh(int arr[],int l,int mid,int r)
{
	int left=l,right=mid+1;
	int len=r-l+1;
	int i=0;
	while(left<=mid&&right<=r)
	{
		if(arr[left]<=arr[right])
		{
			w[++i]=arr[left++];
		}
		else w[++i]=arr[right++];
	}
	while(left<=mid)w[++i]=arr[left++];
	while(right<=r)w[++i]=arr[right++];
	for(int i=1;i<=len;i++)
	{
		arr[l+i-1]=w[i];
	}
}
void mergeHigh(int arr[],int l,int r)
{
	if(l==r)return;
	int mid=(l+r)>>1;
	mergeHigh(arr,l,mid);
	mergeHigh(arr,mid+1,r);
	mergeSortHigh(arr,l,mid,r);
}

void mergeSortLow(int arr[],int l,int mid,int r)
{
	int left=l,right=mid+1;
	int len=r-l+1;
	int i=0;
	while(left<=mid&&right<=r)
	{
		if(arr[left]>=arr[right])
		{
			w[++i]=arr[left++];
		}
		else w[++i]=arr[right++];
	}
	while(left<=mid)w[++i]=arr[left++];
	while(right<=r)w[++i]=arr[right++];
	for(int i=1;i<=len;i++)
	{
		arr[l+i-1]=w[i];
	}
}
void mergeLow(int arr[],int l,int r)
{
	if(l==r)return;
	int mid=(l+r)>>1;
	mergeLow(arr,l,mid);
	mergeLow(arr,mid+1,r);
	mergeSortLow(arr,l,mid,r);
}
pair<int,int>x[100005];
int top=0;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		a[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int p,q;
		cin>>p>>q;
		if(top==0)
		{
			x[++top]={p,q};
		}
		else
		{
			if(p==0)
			{
				if(x[top].first==0&&q>x[top].second)
				{
					x[top]={p,q};
				}
				else if(x[top].first==0&&q<=x[top].second)continue;
				else if(x[top].first==1)
				{
					x[++top]={p,q};
				}
			}
			else if(p==1)
			{
				if(x[top].first==1&&q<x[top].second)
				{
					x[top]={p,q};
				}
				else if(x[top].first==1&&q>=x[top].second)continue;
				else if(x[top].first==0)
				{
					x[++top]={p,q};
				}
			}
		}
	}
	for(int i=1;i<=top;i++)
	{
		if(x[i].first==0)
		{
			mergeLow(a,1,x[i].second);
		}
		else
		{
			mergeHigh(a,x[i].second,n);
		}
	}
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	return 0;
}
~~~



## 分果果

正解DP，我去学习了

~_~