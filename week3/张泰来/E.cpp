#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector <int> v;
int p = 891234941,q = 1123984201,cnt;
ll s = 1ll * (p - 1) * (q - 1),x,y,d = 212353;
__int128 ans,c = 20190324,e,n = 1001733993063167141;
void exgcd(ll a,ll b,ll &x,ll &y)
{
	if (!b) x = 1,y = 0;
	else {
		exgcd(b,a % b,x,y);
		ll t = x;
		x = y;
		y = t - a / b * y;
	}
	return;
}
__int128 pow(__int128 x,__int128 y)
{
	__int128 sum = 1;
	for (;y;y >>= 1,x = x * x % n)
	{
		if (y & 1)
		{
			sum = sum * x % n;
		}
	}
	return sum;
}
void print(__int128 x)
{
	int t[45],cnt = 0;
	memset(t,0,sizeof(t));
	while (x)
	{
		t[++cnt] = x % 10;
		x /= 10;
	}
	for (int i = cnt;i >= 1; i--)
		printf("%d",t[i]);
	printf("\n");
	return;
}
int main()
{
	//cout << LLONG_MAX << endl;
	exgcd(d,s,x,y);
	e = (x % s + s) % s;
	ans = pow(c,e);
	print(ans);
	return 0;
}
