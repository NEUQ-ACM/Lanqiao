#include<bits/stdc++.h> 
using namespace std;
const int M=1e5+5;
char s[M];
int pos[M],nx[M],pre[M];
long long res=0;
int main()
{
    scanf("%s",s+1); 
    int len=strlen(s+1);
    for(int i=1;i<=len;i++)//预处理每一个相对的前一个
    {
        pre[i]=pos[s[i]-'a'];
        pos[s[i]-'a']=i;
    }
    for(int i=0;i<=26;i++) pos[i]=len+1;
    for(int i=len;i>=1;i--)
    {
        nx[i]=pos[s[i]-'a'];
        pos[s[i]-'a']=i;
    }
    for(int i=1;i<=len;i++)
        res+=1LL*(i-pre[i])*(nx[i]-i);
    printf("%lld\n",res);
    return 0;
}
