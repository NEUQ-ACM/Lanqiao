#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int ans=0;
	for(int i=0;i<s.size();i++)
	{
		for(int j=1;j<=s.size()-i;j++)
		{
			string nows=s.substr(i,j);
			int a[26]={0};
			for(int k=0;k<nows.size();k++)
			{
				if(a[nows[k]-'a']==0){ans++;}
				else{ans--;}
				a[nows[k]-'a']++;
			}
		}
	} 
	printf("%d",ans);
	return 0;
}
