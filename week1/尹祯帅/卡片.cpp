#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[10]={2021,2021,2021,2021,2021,2021,2021,2021,2021,2021};
	int n=0;
	bool jud=0;
	while(!jud)
	{
		n++;
		int t=n;
		while(t)
		{
			int s=t%10;
			t/=10;
			a[s]--;
		}
		for(int i=0;i<10;i++) 
		if(!a[i]) jud=1;
	}
	cout<<n;
	return 0;
} 
