#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N=5010,md=1e9+7;

int fx[N][N];
int n;
char s[N];

int get()
{
    memset(fx,0,sizeof(fx));
    fx[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='(')
        {
            for(int j=1;j<=n;j++)
            {
                fx[i][j]=fx[i-1][j-1];
            }
        }
        else
        {
            fx[i][0]=(fx[i-1][1] + fx[i-1][0]) % md;
            for(int j=1;j<=n;j++)
            {
                fx[i][j] = (fx[i-1][j+1] + fx[i][j-1]) % md;
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        if(fx[n][i])
        {
            return fx[n][i];
        }
    }
    return -1;
}

int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);

    int a=get();
    reverse(s+1,s+n+1);
    for(int i=1;i<=n;i++)
        {
            if(s[i]=='(') s[i]=')';
            else s[i]='(';
        }

    int b=get();
    cout<<a * b % md<<endl;
    return 0;
}
