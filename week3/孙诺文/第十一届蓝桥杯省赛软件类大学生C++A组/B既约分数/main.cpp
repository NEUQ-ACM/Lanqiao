#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    int temp,c=0;
    for(int i=1;i<=2020;i++)
    {
        for(int j=1;j<=2020;j++)
        {

            if(i==1||j==1)
            {
                c++;
                continue;
            }
            if(i<=j) temp=i;
            if(j<i) temp=j;

            for(int t=2;t<=sqrt(temp);t++)
            {
                if(i%t!=0&&j%t!=0) c++;
                break;
            }

        }
    }
    cout<<c;
    return 0;
}
