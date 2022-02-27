#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
static const int maxn = 100010;
static const int INF = 0x3f3f3f3f;
static const int mod = (int)1e9 + 7;
static const double eps = 1e-6;
static const double pi = acos(-1);
 
void redirect(){
    #ifdef LOCAL
        freopen("test.txt","r",stdin);
    #endif
}
 
int main(){
    redirect();
    int n,h1,h2,m1,m2,s1,s2,d,t1,t2,t;
    scanf("%d",&n);
    getchar();
    string str;
    while(n--){
        getline(cin,str);
        d = 0;
        sscanf(str.c_str(),"%d:%d:%d %d:%d:%d (+%d)",&h1,&m1,&s1,&h2,&m2,&s2,&d);
        d = max(d,0);
        t1 = 3600*24*d+(h2-h1)*3600+(m2-m1)*60+(s2-s1);
        getline(cin,str);
        d = 0;
        scanf(str.c_str(),"%d:%d:%d %d:%d:%d (+%d)",&h1,&m1,&s1,&h2,&m2,&s2,&d);
        d = max(d,0);
        t2 = 3600*24*d+(h2-h1)*3600+(m2-m1)*60+(s2-s1);
        t = (t1+t2)/2;
        printf("%02d:%02d:%02d\n",t/3600,(t-t/3600*3600)/60,t%60);
    }
    return 0;
}
