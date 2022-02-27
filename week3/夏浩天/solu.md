## A门牌制作

枚举1-2020，用to_string转字符串，枚举字符串中所有字符，有'2'便en++

~~~
//答案：624
#include<iostream>
#include<string>//to_string
using namespace std;
int en = 0;
int main()
{
	for (int i = 1; i <= 2020; i++)
	{
		string str = to_string(i);
		for (int j = 0; j < str.size(); j++)
			if (str[j] == '2')en++;
	}
	printf("%d", en);
	return 0;
}
~~~



## B既约分数

简单的辗转相除法应用

注意结果必须为1，不能直接check()

~~~
//答案：2481215
#include<iostream>
#include<string>//to_string
using namespace std;
int check(int a, int b)//辗转相除法
{
	while (b)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int start = 0;
	for (int i = 1; i <= 2020; i++)
		for (int j = 1; j <= 2020; j++)
			if (check(i, j)==1)start++;
	printf("%d", start);
	return 0;
}
~~~



## C蛇形填数

没啥说的，暴力模拟，没问题的

看了看网上的资料说可以把图转一下或者找规律，没差，减少错误率

~~~
//答案：761
#include<iostream>
#include<string>//to_string
using namespace std;
struct point
{
	int x, y, v;
};
int map[50][50];
int main()
{
	point now;
	now.x = 1;
	now.y = 1;
	now.v = 1;
	bool up_flag = 1;//是否向上
	while (true)
	{
		map[now.x][now.y] = now.v;
		if (up_flag)
		{
			if (now.y == 1)//到顶
			{
				up_flag = 0;
			}
			else
			{
				now.y--;
			}
			now.x++;
			now.v++;
		}
		else
		{
			if (now.x == 1)
			{
				up_flag = 1;
			}
			else
			{
				now.x--;
			}
			now.y++;
			now.v++;
		}
		if (now.x == 20 && now.y == 20)
		{
			cout << now.v << endl;
			break;
		}
	}
	for (int i = 1; i < 41; i++)//打印地图，方便验证
	{
		for (int j = 1; j < 41; j++)
			cout << map[i][j] << ' ';
		cout << endl;
	}
}
~~~



## D七段码

~~~
//答案：80
//递归枚举+并查集
//因为只有七条边 每条边只有选和不选的 0 1 操作，所以递归枚举七条边的所有情况 2 7 2 ^ 7 27。
//枚举完每次用并查集check一下是否所有选上的边的断点都在同一个集合里，如果在同一个集合，res++
//参考：https://www.icode9.com/content-1-908856.html
#include<iostream>
#include<string>//to_string
int book[10], res = 0, f[10];
int u[10] = { 0,1,2,3,4,5,1,3 }; //存边的端点
int v[10] = { 0,2,3,4,5,6,6,6 };
int find(int x) 
{
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}
void check()
{
    int pos = -1;
    for (int i = 1; i <= 6; i++) f[i] = i;  //并查集 初始化
    for (int i = 1; i <= 7; i++)
        if (book[i])  //如果选上了就连起来
            f[find(u[i])] = find(v[i]), pos = u[i];
    if (pos == -1) return;
    for (int i = 1; i <= 7; i++)  //检查是否在同一个集合里
        if (book[i] && find(u[i]) != find(pos))
            return;
    res++;  //在同一个集合里
    return;
}
void dfs(int x)
{
    if (x == 8) 
    {
        check();
        return;
    }
    book[x] = 1; dfs(x + 1);  //选上第x条边
    book[x] = 0; dfs(x + 1);  //不选
}
int main()      // 80
{
    dfs(1); //暴力枚举七条边是否选取  2^7次方种情况
    printf("%d\n", res);
    return 0;
}
~~~



## E平面分割

原文链接：https://blog.csdm.met/weixim_43184669/article/details/115351729
n条直线和m个圆最多可以将平面分割成几个区域
先讨论只有m个圆的情况：
圆属于封闭曲线，且两圆最多交于两点
问题转化为：有m条封闭曲线画在平面上，而任何两条封闭曲线恰好相交于两点，且任何三条封闭曲线不相交于同一点，问这些封闭曲线把平面分割成的区域个数。
推导
设 fm表示m条封闭曲线时的结果。当已有m−1条封闭曲线，加入第m条封闭曲线，为了使得答案最大，它要和已有的m−1条封闭曲线各自产生两个交点，共2(m−1)个交点，所以第m给曲线被分割成 2(m-1) 段，产生了2(m-1)个新的区域。
即：fm=f(m-1)+2(m-1)=m^2-m+2

然后依次加入直线
加入第1条直线，和m个圆，每个圆有2个交点，新产生了2m-1条线段，2条射线。1条线段增加 1个区域，2个射线共增加1个区域 ，最终增加了2m个区域。
加入第2条直线，和m个圆产生2m个交点，和直线产生 1个交点，共产生 2m条线段，2条射线。2m条线段产生2m个区域，2条射线产生2个区域，共增加2m+2个区域。
此后，产生的线段数依次加1，产生的射线数始终为2，故加入n条直线产生的区域为2m+(n−2)+2。

故计算式为：m*m-m+2*m*n+2*n+(n-1)(n-2)/2
代入m = 20 , m = 20，答案为 1391。

我尽力了（哭）



## F成绩分析

挺简单

四舍五入不知道有没有更好的方法

~~~
#include<iostream>
using namespace std;
int main()
{
	int n;
	float min = 9999999, max = -1, sum = 0;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		int lsz;
		scanf("%d", &lsz);
		if (lsz < min)min = lsz;
		if (lsz > max)max = lsz;
		sum += lsz;
	}
	float en = sum / n;
	cout << max << '\n' << min << '\n';
	printf("%.2f", en + 0.005);
}
~~~



## G回文日期

枚举前四位 N/10000-9999，直接构造回文的后四位 。判断

~~~
//参考：https://www.icode9.com/content-1-908856.html
#include<iostream>
using namespace std;
int n, y[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
bool q(int x)
{
    int a[5], now = x, tmp = 1;
    for (int i = 1; i <= 4; i++)
        a[i] = now % 10, now /= 10;
    x *= 10000;
    for (int i = 4; i >= 1; i--)
        x += tmp * a[i], tmp *= 10;
    if (x <= n) return 0;
    printf("%d\n", x);
    return 1;
}
bool check1(int x)  //检查日期是否合法
{//已经保证了回文 只需要保证日期合法即可
    int yue = (x % 10) * 10 + (x / 10) % 10; //提取日期
    int day = ((x / 100) % 10) * 10 + (x / 1000);
    if (yue <= 0 || yue >= 13) return 0; //检查yue是否合法

    if (yue == 2 && ((x % 100 == 0 && x % 400 == 0)|| (x % 100 != 0 && x % 4 == 0)))  //检查day是否合法
    {
        if (day <= 29) return 1;
        return 0;
    }
    else if (day <= y[yue] && day >= 1) return 1;
    return 0;
}
bool check2(int x)
{//同样已经保证了回文  可以利用check1检查合法日期
    if (check1(x) == 0) return 0;  //首先保证日期合法
    int a = (x / 10) % 10, b = x % 10;     //检查ABAB
    if (x / 1000 == a && ((x / 100) % 10) == b) return 1;
    return 0;
}
void solve(int x)
{
    for (int i = x; i <= 9999; i++)
        if (check1(i)) { //找回文
            if (q(i) == 0) continue;
            break;
        }
    for (int i = x; i <= 9999; i++)
        if (check2(i)) 
        {  //找ABAB
            if (q(i) == 0) continue;
            break;
        }
}
int main()
{
    scanf("%d", &n);
    solve(n / 10000);
    return 0;
}


~~~



