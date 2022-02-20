#include<vector>
#include<iostream>
#include<cmath>
using namespace std;

int main() {
	long long n = 2021041820210418;
	vector<long long>fact;
	int i;
	for (i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)fact.emplace_back(i);
	}
	if (sqrt(n) == fact.back()) { i = fact.size() - 2; }
	else i = fact.size() - 1;
	for (; i >= 0; i--) {
		fact.emplace_back(n / fact[i]);
	}
	int sum = 0;
	int cnt = fact.size();
	for (size_t i = 0; i < cnt; i++)
	{
		for (size_t j = 0; j < cnt; j++)
		{
			for (size_t m = 0; m < cnt; m++)
			{
				if (fact[i] * fact[j] * fact[m] == n)++sum;
			}
		}
	}
	cout << sum;
}