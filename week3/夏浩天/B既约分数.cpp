//答案：2481215
#include<iostream>
#include<string>//to_string
using namespace std;
int check(int a, int b)//辗转相除法
{
	while (b)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int start = 0;
	for (int i = 1; i <= 2020; i++)
		for (int j = 1; j <= 2020; j++)
			if (check(i, j)==1)start++;
	printf("%d", start);
	return 0;
}