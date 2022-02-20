#include<bits/stdc++.h>
#define ll long long
using namespace std;
string str="tocyjkdzcieoiodfpbgcncsrjbhmugdnojjddhllnofawllbhfiadgdcdjstemphmnjihecoapdjjrprrqnhgccevdarufmliqijgihhfgdcmxvicfauachlifhafpdccfseflcdgjncadfclvfmadvrnaaahahndsikzssoywakgnfjjaihtniptwoulxbaeqkqhfwl";
int ans=0;
int dp[1005];
int main()
{
	for(int i=0;i<str.size();i++)
		dp[i]=1;
	for(int i=0;i<str.size();i++)
		for(int j=0;j<i;j++)
			if(str[j]<str[i])
				dp[i]+=dp[j];
			else if(str[j]==str[i])
				dp[i]-=dp[j];
	for(int i=0;i<str.size();i++)
		ans+=dp[i];
	cout<<ans;
}
