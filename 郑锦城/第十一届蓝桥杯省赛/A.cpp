#include<iostream>
using namespace std;
int main()
{
    int count1=0;
    for(int i=0;i<=2020;i++)
    {
        int i1=i;
        while(i1>0)
        {
            int a=i1%10;
            if(a==2)
            {
                count1++;
            }
            i1=i1/10;
        }
    }
    cout<<count1;
    return 0;
}
