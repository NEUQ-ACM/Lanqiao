#include<iostream>
#include<iomanip>
#include<algorithm>

using namespace std;

int main(){
	int N;
	cin >> N;
	int temp, min, max, sum = 0;
	cin >> temp;
	sum += temp;
	min = max = temp;
	for (size_t i = 1; i < N; i++)
	{
		cin >> temp;
		if (temp > max)max = temp;
		else if (temp < min)min = temp;
		sum += temp;
	}
	double ave = static_cast<double>(sum) / N;
	cout << max << '\n' << min << '\n' << fixed << setprecision(2) << ave;
}
