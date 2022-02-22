#include <bits/stdc++.h>
using namespace std;
int get(int i,int j)
{
	int temp,cha;
	if(i<j)
	{
		temp=i;
		i=j;
		j=temp;
	}//保证i为最大
	while(j)
	{
		cha=i%j;
		i=j;
		j=cha;	
	} 
	return i;
}
int main()
{
    int i,j,cnt=0;
	for(i=1;i<=2020;i++)
		for(j=1;j<=2020;j++) 
			{
				if(get(i,j)==1)
				cnt++;
			}
	cout<<cnt<<endl;
	return 0;
}
