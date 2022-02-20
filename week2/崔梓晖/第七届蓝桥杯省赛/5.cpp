#include<bits/stdc++.h>
using namespace std;
int n,a[4];
int y;
int main() 
{
	cin>>n;
	for(int i=0;i<=n;i++) 
	{
		for(int j=i;j<=sqrt(n-i*i);j++)
		 {
			for(int k=j;k<=sqrt(n-i*i-j*j);k++)
			 {
			    y=sqrt(n-i*i-j*j-k*k);
				if(y*y==n-i*i-j*j-k*k) 
				{
					a[0]=i,a[1]=j,a[2]=k,a[3]=y;
					sort(a,a+4);
					cout<<a[0]<<' '<<a[1]<<' '<<a[2]<<' '<<a[3]<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}

