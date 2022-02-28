1. 105
2. 50 33 30 41
3. if(  connected(m,pID,i)  )     m[i]=qID ;
4. 
#include<iostream>
#include<string.h>  
#include<algorithm>  
using namespace std;  
typedef long long ll;  
char str[1024*1025],s[12];  
ll a[1024*1025];
ll cont[1100];
int n;  
ll zhuan(char ss[])
{  
    ll ans=0;  
    char s1[12];  
    memcpy(s1,ss,9);  
    sort(s1,s1+8);
    for(int i=0;i<8;i++)  
        ans = ans*26 + (s1[i]-'a');  
    return ans;  
}  
void find(ll c[],int l,int r,ll num,int &cnt)  
{  
    if(l==r){  
        cnt += c[l]==num;  
        return;  
    }  
    int mid=(l+r)/2;  
    if(c[mid]>=num)  
        find(c,l,mid,num,cnt);  
    if(c[mid+1]<=num)  
        find(c,mid+1,r,num,cnt);  
}  
int main()  
{  
    scanf("%s%d",str,&n);  
    for(int i=0;str[i+7];i++)  
    {  
        a[i]=zhuan(str+i);  
        printf("a£º%lld\n",a[i]);  
    }  
    for(int k=0;k<n;k++)  
    {  
        scanf("%s",s);  
        sort(s,s+8);  
        cont[k]=zhuan(s);  
        printf("count:  %lld\n",cont[k]);  
    }  
    sort(cont,cont+n);  
    ll ans=0;  
    for(int i=0;str[i+7];i++)
    {  
        int cnt=0;  
        find(cont,0,n-1,a[i],cnt);
        ans+=cnt;  
    }  
    printf("%lld\n",ans);  
    return 0;  
}
5. 
#include<iostream>
using namespace std;
#define maxn 10000
int w[maxn][maxn];
int n, L;
struct
{
    int dis, pop;
}p[maxn];

int min(int x, int y)
{
    return x < y ? x : y;
}
int solve(int start, int end, int cur)
{
    if (cur == 0)return w[start][end];
    int ML, MR, M;
    M = 2*L;
    //M = 2 * w[0][L];
    for (int m = start + 1; m < end; m++)
    {
        ML = solve(start, m, cur - 1);
        MR = solve(m, end, cur - 1);
        M = min(M, MR + ML);
    }
    return M;
}

int main()
{
    cin >> n >> L;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].dis >> p[i].pop;
    }
    for (int i = 0; i <= L; i++)
    {
        for (int j = i; j <= L; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (p[k].dis > i&&p[k].dis<j)
                {
                    w[i][j] += (j - p[k].dis)*p[k].pop;
                }
            }
        }
    }
    cout << solve(0, L, 2);
    return 0;
}