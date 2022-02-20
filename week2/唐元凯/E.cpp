#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstring>
#define LL long long

using namespace std;
const int maxn = 1e8 + 10;
const LL n = 1001733993063167141ll;
const LL p = 891234941ll;
const LL q = 1123984201ll;
const LL d = 212353;
const LL c = 20190324;
void process(LL x)
{
	cout << x << " = ";
	for (LL i = 1e8 + 1; i < x; i += 2)
	{
		if (x % i == 0)
			cout << i << " * ", x /= i;
	}
	cout << x << endl;
}
void exgcd(LL a, LL b, LL &d, LL &x, LL &y)
{
	if (b == 0)
	{
		d = a; x = 1; y = 0; return;
	}
	exgcd(b, a % b, d, y, x);
	y -= (a / b) * x;
}
LL rev(LL t, LL m)
{
	LL d, x, y;
	exgcd(t, m, d, x, y);
	return (x % m + m) % m;
}
LL fast_product(LL a, LL b, LL mod)
{
	LL ans = 0;
	while (b)
	{
		if (b & 1) ans = (ans + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return ans;
}
LL fast_pow(LL a, LL b, LL mod)
{
	LL ans = 1;
	while (b)
	{
		if (b & 1) ans = fast_product(ans, a, mod);
		a = fast_product(a, a, mod);
		b >>= 1;
	}
	return ans;
}
int main()
{
	process(n);
	LL y = (p - 1) * (q - 1);
	LL e = rev(d, y);
	LL ans = fast_pow(c, e, n);
	cout << "答案：" << ans << endl;
}
