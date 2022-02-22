## A：门牌制作

从1到2020将每个数字拆开统计2的个数。

```c++
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long ans=0;
	for(int i=1;i<=2020;i++){
		int x=i;
		while(x){
			if(x%10==2)
			ans++;
			x/=10;
		}
	}
	cout<<ans;
 } 
```



## B：既约分数

暴力枚举

```c++
#include<bits/stdc++.h>
using namespace std;
int ans;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	for(int i=1;i<=2020;i++)
		for(int j=i+1;j<=2020;j++)
			if(gcd(i,j)==1)
				ans++;
	cout<<ans;
} 
```



## C：蛇形填数

因为求的是对角上的据观察可得规律

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t = 1, base = 0;
	for (int i = 2; i <= 20; i++) {
		base += 4;
		t += base;
	}
	cout << t;
}
```



## D：七段码

~~dfs+并查集？~~还是手算快。

分 7 种情况：
亮一个灯：有 7 种情况，1、2、3、4、5、6、7；
亮两个灯：有 12、13、24、25、…等等；共10
亮三个灯：有 123、124、125、134、136、234、257…等等；共16
亮四个灯，这时不要直接数四个灯，情况与灭三个灯是等价的：灭 123、灭 124…等等；共20
亮五个灯，与灭两个灯等价：灭 12、灭 13、灭 14、…等等；共19
亮六个灯，与灭一个灯等价，有 7 种情况；
亮七个灯，有 1 种情况。
对以上所有情况求和 为 80

## E：平面分割

<u>蒟蒻完全不会</u>

## F：成绩分析

没啥好说

```c++
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,mx=-1,mn=101,sum=0,x;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		mx=max(mx,x);
		mn=min(mn,x);
		sum+=x;
	}
	cout<<mx<<endl<<mn<<endl;
	cout<<fixed<<setprecision(2)<<(double)sum/n;
}
```



## G：回文日期

<u>蒟蒻完全不会</u>

## H：子串分值

字符s[i]有贡献的子字符串为[last[i]+1,i]和[i,next[i]-1]组成的子字符串”.

```c++
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
char s[N];
int vis[40];
int main() { 
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  int  ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (i - vis[s[i] - 'a']) * (n - i + 1);
    vis[s[i] - 'a'] = i; //记录上次的出现位置 
  }
  cout << ans << endl;
  return 0;
}
```

