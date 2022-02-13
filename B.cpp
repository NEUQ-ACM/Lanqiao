#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[10];
    for(int i=0;i<=9;i++) 
    a[i]=2021;
    int now=1;
    bool flag=true;
    while(1)
	{
    int num=now;
    while(num)
	{
	if(a[num%10]==0)
    flag=false;
    a[num%10]--;
    num/=10;
    }
    if(flag==false){ cout<<now-1;
    break;
    }
    now++;
    }
    }

