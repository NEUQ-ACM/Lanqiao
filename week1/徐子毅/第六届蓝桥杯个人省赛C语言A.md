1、莽算就行了吧。

```C++
#include <iostream>
using namespace std;
int main(){
    for(int a=-35;a<=35;a++) for(int b=a;b<=35;b++) for(int c=b;c<=35;c++){
        if(a*a+b*b+c*c==1000) cout << a << endl;
    }
}
```

得出结果-30

2、就应该手算。。。

答案是2017-08-05

3、简单的计算

```C++
#include <iostream>
#include <cstring>
using namespace std;
int nums[10];
int main(){
    for(int num=1;;num++){
        for(int i=0;i<10;i++) nums[i]=0;
        long long pf=num*num;
        long long lf=pf*num;
        string _pf=to_string(pf);
        string _lf=to_string(lf);
        string sum=_pf+_lf;
        if(sum.length()==10){
            bool is=true;
            for(int i=0;i<10;i++){
                int here=sum[i]-'0';
                if(nums[here]==1) is=false;
                else nums[here]=1;
            }
            if(is) {cout << num << endl;return 0;}
        }else continue;
    }
}
```

答案是69

4、可以看到这一行输出的就是中间内容。所以左边控制好一半的空格数就可以了

```C++
(width-strlen(buf))/2-1,buf,(width-strlen(buf))/2-1
```

5、test函数就是来检测是不是符合的，而在填空处的for循环内就可以发现其实是将所有情况给排列组合了，所以这是一个dfs式的排列组合，所以填空处只要进行回溯还原就行了。

```C++
{t = x[k];x[k]=x[i];x[i]=t;}
```

6、模拟一下，小明手上有0张牌，现在他从1号牌开始抽，抽取0~4张1号牌，再抽取0~4张2号牌，以此类推，就可以判断一共有多少种情况。

```C++
#include <iostream>
using namespace std;
int ans=0;
void take_card(int this_card,int sum_card){
    if(sum_card==13){
        ans++;
        return;
    }
    if(this_card>13||sum_card>13) return;
    for(int i=0;i<=4;i++) take_card(this_card+1,sum_card+i);
}
int main(){
    take_card(1,0);
    cout << ans << endl;
}
```

8、简单的模拟

```C++
#include <iostream>
using namespace std;
int main(){
    int origin;
    cin >> origin;
    int origin_fork=origin;
    int extend=0;
    while(origin_fork>=3){
        extend++;
        origin_fork-=2;
    }
    cout << origin+extend << endl;
}
```