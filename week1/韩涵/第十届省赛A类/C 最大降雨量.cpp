#include <iostream>
#include<math.h>
using namespace std;

int main()
{
    int fu = 49;
    int week = sqrt(fu);
	int bigger = pow((week / 2 + 1),2);
	int ans = fu - bigger + 1;
	cout<<ans;
}