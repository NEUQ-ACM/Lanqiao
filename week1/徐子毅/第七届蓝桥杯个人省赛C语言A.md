1、强算

```C++
#include <iostream>
using namespace std;
int main(){
    int ans=0;
    for(int age=27;age<100;age++){
        int reage=age/10+age%10*10;
        if(age-reage==27) ans++;
    }
    cout << ans << endl;
}
```

得出结果是7

2、因为是一个连续的数列，所以这个用等差数列公式算就可以了。

```C++
#include <iostream>
using namespace std;
int main(){
    for(int age=1;age<100;age++){
        for(int n=1;n<100;n++){
            if((age+age+n)*(n+1)/2==236) cout << age << " " << n << endl;
        }
    }
}
```

Age的值为26

3、暴力捏，可以用C++库里的next_permutaion全排列。

答案是1580。

4、快速排序，这里是要把基准调换。

```C++
swap(a,p,j);
```

5、将最右边的1全部消掉，就是对该数+1后取并。

```C++
x&(x+1)
```

6、这个偷懒用一下next_permutation就可以破，缺点是要消耗宝贵的几分钟

```C++
#include <iostream>
#include <algorithm>
using namespace std;
int num[13]={1,2,3,4,5,6,7,8,9,10,11,12,13};
int main(){
    int ans=0;
    while(next_permutation(num,num+13)){
        if(num[0]+num[1]==num[2]&&num[3]-num[4]==num[5]&&num[6]*num[7]==num[8]&&(double)num[9]/(double)num[10]==(double)num[11]){
            ans++;
        }
    }
    cout << ans << endl;
}
```

得出结果是64

8、朴素可解。

```C++
#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int num;
	cin >> num;
	for(int a=0;a*a<=num;a++) for(int b=a;a*a+b*b<=num;b++) for(int c=b;a*a+b*b+c*c<=num;c++) for(int d=c;a*a+b*b+c*c+d*d<=num;d++){
		if(a*a+b*b+c*c+d*d==num){
			cout << a << " " << b << " " << c << " " << d << endl;
			return 0;
		}
	}
}
```

9、一道DP

这道题就是要求最长的回文串，这个时候有两种情况就是要看当前串和把左右相等字符并在一起的串，那个串的回文更长一点。而且这道题应该从长度出发循环。我一开始是直接起始循环发现行不通。

```C++
#include <iostream>
#include <cstring>
using namespace std;
int main(){
    string s;
    cin >> s;
    int dp[1005][1005]={0};//记录从start到end的最长回文串
    for(int length=1;length<=s.size();length++){
        for(int start=0;start<=s.size()-length+1;start++){
            int end=start+length-1;
            if(length==1) dp[start][end]=1;
            else{
                dp[start][end]=max(dp[start+1][end],dp[start][end-1]);
                if(s[start]==s[end]){
                    dp[start][end]=max(dp[start][end],dp[start+1][end-1]+2);
                }
            }
        }
    }
    cout << s.size()-dp[0][s.size()-1] << endl;
}
```

