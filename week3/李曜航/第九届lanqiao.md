填写代码的题真要命 又想起以前初赛了
话说我题是不是没找全啊...写代码的题怎么只看到两个...然后那个还不会
t1
?
t2

t3
求出末尾有多少2和5还有0就可以了
```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  int num2 = 0;
  int num5 = 0;
  while(cin>>n)
    {
      while(n%2 || n%5)
        {
            if(n % 2 == 0)
            {
                n /= 2;
                num2++;
            }
            if(n % 5 == 0)
            {
                n /= 5;
                num5++;
            }
        }
    }
  printf("2:%d 5:%d",num2,num5);
  return 0;
}
```
t4
二分，感谢之前让我复习的排序算法...
又想起了PTA的毒瘤输出过程的题


### 全球变暖
1000的话数据规模不大可以直接暴力
```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
char m[N][N];
int vis[N][N],ans;
int Next[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int n;
void check(int x, int y)
{
    int i,tx,ty,flag = 0;
    for(i = 0;i < 4;i++)
    {
        tx = x + Next[i][0];
        ty = y + Next[i][1];
        if(tx < 0 || tx >= n || ty < 0 || ty >= n)
            continue;
        if(vis[tx][ty] == 2 || vis[tx][ty] == 3)
            flag = 1;
        if(m[tx][ty] == '.')
        {
            vis[x][y] = 1;
            return;
        }
    }
    if(flag)
        vis[x][y] = 3;
    else
        vis[x][y] = 2;
}

void find(int x, int y)
{
    int i,tx,ty;
    check(x, y);
    for(i = 0;i < 4;i++)
    {
        tx = x + Next[i][0];
        ty = y + Next[i][1];
        if(tx < 0 || tx >= n || ty < 0 || ty >= n)
            continue;
        //搜索下一个没有搜索到的点
        if(!vis[tx][ty] && m[tx][ty] == '#')
            find(tx,ty);
    }
    return;
}
int main()
{
    scanf("%d",&n);
    ans = 0;
    for(int i = 0;i < n;i++)
        cin>>m[i];
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            if(m[i][j] == '#')
            {
                if(vis[i][j] != 0)
                    continue;
                find(i,j);
                ans++;
            }
        }
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            if(vis[i][j] == 2 && m[i][j] == '#')
                ans--;
        }
    }
    printf("%d\n",ans);
    return 0;
}

```

### 倍数问题
自己的代码A不掉（~~其实是完全错解的暴力~~）然后网上~~学习~~了一下
(K - i + K - j) % K;
