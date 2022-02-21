## A平方和

**遍历1-2019，将所有数转字符串，查找是否有2,0,1,9，有便加上其平方**

答案：2658417853

~~~
#include<iostream>
#include<string>
using namespace std;
int main()
{
	long long sum = 0;
	for (int i = 1; i <= 2019; i++)
	{
		if (to_string(i).find('2') != -1 || to_string(i).find('0') != -1 || to_string(i).find('1') != -1 || to_string(i).find('9') != -1)
			sum = sum + i * i;
	}
	cout<<sum;
	return 0;
}
~~~



## B数列求值

没啥说的，千位取模

答案：4659

~~~
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int a=1, b=1, c = 1;
	for (int i = 20190321; i >0; i--)//20190324-3
	{
		int d = a;
		a = d + b + c;
		b = c;
		c = d;
		a = a % 10000;
		b = b % 10000;
		c = c % 10000;
	}
	cout<<a;
	return 0;
}
~~~



## C最大降雨量

//一开始想了很久除暴力穷举外的方法，没想出来
//后来看了看别人怎么写的......只能说人与人之间真的有差距
//参考：https://blog.csdn.net/weixin_40532377/article/details/88861587
//将每周降水量从大到小排序，然后每周的中位数从大到小排序，那么第四周第四天的法术符的数字就是本周的总降水量，大于该降水量总共有3+4+4+4=15天
答案：49-15=34



## D迷宫

bfs基础

~~~
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

char ma[30][50];
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,-1,1,0 };
char l[4] = { 'D','L','R','U' };
int vis[30][50] = { 0 };

struct point
{
	int x, y;
	string road;
	point(int a, int b)
	{
		x = a;
		y = b;
	}
};

void bfs()
{
	queue<point> q;
	point p(0, 0);
	p.road = "";
	q.push(p);
	vis[0][0] = 1;
	while (!q.empty())
	{
		point t = q.front();
		q.pop();
		if (t.x == 29 && t.y == 49)
		{
			cout << t.road << endl;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int x = t.x + dx[i];
			int y = t.y + dy[i];
			if (x >= 0 && x < 30 && y >= 0 && y < 50)
			{
				if (ma[x][y] == '0' && !vis[x][y])
				{
					point tt(x, y);
					tt.road = t.road + l[i];//记录路径
					q.push(tt);
					vis[x][y] = 1;
				}
			}
		}
	}
}

int main()
{
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 50; j++)
			cin>>ma[i][j];
	bfs();
	return 0;
}
~~~



## ERSA解密

~~~
//确实不太会......慢慢消化吧......（悲）
//来源：https://blog.csdn.net/weixin_43107805/article/details/89525061
#include<iostream>
using namespace std;
const int N = 500000;
long long n = 1001733993063167141;
long long p = 891234941;
long long q = 1123984201;
long long c = 20190324; //密文 
long long d = 212353;   //公钥
long long m = (p - 1) * (q - 1); //求 X = c^e mod (p-1)*(q-1); 
long long e; // d*e≡1(mod Φ(n))     
long long ex_gcd(long long a, long long b, long long& x, long long& y)//扩展欧几里得 
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	int r = ex_gcd(b, a % b, x, y);
	int t = x;
	x = y;
	y = t - a / b * y;
	return r;
}
long long mod_reverse(long long a, long long n)//ax=1(mod n) 求a的逆元x d*e=1mod(m)
{
	long long d, x, y;
	d = ex_gcd(a, n, x, y);
	if (d == 1)
		return (x % n + n) % n;
	else
		return -1;
}
//快速乘 
long long mult_mod(long long a, long long b, long long m) // 计算 a*b mod m
{
	long long res = 0;
	while (b) 
	{
		if (b & 1) res = (res + a) % m; 
		a = (a * 2) % m;
		b >>= 1;// == 'b*=2'
	}
	return res;
}
//快速幂      
long long quick_mod(long long a, long long b, long long m)
{
	long long ans = 1;
	a = a % m;
	while (b != 0)
	{
		if (b & 1) ans = mult_mod(ans, a, m) % m;//(ans*a)%m;             
		a = mult_mod(a, a, m) % m;  //a=(a*a)%m; 

		b >>= 1;
	}
	return ans;

}
int main()
{
	cout << "m=" << m << endl;
	e = mod_reverse(d, m);
	cout << "e=" << e << endl;
	cout << "d=" << d << endl;

	long long x = quick_mod(c, e, m);
	cout << x << endl; //明文 
	cout << quick_mod(x, d, m) << endl;
}
~~~



## F完全二叉树的权值

挺简单的完全二叉树，理解其含义就基本能写

~~~
#include<iostream>
using namespace std;
int a[100005];
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int cs = 1;//层数
    long long maxx = a[1];
    long long en = 1;//层数
    int num = 1;//该层的节点数
    int p = 2;//下一层开头指针位置
    while(true)
    {
        cs++;
        num *= 2;
        long long sum = 0;
        for (int j = p; j <= min(p + num - 1, n); j++)
            sum += a[j];
        if (sum > maxx)
        {
            en = cs;
            maxx = sum;
        }
        p += num;
        if (p > n)
            break;
    }
    cout << en << endl;
    return 0;
}
~~~



## H修改数组

~~~
//参考：https://blog.csdn.net/linruier2017/article/details/88803441
#include<iostream>
using namespace std;
int bit[2000001];
int n = 1000001;
int sum(int i)
{
    int s = 0;
    while (i > 0)
    {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}
void add(int i, int x)
{
    while (i <= n)
    {
        bit[i] += x;
        i += i & -i; // 位运算，i&(-i)运算的功能为返回 i 的二进制数表示为１的最低位的权值
    }
}
bool vis[1000005];
int ans[100005];
int N;
int a[100005];
int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < N; i++)
    {
        if (!vis[a[i]])//没出现过
        {
            ans[i] = a[i];
            vis[a[i]] = 1;
            add(a[i], 1);
        }
        else
        {
            int l = a[i]; int r = 1000002;
            int mid;
            while (r - l > 1)
            {
                mid = (l + r) / 2;
                int l = mid - a[i] + 1;
                int cnt = sum(mid) - sum(a[i] - 1);
                if (cnt < l)r = mid;
                else l = mid;
            }
            ans[i] = r;
            vis[r] = 1;
            add(r, 1);
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (i == N - 1)
            printf("%d%c", ans[i], ' ');
        else
            printf("%d%c", ans[i], '\n');
    }
    return 0;
}
~~~

