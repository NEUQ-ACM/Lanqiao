1、每一层的数量可以用公式得出，再把第一层到第100层叠加即可。

```C++
#include <iostream>
using namespace std;
int main(){
    int ans=0;
    for(int i=1;i<=100;i++){
        ans+=(1+i)*i/2;
    }
    cout << ans << endl;
}
```

得出是171700

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

3、next_permutation暴力捏

```C++
#include <iostream>
#include <algorithm>
using namespace std;
double num[9]={1,2,3,4,5,6,7,8,9};
int main(){
    int ans=0;
    while(next_permutation(num,num+9)){
        if(num[0]+num[1]/num[2]+(num[3]*100+num[4]*10+num[5])/(num[6]*100+num[7]*10+num[8])==10) ans++;
    }
    cout << ans << endl;
}
```

得出29

4、快速排序，这里是要把基准调换。

```C++
swap(a,p,j);
```

5、发现这道题是递归，这一步就是要更改剩余人数和所选国家即可。

```C++
f(a,k+1,M-j,b);
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

9、插入排序

```C++
#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int count=0;
	for(int i=0;i<n;i++){
		int min=i;
		for(int j=i+1;j<n;j++) if(a[min]>a[j]) min=j;
		if(min!=i){
            swap(a[min],a[i]);
			count++;
		}
	}
	cout<<count<<endl;
	return 0;
}
```

