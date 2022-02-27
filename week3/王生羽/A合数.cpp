#include<bits/stdc++.h>
using namespace std;
bool Pri(int n)
{
	if(n <= 1) return false;
	for(int i = 2;i < sqrt(n);i++)
	{
		if(n % i == 0)  return false;
	}
	return true;
}
int main()
{
   int n;
   cin>>n;
   int num = 0;
   for(int i = 0; i <= n;i++)
   {
   	if(!Pri(i)) num ++;
   }
   cout<<num - 1;
    return 0;
}
//num-1=合数个数=1701 
