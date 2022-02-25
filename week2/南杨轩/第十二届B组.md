# 第十二届蓝桥杯B组

## A.空间

##### 1.解题思路：

​	由于
$$
1MB=(2^5)^2kb=(2^5)^4 b
$$
而8位为一个字节，32位有4个字节。

##### 2. C++代码如下：

```c++
#include<iostream>
using namespace std;
int main()
{
	int n=0;
	cin>>n;
	int x=n*(1<<20)/4;
	cout<<x<<endl;
	return 0;
 } 
```

##### 3.结果如下：

​	![image-20220215102726919](C:\Users\xuan\AppData\Roaming\Typora\typora-user-images\image-20220215102726919.png)



##   B.卡片



##### 1.解题思路：

​	只需从1开始，将每个数的每个位上的数遍历一遍。

##### 2. C++代码如下：

```c++
#include<iostream>
using namespace std;
int main()
{
	int n=0;
	int num[10];
	cin>>n;
	for(int i=0;i<10;i++)
		num[i]=n;
	for(int j=1;;j++)
		{
			int x=j;
			while(x)
				{
					int m=x%10;
					num[m]--;
					if(num[m]<0) 
					{
						cout<<j-1<<endl;
						break;
					}
					x/=10;
				}
			if(x!=0) break;
		}
	return 0;	
}
```

##### 3.结果如下：

​	![image-20220215103830903](C:\Users\xuan\AppData\Roaming\Typora\typora-user-images\image-20220215103830903.png)



## C.直线

##### 1.解题思路：

​		根据公式：
$$
y-y1=(y1-y2)/(x1-x2)*(x-x1) 即，(x2-x1)y-(y2-y1)x=x2y1-x1y2.
$$
判断直线是否相同。

##### 2. C++代码如下：

```c++
#include<iostream>
using namespace std;
struct Point 
{
	int x;
	int y;	
}; 
struct Proportion//记录比例 
{
	int a;
	int b;
	int c;
bool operator!=(int a)
{
	if(this->a==a&&b==a&&c==a) return false;
	else return true;
}
bool operator==(Proportion &p)
	{
		if((a==0&&p.a!=0)||(b==0&&p.b!=0)||(c==0&&p.c!=0)) return false;
		else if((a!=0&&p.a==0)||(b!=0&&p.b==0)||(c!=0&&p.c==0)) return false;
		else 	
		{
			if(a==0&&b==0&&c==0) return true;
			else if((a==0&&b==0&&c!=0)||(a!=0&&b==0&&c==0)||(a==0&&b!=0&&c==0)) 
				 return true;
			else if(a==0&&b!=0&&c!=0) 
				{
					double z=b*1.0/c;
					double zz=p.b*1.0/p.c;
					if(z==zz) return true;
					else return false;
				}
			else if(a!=0&&b==0&&c!=0) 
				{
					double z=a*1.0/c;
					double zz=p.a*1.0/p.c;
					if(z==zz) return true;
					else return false;
				}
			else if(a!=0&&b!=0&&c==0) 
				{
					double z=a*1.0/b;
					double zz=p.a*1.0/p.b;
					if(z==zz) return true;
					else return false;
				}
			else if(a!=0&&b!=0&&c!=0) 
				{
					double z=a*1.0/b;
					double zz=p.a*1.0/p.b;
					double zzz=a*1.0/c;
					double zzzz=p.a*1.0/p.c;
					double xxx=b*1.0/c;
					double xxxx=p.b*1.0/p.c;
					if((z==zz)&&(xxx==xxxx)&&(zzz==zzzz)) return true;
					else return false;
				}
		}
	}
};
int main()
{
	Point p[10000];
	int a=0,b=0;
	cout<<"请输入几行,几列："<<endl;
	cin>>a>>b;
	int n=a*b;//n个点 
	int j=0,k=0;	
	for(int i=0;i<n;i++)
		{
			p[i].x=k;
			p[i].y=j;
			if(k==a-1) 
				{
					k=0;
					j++;
				}
			else k++;
		 }
	int o=a*b*(a*b-1)/2;  
	Proportion pp[o];
	int m=0;	 
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			{
				pp[m].a=p[j].x-p[i].x;
				pp[m].b=p[j].y-p[i].y;
				pp[m].c=p[j].x*p[i].y-p[i].x*p[j].y;
				m++;
			}
	int x=0;//记录直线条数
	for(int i=0;i<m;i++)
		{
			for(int j=i+1;j<m;j++)
				if(pp[i]==pp[j]) 
				{
					pp[j].a=0;
					pp[j].b=0;
					pp[j].c=0;
				}
		}
	for(int i=0;i<m;i++)
		{
			if(pp[i]!=0) x++;
		}
	cout<<"直线条数："<<x<<endl;
	return 0;	
}
```



##### 3.结果如下：

![image-20220215103949794](C:\Users\xuan\AppData\Roaming\Typora\typora-user-images\image-20220215103949794.png)（缺点是算法比较垃圾，费时三十多s)





## D.货物摆放

##### 1.解题思路：

​	思路借鉴于别人，采用质数分解，然后再将质数分配给3个（a,b,c）。以此计算。

##### 2. C++代码如下：

​	这个是自己写的（比较废物，花了一个下午）

```c++
#include<iostream>
#define ll long long
#define o 1000 
#include<cmath>
using namespace std;
struct Math
{
	ll ans;
	ll an;
};
bool judge(ll n)//判断是否为素数 
{
	for(ll i=2;i<=sqrt(n);i++)
		{
			if(n%i==0) return false;
		} 
	return true;
}
ll judge(Math *qa,int n,int j)
{
	for(ll i=1;i<j;i++)
		if(qa[i].an==n) return i;
	return 0;
}
int jisuan(int n)//将n个相同的数 分配给3个不同的人 --> n个东西，分三次取完 
{
	int x=0;
	for(int i=0;i<=n;i++) //第一次取
		for(int j=0;j<=n-i;j++)
			{
				if(n-i-j>=0) x++;
			}
	return x; 
}
int main()
{
	ll n=0;
	cin>>n;
	ll m=n;
	Math qa[o];
	ll i=2;
	int j=1;
	while(i<=m)
	{
		while(!judge(i))
			{
				i++;	
			}
		if(m%i==0)
			{
				ll mm=judge(qa,i,j);
				if(mm)
					{
						qa[mm].ans++;
					}
				else
					{
						qa[j].an=i;
						qa[j].ans++;
						j++;
					}
				m=m/i;
			}
		else i++;
	}
	cout<<n<<"=";
	for(int x=1;x<j;x++)
		{
			cout<<"("<<qa[x].an<<"^"<<qa[x].ans<<")";
			if(x!=j-1) cout<<"*";
		}cout<<endl;
	int nn=0;
	int mm=0;
	for(int x=1;x<j;x++)
		{
			if(qa[x].ans==1) nn++;
			else
				{
					mm+=jisuan(qa[x].ans);
				}
		}
	if(nn!=0)
		{
			if(mm!=0)
				mm=mm*pow(3,nn);
			else mm=pow(3,nn);			
		}
	cout<<"数为："<<mm;
	return 0;
}
```



##### 3.结果如下：

![image-20220214180531962](C:\Users\xuan\AppData\Roaming\Typora\typora-user-images\image-20220214180531962.png)



## E.路径

##### 1.解题思路：

​	先将点与点之间的距离赋上 0x3f(无穷)，再计算各点到其他点的距离，再通过 floyd 算法，重新计算。

##### 2. C++代码如下：

```c++
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int qiu(int x, int y)//求最小公倍数 
{
	int a = x, b = y;
	while (a % b != 0)
	{
		int c = a % b;
		a = b;
		b = c;
	}
	return x * y / b;
}
int num1[2025][2025];
int main()
{
	memset(num1,0x3f,sizeof(num1));	
	for (int i = 1; i <= 2021; i++)
	{
		for (int j = i; j <= 2021; j++)
		{
			if (i == j) num1[i][j] = 0;
			else if ( j - i <= 21) 
				{
					num1[i][j] = qiu(j,i);
					num1[j][i]=num1[i][j];
				}
		}
	}
	cout<<num1[1][2021]<<endl;
	for (int k = 1; k <= 2021; k++)
		for (int i = 1; i <= 2021; i++)
			for (int j = 1; j <= 2021; j++)
					num1[i][j] = min(num1[i][k] + num1[k][j],num1[i][j]);
	cout<<num1[1][2021]<<endl;	
	return 0;
}
```

##### 3.结果如下：

![image-20220217135025762](C:\Users\xuan\AppData\Roaming\Typora\typora-user-images\image-20220217135025762.png)



## F.时间显示

##### 1.解题思路：

利用取余运算，与60取余。

##### 2. C++代码如下：

```c++
#include<iostream>
#define ll long long//46800999
using namespace std;//
int main()
{
	ll n;
	cin>>n;
	ll day=24*60*60*1000;
	n=n%day;
	n/=1000;
	int a=n%60;//秒 
	n/=60;
	int b=n%60;//分 
	n/=60;//时
	if(n>=10) cout<<n<<":";
	else cout<<"0"<<n<<":";
	
	if(b>=10) cout<<b<<":";
	else cout<<"0"<<b<<":";
	
	if(a>=10) cout<<a<<endl;
	else cout<<"0"<<a<<endl;	  
	return 0;
} 
```

##### 3.结果如下：

###### 1.测试数据1![image-20220217142201263](C:\Users\xuan\AppData\Roaming\Typora\typora-user-images\image-20220217142201263.png)

###### 2.测试数据2

![image-20220217142309803](C:\Users\xuan\AppData\Roaming\Typora\typora-user-images\image-20220217142309803.png)



## G.砝码称重

##### 1.解题思路：

$$
a[i][j]表示前 i 个数字选择若干个加或者减，能否获得和为 j 。
$$

若成功，则为1；若不成，则为0.

##### 2. C++代码如下：

```c++
//化繁为简 
#include<bits/stdc++.h> 
using namespace std;
int a[101][100001];//防止越界 
int main()
{
	int n=0,sum=0;
	int num[101];
	num[0]=0; 
	memset(a,0,sizeof(a));//全部赋值为0 
	cin>>n;
	for(int i=1;i<=n;i++)//输入砝码数 
		{
			cin>>num[i];
			sum+=num[i];
		}
	for(int i=1;i<=n;i++) //n个砝码 
		for(int j=1;j<=sum;j++)
			{
				a[i][j]=a[i-1][j];//前 i-1个能合成 j,那么前 i个也一定能合成 j 
				if(a[i][j]==0) //例外的情况
					{
						//当 j大于第 i个砝码质量时： 
			if(j>num[i]) a[i][j]=a[i-1][j-num[i]]; //若去掉第 i 个砝码之后，剩余砝码能合成 j-num[i]，则，不去掉一样能
						//当j=num[i]时，一定能合成 
			else if(j==num[i])	a[i][j]=1;
						//当 j小于第 i个砝码质量时：
			else if(j<num[i])	a[i][j]=a[i-1][num[i]-j];//考虑砝码放两边 
					}	
			} 
	int x=0;//统计个数 	
	for(int i=1;i<=sum;i++)
		if(a[n][i])  x++;
	cout<<x;
	return 0;
}
```

##### 3.结果如下：

![image-20220217174533699](C:\Users\xuan\AppData\Roaming\Typora\typora-user-images\image-20220217174533699.png)





## H.杨辉三角

##### 1.解题思路：

​	利用杨辉三角特性，遍历一遍。

##### 2. C++代码如下：

```c++
#include<bits/stdc++.h>
using namespace std;
int C(int a,int b)
{
	if(b==1) return a;
	int x=1,y=1;
	for(int i=1;i<=b;i++)
		{
			y*=i;
			x*=a;
			a--;
		}
	return x/y;
}
int main()
{
	int n=0;
	cin>>n;
	if(n==1) cout<<"1";
	else 
		{
			int x=3;
			int i=2;
			while(true)
			{
				x++;
				int a; 
				for(int j=1;j<=(i/2);j++)
					{
						a=C(i,j);
						if(n==a) 
							{
								x++;
								break;
							}
						else x++;						
					} 
				if(n==a) break;
				else x+=(i+1)/2;	
				i++;
			}
	cout<<x;			
		}
	return 0;
 } 
```

##### 3.结果如下：

![image-20220218200829277](C:\Users\xuan\AppData\Roaming\Typora\typora-user-images\image-20220218200829277.png)

![img](https://bkimg.cdn.bcebos.com/pic/b7003af33a87e9502845f2701d385343fbf2b45f?x-bce-process=image/watermark,image_d2F0ZXIvYmFpa2U4MA==,g_7,xp_5,yp_5/format,f_auto)

792就在杨辉三角84的位置上，结果正确。



## I.双向排序

##### 1.解题思路：

逐步进行，采用快速排序法。

##### 2. C++代码如下：

```c++
#include<iostream>
using namespace std;
void Quick_sort1(int *a,int start,int end)//降序排 
{
	if(start>end) return ;
	int i=start;
	int j=end;
	int key=a[i];
	while(i<j)
		{
			while(i<j&&a[j]<=key)
				j--;
			a[i]=a[j];
			while(i<j&&a[i]>=key)
				i++;
			a[j]=a[i];		
		}
	a[i]=key;
	Quick_sort1(a,start,i-1);
	Quick_sort1(a,i+1,end);
}
void Quick_sort2(int *a,int start,int end)//升序排 
{
	if(start>end) return ;
	int i=start;
	int j=end;
	int key=a[i];
	while(i<j)
		{
			while(i<j&&a[j]>=key)
				j--;
			a[i]=a[j];
			while(i<j&&a[i]<=key)
				i++;
			a[j]=a[i];		
		}
	a[i]=key;
	Quick_sort2(a,start,i-1);
	Quick_sort2(a,i+1,end);
}
int main()
{
	int n=0,m=0;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++)
		a[i]=i;
	for(int i=1;i<=m;i++)
		{
			int x,y;
			cin>>x>>y;
			if(x==0) //降序排 
				Quick_sort1(a,1,y);
			else if(x==1) 
				Quick_sort2(a,y,n);
		}
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
}
```

##### 3.结果如下：

![image-20220218203057182](C:\Users\xuan\AppData\Roaming\Typora\typora-user-images\image-20220218203057182.png)
