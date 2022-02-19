## **A：卡片**
&emsp;&emsp;因为该题是填空题，所以可以直接暴力求解。  
&emsp;&emsp;首先创建一个数组，并将数组初始化为0；然后从1开始遍历，将每一个数字需要用的次数在数组中记录下来。当该数字的使用次数到2022时退出循环；最后输出倒数第二个数字。

	#include<bits/stdc++.h>
	using namespace std;
	int main(){
		int i,f[20],m,n,flag;
		f[0]=f[1]=f[2]=f[3]=f[4]=f[5]=f[6]=f[7]=f[8]=f[9]=0;
		i=1;
		flag=0;
		while(1){
			n=i;
			while(n>0){
				m=n%10;
				f[m]+=1;
				if(f[m]==2022){
					flag=1;
					break;
				}
				n=n/10;
			}
			if(flag==1){
				cout<<i-1;
				break;
			}
    	i=i+1;
		}
		return 0;
	}

## **B:直线**
&emsp;&emsp;将420个点的坐标存入结构体中，接着求出这420个点组成不同直线的k和b，最后通过判断k和b是否想等得到直线的数量。  
&emsp;&emsp;首先将每个点的坐标存入p，一共有s1个点

	for(double i=0.0;i<20.0;i++){ 
		for(int j=0.0;j<21.0;j++){
			s1++;
			p[s1].x=i;
			p[s1].y=j;
		}
	}  
然后s1个点得到s2条线

	for(int x1=1;x1<=s1;x1++){
		for(int x2=x1+1;x2<=s1;x2++){
			if(p[x1].x!=p[x2].x&&p[x1].y!=p[x2].y){
				s2++;
				sp[s2].k=(p[x1].y-p[x2].y)/(p[x1].x-p[x2].x);
				sp[s2].b=p[x1].y-sp[s2].k*p[x1].x;
			}
		}
	}
最后根据k的大小排序，循环判断时可以大大降低时间复杂度。

	sort(sp+1,sp+s2+1,cmp);
	for(int x1=1;x1<s2;x1++){
		if(sp[x1].k!=sp[x1+1].k||sp[x1].b!=sp[x1+1].b)	s3++;
	}
## **C：货物摆放**
&emsp;&emsp;该题实质就是将正方体堆在一起后的长宽高相乘等于n，且长宽高的数字必须是n的约数。为了减少运行时间，for循环至sqrt（n);接着套三层循环得到结果。

	#include<bits/stdc++.h>
	using namespace std;
	int main(){
		long long f[100001],n,sum=0;
		int m=0;
		n=2021041820210418;
		for(int i=1;i<=sqrt(n);i++){
			if(n%i==0){
				m++;
				f[m]=i;
				if(i!=n/2){
					m++;
					f[m]=n/i;
				}
			}
		}
		sort(f+1,f+m+1);
		for(int i=1;i<=m;i++){
			for(int j=i;j<=m;j++){
				for(int k=j;k<=m;k++){
					if(f[i]*f[j]*f[k]==n){
						if(f[i]==f[j]&&f[j]==f[k])	sum+=1;
						else if(f[i]==f[j]||f[j]==f[k]||f[i]==f[k])	sum+=3;
						else	sum+=6;
					}
					else if(f[i]*f[j]*f[k]>n)	break;
				}
			}
		}
		cout<<sum;
	return 0;
	}

## **D:路径**
&emsp;&emsp;这个题首先在求最小公倍数时就尽量不要暴力，因为最后的数很大，跑的非常慢。*(我暴力时什么都跑不出来，太慢了？还是我的代码有问题，不知道）*用两数之积除以最大公约数。  
&emsp;&emsp;然后求从1到每一个数的最短路径。如1到x（x-1>21),这时需要一个中间值i，x-i<21，用1到i的最小值加上i到x的最小值之和，M，当M最小时，1到x的最小路径就是M。（i的值需要从x-21到x遍历）。*1到i的最小路径也是根据此循环得到。*

	#include<bits/stdc++.h>
	using namespace std;
	int lmin(int x, int y){
		int a,b;
	 	a=x;
	 	b=y;
	 	int z = y;
		while(x%y!=0){
			z = x%y;
			x = y;
			y = z;	
		}
	 	return a*b/z;
	 }
	int main(){
		int lu[3000]={0};
		for(int i=2;i<=2021;i++){
			int M=100000000;
			if(i>21){
				for(int j=i-21;j<i;j++){
					M=min(M,lmin(j,i)+lu[j]);
				}
			}
			else{
				for(int j=1;j<i;j++){
					M=min(M,lmin(j,i)+lu[j]);
				}
			}
			lu[i]=M;
		}
		cout<<lu[2021];
		return 0;
	}
## **F:砝码称重**  
---
f[i][a[j]]  &emsp; 1&emsp;  2 &emsp; 3 &emsp; 4&emsp;  5 &emsp; 6&emsp;  7&emsp;  8 &emsp; .... &emsp; sum

---
 &emsp;1   &emsp;&emsp;  ^

---
 &emsp;2&emsp;&emsp; ^&emsp;&emsp;^&emsp;&emsp;^

---
&emsp;3&emsp;&emsp;^&emsp;&emsp;^&emsp;&emsp;^&emsp;&emsp;^&emsp;&emsp;^&emsp;&emsp;^

---

&emsp;&emsp;（认为第i个砝码就是状态i）如果状态i-1时j重量存在，则f[i][j]=1,否则为0。且让重量j加减a[i]的重量，得到状态i.最后统计状态n时的1的个数，即为结果。

	#include<bits/stdc++.h>
	using namespace std;
	int n,f[101][100001],a[101],sum=0;
	int main(){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		memset(f,0,sizeof(f));
		f[1][a[1]]=1;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=sum;j++){
				if(f[i-1][j]==1){
					f[i][j]=1;
					f[i][a[i]]=1;
					f[i][a[i]+j]=1;
					f[i][abs(a[i]-j)]=1;
				}
			}
		}
		int flag=0;
		for(int i=1;i<=sum;i++){
			if(f[n][i]==1)	flag=flag+1;
		}
		cout<<flag;
		return 0; 
	}

