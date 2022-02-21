#include <iostream>
using namespace std;
int main(){
	int sumdays=0;
	for(int i=1901;i<=2000;i++){
		if((i%4==0&&i%100!=0)||i%400==0) sumdays+=366;
		else sumdays+=365;
	}
	cout << sumdays/7 << endl;
}