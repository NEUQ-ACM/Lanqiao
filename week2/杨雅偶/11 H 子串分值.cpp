#include<bits/stdc++.h>
using namespace std;
int main(){
	string st;
	cin>>st;
	int i,sum,sum1;
	i=st.length();
	sum=i;
	for(int j=0;j<i-1;j++){
		string st1,st2;
		sum1=1;
		for(int k=j+1;k<i;k++){
			int s=0;
			for(int m=j;m<k;m++){
				if(st[m]==st[k])	s++;
				if(s==2)	break;
			}
			if(s==0)	sum1=sum1+1;
			else if(s==1)	sum1=sum1-1;
			sum=sum+sum1;
		}
	}
	cout<<sum;
	return 0;
}
