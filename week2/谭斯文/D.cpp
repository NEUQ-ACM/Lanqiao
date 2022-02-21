#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int arr[2022][2022],d[2022];
int gcd(int i,int j)
{
	return j==0?i:gcd(j,i%j);
}
int get(int i,int j)
{
	return i*j/gcd(i,j);
}
int main()
{
    int i,j;
    
    for(i=1;i<=2021;i++)
    	for(j=i-1;j>=i-21&&j>=1;j--)
    		arr[j][i]=get(i,j);
    memset(d,0x3f,sizeof(d));
    d[1]=0;
    for(i=1;i<=2021;i++)
    	for(j=i-1;j>=i-21&&j>=1;j--)
    		d[i]=min(d[i],d[j]+arr[j][i]);
    cout<<d[2021]<<endl;
	return 0;
}
