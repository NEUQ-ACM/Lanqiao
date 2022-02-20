#include<bits/stdc++.h>
using namespace std;
int main() {
	int c1, c2, r1, r2;
	int i, j;
	cin >> r1 >> c1;
	int array1[r1][c1];
	for (i = 0; i < r1; i++) {
		for ( j = 0; j < c1; j++) {
			cin >> array1[i][j];
		}
	}
	cin >> r2 >> c2;
	int array2[r2][c2];
	for (i = 0; i < r2; i++) {
		for ( j = 0; j < c2; j++) {
			cin >> array2[i][j];
		}
	}
	if (c1 == r2) 
	{
		cout << r1 << " " << c2 << endl;
		for (i = 0; i < r1; i++) 
		{
			for (j = 0; j < c2; j++)
			{
				int sum = 0;
				for (int k = 0; k < c1; k++) 
				{
					sum = sum + array1[i][k] * array2[k][j];
				}
				cout << sum;
				if (j != c2 - 1) 
				{
					cout << " ";
				}
				cout << endl;
			} 
		}
	}
	else cout << "Error: " << c2 << " != " << r2;
	return 0;
}
