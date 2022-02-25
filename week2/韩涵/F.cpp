#include<iostream>
#include <iomanip>
#include<algorithm>
using namespace std;


int grade[100001];

int main() {
	double sum = 0;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> grade[i];
		sum += grade[i];
	}
	sort(grade, grade + n);
	double ans = sum / n;
	cout.setf(ios::fixed);
	cout << grade[n - 1] << endl << grade[0] << endl;
	cout << setprecision(2) << ans << endl;
}