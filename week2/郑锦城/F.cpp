#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int sum=0;
    int max1=0;
    int a[n];
    int min1=100;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>max1)
        {
            max1=a[i];
        }
        if(a[i]<min1)
        {
            min1=a[i];
        }
        sum+=a[i];
    }
    cout<<max1<<endl<<min1<<endl;
    printf("%.2f",sum*1.0/n);
    return 0;
}
