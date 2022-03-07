#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int f[210],ans=0;
	s="tocyjkdzcieoiodfpbgcncsrjbhmugdnojjddhllnofawllbhfiadgdcdjstemphmnjihecoapdjjrprrqnhgccevdarufmliqijgihhfgdcmxvicfauachlifhafpdccfseflcdgjncadfclvfmadvrnaaahahndsikzssoywakgnfjjaihtniptwoulxbaeqkqhfwl";
	for(int i=0;i<200;i++){
		f[i]=1;
		for(int j=0;j<i;j++)
		{
			if(s[i]>s[j]) f[i]+=f[j];
			else if(s[i]==s[j]) f[i]=0;		
		}
		ans+=f[i];
	}
	cout<<ans;
	return 0;		
}

