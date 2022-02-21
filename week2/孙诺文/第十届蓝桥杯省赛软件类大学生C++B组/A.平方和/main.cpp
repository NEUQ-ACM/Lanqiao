#include <iostream>

using namespace std;

int main()
{
    long long sum=0;
    for(int i=1;i<=2019;i++)
    {
        int temp=i,ch,flag=0;
        while(temp!=0)
        {
            ch=temp%10;
            if(ch==2||ch==0||ch==1||ch==9)
            {
                flag=1;
                break;
            }
            temp=temp/10;
        }

        if(flag==1)
        {
            sum=sum+i*i;
        }

    }

    cout<<sum;
    return 0;
}

//½á¹ûÎª2658417853
