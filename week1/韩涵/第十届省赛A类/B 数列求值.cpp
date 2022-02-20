#include <iostream>
using namespace std;

int a[3] = {1,1,1};

int main()
{
   for(int i = 4;i <= 20190324;i++){
	   a[(i - 1) % 3] = (a[0] + a[1] + a[2]) % 10000;
   }
	cout<<a[(20190324 - 1) % 3];
}