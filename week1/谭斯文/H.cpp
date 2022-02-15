#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cnt=0,i,j,k;
	int arr[26]={0};
    string str;
    cin>>str;
    for(i=0;i<str.length();i++)
    	for(j=i;j<str.length();j++)
    	{
    		for(k=i;k<=j;k++)
    		arr[str[k]-'a']++;
    		for(k=i;k<=j;k++)
    		{
    			if(arr[str[k]-'a']==1)
    			cnt++;
    			arr[str[k]-'a']=0;
			}	
		}
	cout<<cnt<<endl;
	return 0;
}
