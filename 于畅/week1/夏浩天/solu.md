# 12A C&C++

## A卡片

//0用到的地方比较少，1在其余数字前，所以只需要考虑1
//在百位不为1的情况下，100内含1数量为20=1*10+10
//在千位不为1的情况下，1000内含1数量为20*10+100=300
//2000前含1数量1600
//易知答案在3000（1900）-4000（2200）间
//2021-1900=121 121-20-100-20=-19 即3181

//以下为暴力穷举验证(真比赛肯定不会分析上面那一大堆233)

```
//答案：3181
#include<iostream>
#include<string>  // to_string
using namespace std;
int main()
{
	int num = 2021;
	int i = 0;
	while (num > 0)
	{
		i++;
		string a = to_string(i);
		for (int j = 0; j < a.size(); j++)
		{
			if (a[j] == '1') num--;
			if (num <= 0) break;
		}
		

	}
	cout << i;
	return 0;

}
```



## B直线

//暴力穷举
//没想到更好的办法:(；ﾞﾟ'ωﾟ')

```
//答案：40257
#include <iostream>
#include<map>
using namespace std;
struct points
{
	double x, y;
};
points point[1000000];
long long en = 0;  // 最终结果
int num;
map<pair<double, double>, bool> ma;
int main()
{
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 21; j++)
		{
			point[num].x = i;
			point[num].y = j;
			num++;
		}
	for(int i=0;i<num;i++)
		for (int j = i+1; j < num; j++)
		{
			if (point[i].x == point[j].x)
				continue;
			else
			{
				double k = (point[i].y - point[j].y) / (point[i].x - point[j].x);
				double b = (point[j].x * point[i].y - point[j].y * point[i].x) / (point[j].x - point[i].x);  //如果用y1-kx1的方式求会导致误差增大（尚不知为什么表现为数量减小）
				if (!ma[{k, b}])
				{
					ma[{k, b}] = true;
					en++;
				}
			}
		}
	cout << en + 20;
	return 0;
}
```



## C货物摆放

// 即 num=a*b*c，有多少种组合方案

```
//答案：2430
#include <iostream>
using namespace std;
int main()
{
	long long num = 2021041820210418;
	while (num != 1)
	{
		for (int i = 2; i <= num; i++)
		{
			if (num % i == 0)  // i是num的因数
			{
				cout << i << " ";  //输出因数以便接下来的操作（反正是填空）
				num /= i;
				break;
			}
		}
	}
	return 0;
}
// 通过上面输出知因数为 2 3 3 3 17 131 2857 5882353
// 即 3^5* (3+6+1)=2430
// 注意：如果你没有给任意位置分配数字，该位置为1 !
```



## D路径

//floyed算法（会超时，问题不大）

```
//答案：10266837

#include <iostream>
using namespace std;
int en[2030][2030];
int fff(int x, int y)
{
    if (y == 0)
        return x;
    else
        return fff(y, x % y);
}
int main()
{
    memset(en, 0x3f, sizeof(en));
    for (int i = 1; i <= 2021; i++)
        for (int j = i + 1; j <= 2021; j++)
        {
            if (j - i > 21)
                continue;
            int cost = i / fff(i, j) * j;
            en[i][j] = cost;
            en[j][i] = cost;
        }
    for (int k = 1; k <= 2021; k++)
        for (int i = 1; i <= 2021; i++)
            for (int j = 1; j <= 2021; j++)
            {
                en[i][j] = min(en[i][k] + en[k][j], en[i][j]);
            }
    cout << en[1][2021];
    return 0;
}
```



## E回路计数

```
//答案：881012367360
//参考：https://blog.csdn.net/qq_36306833/article/details/121872050
//看得不是太懂，还在尝试理解，见谅
//尝试过dfs然后十分钟后给了错误答案（捂脸）
#include <iostream>
using namespace std;
long long dp[1 << 21][21];
int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a % b); }//求最大公因数
bool vis(int state, int pos) //是否vis
{
    if ((state & (1 << pos)) != 0) //1 << pos == 2的pos次方
        return true;
    else 
        return false;
}

bool IsConnect(int x, int y) //是否相连
{
    if (x == 0 || y == 0) 
        return true;
    if (gcd(x + 1, y + 1) == 1) 
        return true;
    else 
        return false;
}

long long f(int state, int fp) 
{
    if (dp[state][fp] != -1) 
        return dp[state][fp];
    if (!vis(state, fp)) 
    return dp[state][fp]=0;

    long long ret = 0;

    for (int net = 0; net < 21; net++) 
    {
        if (!vis(state, net)) 
            continue;
        if (!IsConnect(net, fp)) 
            continue;
        ret += f(state - (1 << fp), net);
    }
    return dp[state][fp] = ret;
}

int main() 
{
    memset(dp, -1, sizeof(dp));
    long long int ans = 0;
    int finalState = (1 << (21)) - 1;
    dp[1][0] = 1;

    for (int i = 0; i < 21; i++) 
    {
        long long temp = f(finalState, i);
        ans += temp;
    }
    cout << ans;
    return 0;
}

```



## F砝码称重

```
//dp与伪背包

#include <iostream>
using namespace std;
long long sum = 0;
bool dp[110][200001]; // 重量j 前i个砝码
int w[110];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i], sum += w[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= sum; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (dp[i - 1][j] == 0)
            {
                if (w[i] == j)
                    dp[i][j] = 1;
                if (dp[i - 1][j + w[i]])
                    dp[i][j] = 1;
                if (dp[i - 1][abs(j - w[i])])
                    dp[i][j] = 1;
            }
        }
    long long en = 0;
    for (int i = 1; i <= sum; i++)
        if (dp[n][i])
            en++;
    cout << en;
    return 0;
}
```



## I括号序列

//左边的匹配数乘右边的匹配数

~~~
#include <iostream>
using namespace std;
const long long MOD = 1e9 + 7;
int dp[5001][5001];
bool vis[5001][5001];
char str[5001];
int n;
long long gg() 
{
    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    dp[0][0] = 1;
    vis[0][0] = true;

    for (int i = 1; i <= n; i++)
    {
        if (str[i - 1] == '(') 
        {
            for (int j = 1; j <= n; j++) 
            {
                dp[i][j] = dp[i - 1][j - 1];
                vis[i][j] = vis[i - 1][j - 1];
            }
        }
        else
        {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
            vis[i][0] = vis[i - 1][0] | vis[i - 1][1];
            for (int j = 1; j <= n; j++) 
            {
                dp[i][j] = (dp[i - 1][j + 1] + dp[i][j - 1]) % MOD;
                vis[i][j] = vis[i - 1][j + 1] | vis[i][j - 1];
            }
        }
    }
    for (int i = 0; i <= n; i++) 
        if (vis[n][i] != 0) 
            return dp[n][i];
    return -1;
}
int main() 
{
    cin >> str;
    n = strlen(str);
    long long l = gg();
    reverse(str, str + n);//翻转
    for (int i = 0; i < n; i++) 
    {
        if (str[i] == ')') 
            str[i] = '(';
        else 
            str[i] = ')';
    }
    long long r = gg();
    cout << (l * r) % MOD;
    return 0;
}
~~~



