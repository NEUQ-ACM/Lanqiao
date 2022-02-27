#include<bits/stdc++.h>
using namespace std;

int a[10005];
double sum = 0;
double res;

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum += a[i];
    }
    sort(a,a+n);
    res = sum/n;
    cout<<a[n-1]<<endl;
    cout<<a[0]<<endl;
    printf("%.2f",res);
    return 0;
}
