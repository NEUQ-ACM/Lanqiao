1、~~为什么不用数学的等差公式写呢？~~这道题可以用一些简单的数学得出分子和分母，约分一下，就可以得到答案，约分就是除以最大公约数。

```C++
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    if(b==0) return a;
    else return gcd(b,a%b);
}
 int main() {
     int fz=1;
     for(int i=1;i<=20;i++) fz*=2;
     int sum = 0, fm = 1;
     for(int i=1; i<=20; ++i) {
         sum += fz / fm;
         fm *= 2;
     }
     fz = gcd(sum, fm);
     sum=sum/fz;
     fm=fm/fz;
     cout << sum << "/" << fm << endl;
     return 0;
}
```

2、需要知道2020年12月31日正好是星期天，所以直接把这所有的日期加起来除以7就可以了。

```C++
#include <iostream>
using namespace std;
int main(){
	int sumdays=0;
	for(int i=1901;i<=2000;i++){
		if((i%4==0&&i%100!=0)||i%400==0) sumdays+=366;
		else sumdays+=365;
	}
	cout << sumdays/7 << endl;
}
```

3、求末尾零的个数其实就是求所有2的因子和5的因子再求最小的那个就可以了。

```C++
#include <iostream>
using namespace std;
int main(){
	int num;
	int NumFive=0,NumTwo=0;
	while(cin>>num){
		while(num%2==0){
			NumTwo++;
			num/=2;
		}
		while(num%5==0){
			NumFive++;
			num/=5;
		}
	}
	cout << min(NumFive,NumTwo) << endl;
}
```

4、简单来说就是找3,5,7的倍数的个数，a代表几个3,b代表几个5,c代表几个7。这题我想不出来，本来用的是暴力www。

```C++
#include<iostream>
using namespace std;
const long long num = 59084709587505;
bool is_lucky(int x,int y,int z)
{
	long long sum = 1;
	while (x--){
		sum *= 3;
		if (sum >= num) return false;
	}
	while (y--){
		sum *= 5;
		if (sum >= num) return false;
	}
	while (z--){
		sum *= 7;
		if (sum >= num) return false;
	}
	return true;
}
int main(){
	int ans=0;
	for (int a=0;a<=30;a++) for (int b=0;b<=30;b++) for (int c=0;c<=30;c++) {
		if (is_lucky(a,b,c)) ans++;
	}
	cout << ans;
	return 0;
}
```

5、递归，这个时候要开始写上面的和下面的，观察可得第1座和第3座刚好是3和9差3的倍数，这递归其实就是从中间到两边发散开来。所以这里填写size/3。

```C++
size/3
```

6、将所有的时间全部加起来，利用一些肮脏的手段把一个string化为一个数字，就可以很方便的直接相加。比如12:23:34就可以方便的化为122334这样简单的数字，这样直接相加可以分理出正确的时间数。因为要避免超过60,所以这里取60为乘。

```C++
#include <iostream>
#include <cstring>
using namespace std;
int turn_time_second(){
	char time[30]={};
	cin.getline(time,30);
	int hour1,hour2,minute1,minute2,second1,second2;
	int extend=0;
	if(strlen(time)==22) sscanf(time,"%d:%d:%d %d:%d:%d (+%d)",&hour1,&minute1,&second1,&hour2,&minute2,&second2,&extend);
	else sscanf(time,"%d:%d:%d %d:%d:%d",&hour1,&minute1,&second1,&hour2,&minute2,&second2);
	return (hour2-hour1+extend*24)*60*60+(minute2-minute1)*60+second2-second1;
}
int main(){
	int n;
	cin >> n;
	getchar();
	while(n--){
		int time1=turn_time_second();
		int time2=turn_time_second();
		int time=(time1+time2)/2;
		printf("%02d:%02d:%02d\n",time/60/60,time/60%60,time%60);
	}
}
```

8、这题就是bfs,和之前那道找岛是一样的思路，区别是岛应该是内陆区块。

9、暴力

```C++
#include <iostream>
using namespace std;
int main(){
	int n,K,ans=0;
	cin >> n >> K;
	int num[n];
	for(int i=0;i<n;i++) cin >> num[i];
	for(int a=0;a<n-2;a++) for(int b=a+1;b<n-1;b++) for(int c=b+1;c<n;c++){
		int sum=num[a]+num[b]+num[c];
		if(sum%K==0) ans=max(ans,sum);
	}
	cout << ans << endl;
	return 0;
}
```

