#include<bits/stdc++.h>
using namespace std;
char a[10][11]={"UDDLUULRUL",
				"UURLLLRRRU",
				"RRUURLDLRD",
				"RUDDDDUUUU",
				"URUDLLRRUU",
				"DURLRLDLRL",
				"ULLURLLRDU",
				"RDLULLRDDD",
				"UUDDUDUDLL",
				"ULRDLUURRR"};
int main()
{
	int k=0;
	int m,n;
	int sum=0;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			m=i;
			n=j;
			while(k<100)
			{
				if(a[m][n]=='U') 
				m--;
				else if(a[m][n]=='D') 
				m++;
				else if(a[m][n]=='L') 
				n--;
				else if(a[m][n]=='R') 
				n++;
				if(m<0||m>9||n<0||n>9)
				{
					sum++;
					break;
				}
				k++;
			}
			k=0;
		}
	}
	cout<<sum<<endl;		
	return 0;
}

