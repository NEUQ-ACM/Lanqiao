#include <iostream>

using namespace std;

int m[10];
//int l[2021];
int main()
{
    int i;
    for(i=0;i<=9;i++)
    {
        m[i]=2021;
    }
    int temp,w;
    for(i=1;i<=20210;i++)
    {
        temp=i;
        while(temp!=0)
        {
            w=temp%10;
            m[w]--;
            temp=temp/10;
            if(m[w]==0)
            {
                cout<<i;
                return 0;
            }
        }
    }

    return 0;
}
