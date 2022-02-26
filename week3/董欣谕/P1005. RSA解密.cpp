#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pair <int,int> pii
const ll mod=1001733993063167141;
const ll INF=0x3f3f3f3f; 
__int128 qsm(__int128 a,__int128 b,__int128 mod){
	__int128 res=1,temp=a%mod;
	while (b){
		if (b&1) res=res*temp%mod;
		temp=temp*temp%mod;
		b>>=1;
	}
	
	return res;
}
template<typename T>void write(T x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9)
    {
        write(x/10);
    }
    putchar(x%10+'0');
}
template<typename T> void read(T &x)
{
    x = 0;char ch = getchar();ll f = 1;
    while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
    while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
int main(){
	__int128 n=1001733993063167141,d=212353,c=20190324;
	__int128 p=891234941,q=1123984201;
	__int128 temp=(p-1)*(q-1);
	__int128 e;
	for (int i=2;i<=n+1;i++){
		__int128 now=i*temp+1;
		if (now%d==0){
			e=now/d;
			break;
		}
	}
	__int128 ans=qsm(c,e,n);
	write(ans);
	return 0;
} 
