#include<iostream>
using namespace std;
bool judge(int m)
{
    int mm[10];
    int indexm=0;
    while(m>0)
    {
        mm[indexm++]=m%10;
        m=m/10;
    }
    for(int j=0;j<4;j++)
    {
        if(mm[j]!=mm[indexm-j-1])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    int count1=0;
    for(int i=n+1;count1<2;i++)
    {
        if(judge(i))
        {
            cout<<i<<endl;
            count1++;
        }
    }
    return 0;
}
