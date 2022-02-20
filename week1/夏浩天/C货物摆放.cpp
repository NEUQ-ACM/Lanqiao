//答案：2430
// 即 num=a*b*c，有多少种组合方案


#include <iostream>
using namespace std;
int main()
{
	long long num = 2021041820210418;
	while (num != 1)
	{
		for (int i = 2; i <= num; i++)
		{
			if (num % i == 0)  // i是num的因数
			{
				cout << i << " ";  //输出因数以便接下来的操作（反正是填空）
				num /= i;
				break;
			}
		}
	}
	return 0;
}
// 通过上面输出知因数为 2 3 3 3 17 131 2857 5882353
// 即 3^5* (3+6+1)
// 注意：如果你没有给任意位置分配数字，该位置为1 !