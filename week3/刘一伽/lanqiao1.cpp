#include<iostream>
using namespace std;
int calu(int num)
{
	int ans = 0;
	while(num)
	{
		if(num%10==2)
			ans++;
		num/=10;
	}
	return ans;
}
int main()
{
	int cnt = 0;
	for(int i = 1; i <=2020; i++)
	{
		cnt+=calu(i);
	}
	cout << cnt <<endl;
	return 0;
} 

