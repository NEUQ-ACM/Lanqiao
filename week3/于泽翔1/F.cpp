#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n, a, min=100, max=0;
	double tot=0;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>a;
		min=a<min?a:min;
		max=a>max?a:max;
		tot+=a;
	}
	double ave=tot/n;
	printf("%d\n%d\n%.2lf", max, min, ave);
	
	return 0;
}