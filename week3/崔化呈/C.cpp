#include<bits/stdc++.h>
using namespace std;
int main()
{
	int dp[210],ans=0;
	string s="tocyjkdzcieoiodfpbgcncsrjbhmugdnojjddhllnofawllbhfiadgdcdjstemphmnjihecoapdjjrprrqnhgccevdarufmliqijgihhfgdcmxvicfauachlifhafpdccfseflcdgjncadfclvfmadvrnaaahahndsikzssoywakgnfjjaihtniptwoulxbaeqkqhfwl";
	for(int i=0;i<s.size();i++)
	{
		dp[i]=1;
		for(int j=0;j<i;j++)
		{
			if(s[j]<s[i]){dp[i]+=dp[j];}
			else if(s[j]==s[i]){dp[i]-=dp[j];}
		}
		ans+=dp[i];
	}
	printf("%d",ans);
}
