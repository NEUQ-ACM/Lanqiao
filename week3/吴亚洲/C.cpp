#include<bits/stdc++.h>
using namespace std;
long long ans;
long long dp[200];
string s="tocyjkdzcieoiodfpbgcncsrjbhmugdnojjddhllnofawllbhfiadgdcdjstemphmnjihecoapdjjrprrqnhgccevdarufmliqijgihhfgdcmxvicfauachlifhafpdccfseflcdgjncadfclvfmadvrnaaahahndsikzssoywakgnfjjaihtniptwoulxbaeqkqhfwl";
int main()
{
	for(int i=0;i<=199;i++)
	dp[i]=1;
	for(int i=1;i<=199;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(s[i]>s[j])
			dp[i]+=dp[j];
			else if(s[i]==s[j])
			dp[i]-=dp[j];
		}
	}
	for(int i=0;i<=199;i++)
	ans+=dp[i];
	cout<<ans;
}
