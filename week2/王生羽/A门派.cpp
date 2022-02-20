#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i = 1,  res, sum = 0;
	while(i <= 2020) 
	{
		int y = i;
		while(y)
		{
			res = y % 10;
			if(res == 2)  sum++;
			y /= 10;
		}
		i++;
	}
	cout<<sum;
    return 0;
}

