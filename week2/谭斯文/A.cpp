#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[10];
	int i,j,k,jud=1;
	for(i=0;i<10;i++)
		arr[i]=2021;
	for(i=1;jud;i++)
	{
		for(j=i;j>0;j/=10)
		{
			k=j%10;
			arr[k]--;
			if(arr[k]<0)
			{
				jud=0;
				break;
			}
		}
	} 
	cout<<i-2<<endl; 
	return 0;
}
