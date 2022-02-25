#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef long long LL;

int main()
{
    int n,maxg=-1,ming=101,sum=0;

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        int g;
        scanf("%d",&g);
        sum+=g;
        if(g>maxg) maxg=g;
        else if(g<ming) ming=g;
    }

    double avg=sum*1.0/n;

    printf("%d\n%d\n%.2f",maxg,ming,avg);

    return 0;
}

