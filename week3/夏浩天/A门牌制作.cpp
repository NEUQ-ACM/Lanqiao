//答案：624
#include<iostream>
#include<string>//to_string
using namespace std;
int en = 0;
int main()
{
	for (int i = 1; i <= 2020; i++)
	{
		string str = to_string(i);
		for (int j = 0; j < str.size(); j++)
			if (str[j] == '2')en++;
	}
	printf("%d", en);
	return 0;
}