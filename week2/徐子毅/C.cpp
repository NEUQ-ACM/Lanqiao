#include <iostream>
using namespace std;
int main(){
	int num;
	int NumFive=0,NumTwo=0;
	while(cin>>num){
		while(num%2==0){
			NumTwo++;
			num/=2;
		}
		while(num%5==0){
			NumFive++;
			num/=5;
		}
	}
	cout << min(NumFive,NumTwo) << endl;
}