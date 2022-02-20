#include <bits/stdc++.h>
using namespace std;
int main() 
{   
    int ans = 0;
    int a[13] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    do
	{
        if(a[0]+a[1]==a[2]&&a[3]-a[4]==a[5]
        && a[6]*a[7] == a[8]&&a[9]/a[10]==a[11])
		{
            ans++;
        }
    }while(next_permutation(a,a+13));
    cout << ans;
    return 0;
}

