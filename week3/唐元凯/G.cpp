#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>

using namespace std;

bool is_legal(int date) {
	if (date > 100000000)return false;
	int year = date / 10000;
	if (date < 1000)return false;
	int month = date % 10000 / 100, day = date % 100;
	bool isrun = false;
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0)isrun = true;
		}
		else isrun = true;
	}
	if (month < 1 || month > 12)return false;
	switch (month)
	{
	case 1:
		if (day <= 31)return true;
		break;
	case 2:
		if (isrun && day <= 29)return true;
		if ((!isrun) && day <= 28)return true;
		break;
	case 3:
		if (day <= 31)return true;
		break;
	case 4:
		if (day <= 30)return true;
		break;
	case 5:
		if (day <= 31)return true;
		break;
	case 6:
		if (day <= 30)return true;
		break;
	case 7:
		if (day <= 31)return true;
		break;
	case 8:
		if (day <= 31)return true;
		break;
	case 9:
		if (day <= 30)return true;
		break;
	case 10:
		if (day <= 31)return true;
		break;
	case 11:
		if (day <= 30)return true;
		break;
	case 12:
		if (day <= 31)return true;
		break;
	default:
		break;
	}
	return false;
}

bool is_loop(int date) {
	int front = date / 10000;
	int back = date % 10000;
	if ((front%10==back/1000)&&(front%100/10==back/100%10)&&(front/100%10==back%100/10)&&(front/1000==back%10))return true;
	else return false;
}

bool is_special_loop(int date) {
	int front = date / 10000;
	int back = date % 10000;
	if ((front / 100 == front % 100) && (back / 100 == back % 100))return true;
	else return false;
}

int main() {
	int date;
	cin >> date;
	bool sig1 = false, sig2 = false;
	int ans1, ans2;
	while (date < 100000000 && (!sig2)) {
		++date;
		if (is_legal(date)) {
			if (is_loop(date)) {
				if (!sig1) {
					ans1 = date;
					sig1 = true;
				}
				if (is_special_loop(date)) {
					ans2 = date;
					sig2 = true;
				}
			}
		}
	}
	cout << ans1 << '\n' << ans2;
}
