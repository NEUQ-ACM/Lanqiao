#include<iostream>
using namespace std;
int lcm(int x, int y){
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
	int lu[3000] = {0};
	for (int i = 2; i <= 2021; i++)
	{
		int M = 100000000;//警示****该值要开辟的足够大（至少大于该题答案，题主错在这里） 
		if (i - 21 > 0)//如果大于21,则从i-21开始 
		{
			for (int j = i-21; j < i; j++)
			{
				//到该点的距离为距离小于等于21的任意一点的最短距离（dp[j]) 加上任意一点
				//到该点的距离（即最小公倍数）
				//最短距离就是求出上述 距离的最小值 
				M= min(M,lcm(j,i) + lu[j]);
			}
		}
		else
		{
			//否则从1开始 
			for (int j = 1; j < i; j++)
			{
				    //同上 
					M = min(M,lcm(j,i) + lu[j]);
			}
		}
		//该点的最短距离为求得的最小值 
		lu[i] = M;
	}
	cout << lu[2021];
	return 0;
}
