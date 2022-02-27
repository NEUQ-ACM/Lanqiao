#include<iostream>
using namespace std;

int main() {
	int num = 1, dif = 4;
	for (size_t i = 0; i < 19; i++)
	{
		num += dif;
		dif += 4;
	}
	cout << num;
}