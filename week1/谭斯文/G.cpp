#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void check(int y)
{
	if((y%4==0&&y%100!=0)||y%400==0)
	{
		day[2]=29;
	}
	else day[2]=28;
}
int main()
{
    long long n,i,j,k,cnt=1;
    cin>>n;
    int y=n/10000+1,m=0,d=0,jud=1;	//´æ´¢Äê
    int arr[5];
    arr[1]=y%10;
    arr[2]=(y%100-arr[1])/10;
    arr[3]=(y%1000-y%100)/100;
    arr[4]=y/1000;
    i=y;
    while(jud)
    {
    	for(;i>0;i/=10)
	    {
	    	if(cnt<3) m+=i%10*pow(10,2-cnt);
	    	else if(cnt<5&&cnt>2) d+=i%10*pow(10,4-cnt);
	    	cnt++;
	    	if(cnt==5) 
			{
				cnt=1;
				check(y);
		    	if(m>12||m<1||day[m]<d)
		    	{
		    		i++;
		    		d=0;
		    		m=0;
		    		continue;
				}
				else
				{
					cout<<y*10000+m*100+d<<endl;
					jud=0;
				}
			}
		}
	} 
	jud=1;m=0;
	j=arr[2]*10+arr[1];k=j;
	while(jud)
    {
    	for(;k>0;k/=10)
	    {
	    	m+=k%10*pow(10,2-cnt);
	    	cnt++;
	    	if(cnt==3) 
			{
				d=m;
				cnt=1;
				y=j*100+j;
				check(y);
		    	if(m>12||m<1||day[m]<d)
		    	{
		    		j++;
		    		y=j*100+j;
		    		d=0;
		    		m=0;
		    		continue;
				}
				else
				{
					cout<<y*10000+m*100+d<<endl;
					jud=0;
				}
			}
		}
	} 
	return 0;
}
