#include<bits/stdc++.h>
using namespace std;
int gcd(int x, int y)
{
	int min, i;
	min = x>y?y:x;
	for(i=min; i>=1; --i){
	if(x%i==0 && y%i==0)
	break;
}
	return i;
}
int main()
{
	int  i, j, sum = 0;
	for(i = 1;i <= 2020;i++)
	{
		for(j =1;j <= 2020;j++)
		if(gcd(i,j) == 1) sum ++;
	} 
	cout<<sum;
    return 0;
}
//2481215
