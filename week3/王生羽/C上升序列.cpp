#include <iostream>
#include <string.h>
using namespace std;
#define N 200
int dp[N]={0};
int main()
{
	string s="tocyjkdzcieoiodfpbgcncsrjbhmugdnojjddhllnofawllbhfiadgdcdjstemphmnjihecoapdjjrprrqnhgccevdarufmliqijgihhfgdcmxvicfauachlifhafpdccfseflcdgjncadfclvfmadvrnaaahahndsikzssoywakgnfjjaihtniptwoulxbaeqkqhfwl";
	//string s="lanqiao";	
	
	for(int i=0;i<N;i++)dp[i]=1;
	for(int i=1;i<N;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(s[i]>s[j])
			{
				dp[i]+=dp[j];
			}
			else if(s[i]==s[j])
			{
				dp[i]-=dp[j];
			}
		}
	}
	
	
	int ans=0;
	for(int i=0;i<N;i++)
	{
		ans+=dp[i];
	}
	cout<<ans<<endl;
	
	
	//for(int i=0;i<N;i++)cout<<dp[i]<<" "<<endl;
	return 0;
} 
//3616159 
