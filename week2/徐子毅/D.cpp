#include<iostream>
using namespace std;
const long long num = 59084709587505;
bool is_lucky(int x,int y,int z)
{
	long long sum = 1;
	while (x--){
		sum *= 3;
		if (sum >= num) return false;
	}
	while (y--){
		sum *= 5;
		if (sum >= num) return false;
	}
	while (z--){
		sum *= 7;
		if (sum >= num) return false;
	}
	return true;
}
int main(){
	int ans=0;
	for (int a=0;a<=30;a++) for (int b=0;b<=30;b++) for (int c=0;c<=30;c++) {
		if (is_lucky(a,b,c)) ans++;
	}
	cout << ans;
	return 0;
}