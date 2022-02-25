#include<iostream>
using namespace std;

int main() {
	long int power(int, int);
	int p, p1, m, n, i, a, b, x = 0, y = 0;
	cin >> p;
	p1 = p;
	for (i = 1;; i++) {
		if ((m = power(4, i)) <= p && p < power(4, i + 1)) {
			n = i;
			break;
		}
	}
	n = i;
	while (n > 0) {
		if (n != 1) {
			a = p / m;
			b = p % m;;
			p = b;
			if (b != 0)
				a += 1;
			else
				b = 4;
			switch (a) {
			case 1:	x += 0; y += 0;			 			break;
			case 2:	x += 0; y += power(2, n) - 1;			break;
			case 3:	x += power(2, n) - 1; y += power(2, n) - 1; break;
			case 4:	x += power(2, n) - 10; y += 0;			break;
			}
			n--;
			m = power(4, n);
		}
		if (n != 1)
			continue;
		else {
			a = p / m;
			b = p % m;
			if (b != 0)
				a += 1;
			else
				b = 4;
			switch (a) {
			case 1:switch (b) {
			case 1:if (x == 0) { x += 0; }
				  else { x += 1; }
				  if (y == 0) { y += 0; }
				  else { y += 1; }break;
			case 2:if (x == 0) { x += 1; }
				  else { x += 2; }
				  if (y == 0) { y += 0; }
				  else { y += 1; }break;
			case 3:if (x == 0) { x += 1; }
				  else { x += 2; }
				  if (y == 0) { y += 1; }
				  else { y += 2; }break;
			case 4:if (x == 0) { x += 0; }
				  else { x += 1; }
				  if (y == 0) { y += 1; }
				  else { y += 2; }break;
			}; break;
			case 2:switch (b) {
			case 1:if (x == 0) { x += 0; }
				  else { x += 1; }
				  if (y == 0) { y += 2; }
				  else { y += 3; }break;
			case 2:if (x == 0) { x += 0; }
				  else { x += 1; }
				  if (y == 0) { y += 3; }
				  else { y += 4; }break;
			case 3:if (x == 0) { x += 1; }
				  else { x += 2; }
				  if (y == 0) { y += 3; }
				  else { y += 4; }break;
			case 4:if (x == 0) { x += 1; }
				  else { x += 2; }
				  if (y == 0) { y += 2; }
				  else { y += 3; }break;
			}; break;
			case 3:switch (b) {
			case 1:if (x == 0) { x += 2; }
				  else { x += 3; }
				  if (y == 0) { y += 2; }
				  else { y += 3; }break;
			case 2:if (x == 0) { x += 2; }
				  else { x += 3; }
				  if (y == 0) { y += 3; }
				  else { y += 4; }break;
			case 3:if (x == 0) { x += 3; }
				  else { x += 4; }
				  if (y == 0) { y += 3; }
				  else { y += 4; }break;
			case 4:if (x == 0) { x += 3; }
				  else { x += 4; }
				  if (y == 0) { y += 2; }
				  else { y += 3; }break;
			}; break;
			case 4:switch (b) {
			case 1:if (x == 0) { x += 3; }
				  else { x += 4; }
				  if (y == 0) { y += 1; }
				  else { y += 2; }break;
			case 2:if (x == 0) { x += 2; }
				  else { x += 3; }
				  if (y == 0) { y += 1; }
				  else { y += 2; }break;
			case 3:if (x == 0) { x += 2; }
				  else { x += 3; }
				  if (y == 0) { y += 0; }
				  else { y += 1; }break;
			case 4:if (x == 0) { x += 3; }
				  else { x += 4; }
				  if (y == 0) { y += 0; }
				  else { y += 1; }break;
			}; break;
			}
			break;
		}
	}
	cout << x << y;
	return 0;
}
long int power(int a, int b) {
	int i, c = 1;
	for (i = 0; i < b; i++) {
		c *= a;
	}
	return c;
}