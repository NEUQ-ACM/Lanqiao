## A 合数个数
 &emsp;&emsp;43^2<2020<47^2；可以直接暴力除以43以内的质数来判断是不是合数。

	#include<bits/stdc++.h>
	using namespace std;
	int main(){
		int f[30],ans=0;
		f[1]=2;f[2]=3;f[3]=5;f[4]=7;f[5]=11;
		f[6]=13;f[7]=17;f[8]=19;f[9]=23;f[10]=29;
		f[11]=31;f[12]=37;f[13]=41;f[14]=43;
		for(int i=4;i<=2020;i++){
			for(int j=1;j<=14;j++){
				if(i%f[j]==0&&i!=f[j]){
					ans++;
					break;
				}
			}
		}
		cout<<ans;
		return 0;
	}

## B 含2天数
&emsp;&emsp;定义两个bool型函数，用以判断1、年份中是否有2。2、是否是闰年。根据这两个条件会有四种情况，进行判断和运算。

	#include<bits/stdc++.h>
	using namespace std;
	bool flag(int year){
		 if((year%4== 0) && ( (year%100)!=0 ) || year%400==0)	return true;
		 else	return false;
	}
	bool f(int year){
		while(year!=0){
			if(year%10==2){
				return true;
			}
			year/=10;
		}
		return false;
	}
	int main(){
		int ans=0;
		for(int i=1900;i<=9999;i++){
			if(f(i)&&flag(i))	ans=ans+366;
			else if(f(i)&&!flag(i))	ans=ans+365;
			else if(!f(1)&&flag(i))	ans=ans+180;
			else ans+=179;
		}
		cout<<ans;
		return 0;
	}

## C 本质上升序列

&emsp;&emsp;这个题跟第十二届的砝码称重问题有点像。s中存放着200个英文。f[i]是第i+1个字母与前边符合条件的字母可以组成的个数。每一个字母都是一个升序排列，所以f[i]初始值是1。要求本质不同，所以当f[i]与前边某一个字母相同时，要使f[i]=0，因为与他相同的字母必然和最前边的字母已经组过一次了。  
&emsp;&emsp;如：lanqiao  

---
字母&emsp;l&emsp;&emsp;a&emsp;&emsp;n&emsp;&emsp;q&emsp;&emsp;i&emsp;&emsp;a&emsp;&emsp;o

---
初始&emsp;1&emsp;&emsp;1&emsp;&emsp;1&emsp;&emsp;1&emsp;&emsp;1&emsp;&emsp;1&emsp;&emsp;1

---
&emsp;`l`&emsp;&emsp;1&emsp;&emsp;1&emsp;&emsp;1&emsp;&emsp;1&emsp;&emsp;1&emsp;&emsp;1&emsp;&emsp;1&emsp;&emsp;

---
&emsp;`a`&emsp;&emsp;1&emsp;&emsp;1&emsp;&emsp;1&emsp;&emsp;1&emsp;&emsp;1&emsp;&emsp;1&emsp;&emsp;1&emsp;&emsp;

---
&emsp;`n`&emsp;1&emsp;&emsp;1&emsp;&emsp;3&emsp;&emsp;1&emsp;&emsp;1&emsp;&emsp;1&emsp;&emsp;1&emsp;&emsp;

---
&emsp;`q`&emsp;1&emsp;&emsp;1&emsp;&emsp;3&emsp;&emsp;6&emsp;&emsp;1&emsp;&emsp;1&emsp;&emsp;1&emsp;&emsp;

---
&emsp;`i`&emsp;1&emsp;&emsp;1&emsp;&emsp;3&emsp;&emsp;6&emsp;&emsp;2&emsp;&emsp;1&emsp;&emsp;1&emsp;&emsp;

---
&emsp;`a`&emsp;1&emsp;&emsp;1&emsp;&emsp;3&emsp;&emsp;6&emsp;&emsp;2&emsp;&emsp;0&emsp;&emsp;1&emsp;&emsp;

---
&emsp;`o`&emsp;1&emsp;&emsp;1&emsp;&emsp;3&emsp;&emsp;6&emsp;&emsp;2&emsp;&emsp;0&emsp;&emsp;8&emsp;&emsp;

---
&emsp;&emsp;总计1+1+3+6+2+0+8=21

	#include <bits/stdc++.h>
	using namespace std;
	int main()
	{
		string s;
		int f[210],ans=0;
		s="tocyjkdzcieoiodfpbgcncsrjbhmugdnojjddhllnofawllbhfiadgdcdjstemphmnjihecoapdjjrprrqnhgccevdarufmliqijgihhfgdcmxvicfauachlifhafpdccfseflcdgjncadfclvfmadvrnaaahahndsikzssoywakgnfjjaihtniptwoulxbaeqkqhfwl";
		for(int i=0;i<200;i++){
			f[i]=1;
			for(int j=0;j<i;j++)
			{
				if(s[i]>s[j]) f[i]+=f[j];
				else if(s[i]==s[j]) f[i]=0;		
			}
			ans+=f[i];
		}
		cout<<ans;
		return 0;		
	}
