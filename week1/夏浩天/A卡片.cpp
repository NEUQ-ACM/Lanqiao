//0用到的地方比较少，1在其余数字前，所以只需要考虑1
//在百位不为1的情况下，100内含1数量为20=1*10+10
//在千位不为1的情况下，1000内含1数量为20*10+100=300
//2000前含1数量1600
//易知答案在3000（1900）-4000（2200）间
//2021-1900=121 121-20-100-20=-19 即3181

//以下为暴力穷举验证(真比赛肯定不会分析上面那一大堆233)
#include<iostream>
#include<string>  // to_string
using namespace std;
int main()
{
	int num = 2021;
	int i = 0;
	while (num > 0)
	{
		i++;
		string a = to_string(i);
		for (int j = 0; j < a.size(); j++)
		{
			if (a[j] == '1') num--;
			if (num <= 0) break;
		}
		
	}
	cout << i;
	return 0;
}