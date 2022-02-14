#include <iostream>
#include<cmath>
using namespace std;
long long m[99];
int t[99];
int head=1,tail=1;


int main()
{
    long long target=2021041820210418;
    long long i;
    long long sum=1;
    for(i=2;i<=target;i++)
    {
        if(target%i==0)
        {
            m[tail]=i;
            t[tail]=1;
            target=target/i;
            tail++;

            if(i! =1  )
                i--;
        }

        if(m[tail-1]==m[tail-2])
        {
            t[tail-2]++;
            tail--;
        }

    }


    cout<<tail-1<<endl;
    for(i=1;i<tail;i++)
    {
        cout<<m[i]<<" ";
    }
    cout<<endl;
    for(i=1;i<tail;i++)
    {
        cout<<t[i]<<" ";
    }
    cout<<endl;



    return 0;
}


