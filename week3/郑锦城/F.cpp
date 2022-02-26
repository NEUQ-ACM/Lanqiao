#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin>>n;//输入n个数
    int b[n];
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    int maxlevel= log2(n+1);//层数
    int a[maxlevel] = {0};
    int max1=0;
    int i=0;
    for(int index=0;index<maxlevel;index++)
    {
        for(int cishu=1;cishu<=pow(2,index)&&i<n;cishu++,i++)
        {
            a[index]+=b[i];
        }
        max1 = a[index]>max1 ? a[index]:max1;

    }

    for(int i=0;i<maxlevel;i++)
    {

        if(a[i]==max1)
        {
            cout<<i+1;
            break;
        }
    }
    return 0;
}
