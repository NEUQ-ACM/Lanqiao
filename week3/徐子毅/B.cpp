#include <iostream>
using namespace std;
long long a[4]={1,1,1,3};
int main(){
	long long count=4;
	int i=0;
	while(count!=20190324){
		count++;
		a[i]=(a[0]+a[1]+a[2]+a[3]-a[i])%10000;
		if(i==3) i=0;
		else i++;
	}
	cout << i << endl;
	cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << endl;
}