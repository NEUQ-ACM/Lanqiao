# 第六届蓝桥杯省赛大学a组

1.

-30

完全不用写程序。。

数学方法直接猜；

2.

2017-08-05

EZ

```c++
#include <iostream>
#include <iomanip>
using namespace std;
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	int y,m,d,t;
	cin>>y>>m>>d>>t;
	for(int i=0;i<t;i++)
	{
		d++;
		if(y%4==0&&y%100!=0||y%400==0)
		{
			month[2]=29;
		}
		else
		{
			month[2]=28;
		}
		if(d>month[m])
		{
			m++;
			d=1;
		}
		if(m>12)
		{
			y++;
			m=1;
		}
	}
	cout<<setfill('0')<<setw(4)<<y<<" "<<setw(2)<<setfill('0')<<m<<" "<<setw(2)<<setfill('0')<<d;
}
```

3.

69

暴力搜索。。

4.

(width-strlen(buf))/2-1,"",buf,(width-strlen(buf))/2-1,""

看懂题目就行

5.

{t =x[k];x[k]=x[i];x[i]=t;}

回溯。。

6.

3598180

```c++
#include <iostream>
using namespace std;
int ans;
void poker(int a,int sum）
{
	if (sum==13)
	{
		ans++;
		return;
	}
	if (a==14||sum>13) 
        return;
	for (int i=0;i<=4;i++) 
        poker(a+1,sum+i);
}

int main()
{
	poker(1, 0);
	cout<<ans;
	return 0;
}

```



递归

7。

```c++
#include <iostream>
using namespace std;
int ans;
string s_black;
string Find[5005];
int len;
void chuan(int a,int b,int c,string s)
{
	if (a==0&&b==0&&c==0)
	{
		bool same=0;
	int i;
	string old_s=s;
	for (i=0;i<12;i++)
	{
		if(same) 
         	break;
		string new_s;
		for(int j=1;j<12;j++) 
            new_s+=old_s[j];
		new_s+=old_s[0];
		for(int j=0;j<len;j++)
		{
			if(Find[j]==new_s)
			{
				same=1;
				break;
			}
			if (Find[j]=="")
                break;
		}
		old_s=new_s;
	}
	if(i==12)
	{
		Find[len++]=s;
		ans++;
	}
		return;
	}
	if (a<0||b<0||c<0) 
        return;
	chuan(a-1,b,c,s+'a');
	chuan(a,b-1,c,s+'b');
	chuan(a,b,c-1,s+'c');
}

int main()
{
	chuan(3,4,5,s_black);
	cout<<(ans+30)/2;
	return 0;
}
```

就是dfs，然后加一个判断条件

1170