#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<stack>
#define int long long
#define mod 1000000007
#define maxn 5005
using namespace std;

int read()
{
	int x=1,res=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		x=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		res=res*10+(c-'0');
		c=getchar();
	}
	return res*x;
}
int f[maxn][maxn],t[maxn],last,cnt;
char a[maxn],b[maxn];
stack<char>s;
signed main()
{
	cin>>(a+1);
	int n=strlen(a+1);
	for(int i=n;i>=1;i--) b[i]=a[n-i+1];
	f[0][0]=1;t[0]=1;cnt=1;
	for(int i=1;i<=n;i++)
	{
		if(!s.size()&&a[i]==')')
			for(int j=1;j<=n;j++)
				f[i][j]=t[j-1];
		else if(a[i]=='(')
		{
			s.push('(');
			continue;
		}
		else {
			s.pop();
			if(s.size()) {cnt++;continue;}
			for(int j=cnt;j<=n;j++)
				f[i][j]=f[last][j-cnt];
			cnt=1;
		}
		for(int j=n;j>=0;j--)
		t[j]=(t[j+1]+f[i][j])%mod;
		last=i;
//		for(int j=1;j<=n;j++)
//		cout<<f[i][j]<<" ";puts("");
	}
	int ans1=0,ans2=0;
	for(int i=1;i<=n;i++)
		ans1=(ans1+f[last][i])%mod;
	memset(f,0,sizeof(f));
	memset(t,0,sizeof(t));
	f[0][0]=1;t[0]=1;last=0;cnt=1;
	while(s.size()) s.pop();
	for(int i=1;i<=n;i++)
	{
		if(!s.size()&&b[i]=='(')
			for(int j=1;j<=n;j++)
				f[i][j]=t[j-1];
		else if(b[i]==')')
		{
			s.push(')');
			continue;
		}
		else {
			s.pop();
			if(s.size()) {cnt++;continue;}
			for(int j=cnt;j<=n;j++)
				f[i][j]=f[last][j-cnt];
			cnt=1;
		}
		for(int j=n;j>=0;j--)
		t[j]=(t[j+1]+f[i][j])%mod;
		last=i;
	}
	for(int i=1;i<=n;i++)
		ans2=(ans2+f[last][i])%mod;
	if(ans1==0) ans1=1;if(ans2==0) ans2=1;
	cout<<(ans1*ans2)%mod;
	return 0;
	
}