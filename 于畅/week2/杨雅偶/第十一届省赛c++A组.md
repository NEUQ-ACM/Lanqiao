# A 门牌制作

&emsp;&emsp;这个题的数据不大，可以直接从1到2020遍历一遍，得到2的个数。

	#include<bits/stdc++.h>
	using namespace std;
	int main(){
		int a,b=0;
		for(int i=1;i<=2020;i++){
			a=i;
			while(a!=0){
				if(a%10==2)	b++;
				a=a/10;
			}
		}
		cout<<b;
		return 0;
	} 

#B 既约分数

&emsp;&emsp;首先要明确分子分母的位置可以互换，所以为了减少时间复杂度，先确定一个算出后在乘以2。最后不要忘记加上1/1的情况。

	#include<bits/stdc++.h>
	using namespace std;
	int gcd(int x,int y){
		int z;
		z=x%y;
	 	while(z!=0) 
	 	{
	  		x = y;  
	  		y = z;  
	  		z =x%y; 
	 	}
		return y;
	}
	int main(){
		int a=0;
		for(int i=1;i<2020;i++){
			for(int j=i+1;j<=2020;j++){
				if(gcd(i,j)==1)	a++;
			}
		}
		cout<<a*2+1;
		return 0;
	}	

#C 蛇形填数

&emsp;&emsp;这是一个填空题，他要的是20*20的数据，所以可以直接找对角线的规律，不难发现第n个数比n-1多了4（n-1）。

	#include<bits/stdc++.h>
	using namespace std;
	int main(){
		int sum=1;
		for(int i=1;i<20;i++){
			sum+=4*i;
		}
		cout<<sum;
		return 0;
	} 

#D 七段码

&emsp;&emsp;这个题的数据非常小，所以我直接数出来了....

	#include<bits/stdc++.h>
	using namespace std;
	int main(){
		int a;
		a=7+(6+4)+(6+10)+(6+14)+(6+13)+7+1;
		cout<<a;
		return 0;
	} 

# E 平面分割

&emsp;&emsp;圆分割平面是f(n)=n^2-n+2;增加第i条直线，会增加2m+i，所以f(m)=n^2-n+2+2mn+(1+2+...+m)=n^2-n+2+2mn+n(n+1)/2+1;所以直接套公式后输出。

	#include<bits/stdc++.h>
	using namespace std;
	int main(){
		cout<<400-20+800+1+210;
		return 0;
	}




# F成绩分析

&emsp;&emsp;这个题目十分简单，输入的时候直接求和，sort排序，然后输出最大和最小。

	#include<bits/stdc++.h>
	using namespace std;
	int main(){
		int sum=0,f[10001],n;
		double ave;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>f[i];
			sum+=f[i];
		}
		sort(f+1,f+n+1);
		ave=sum*1.0/n;
		cout<<f[n]<<endl;
		cout<<f[1]<<endl;
		printf("%.2f",ave);
		return 0;
	}

#H 子串分值

&emsp;&emsp;从第一个字符开始往后遍历(j),再从j+1到最后一个，以sum1=1开始，计算每一个j开始有多少，最后相加。

	#include<bits/stdc++.h>
	using namespace std;
	int main(){
		string st;
		cin>>st;
		int i,sum,sum1;
		i=st.length();
		sum=i;
		for(int j=0;j<i-1;j++){
			string st1,st2;
			sum1=1;
			for(int k=j+1;k<i;k++){
				int s=0;
				for(int m=j;m<k;m++){
					if(st[m]==st[k])	s++;
					if(s==2)	break;
				}
				if(s==0)	sum1=sum1+1;
				else if(s==1)	sum1=sum1-1;
				sum=sum+sum1;
			}
		}
		cout<<sum;
		return 0;
	}
