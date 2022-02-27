#include<iostream>
using namespace std;
int judge(int m, int n)
{

   if(m%n==0)
   {
       return n;
   }
   else
   {
       return judge(n,m%n);
   }

}
int main()
{

    int count1=0;
    for(int i=1;i<=2020;i++)
    {
        for(int j=1;j<=2020;j++)
        {
            if(judge(i,j) == 1)
            {
                count1++;
            }
        }
    }
    cout<<count1;
    return 0;
}
