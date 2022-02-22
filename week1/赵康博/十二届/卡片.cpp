#include<iostream>
#include<vector>
 
using namespace std;
int main()
{
    vector<int> cards(10,2021);
    int i;
    for(i=1;i<999999;i++)
    {
        //cout<<i<<endl;
        int num=i;
        while(num)
        {
            int n=num%10;
            num/=10;
            if(cards[n]==0)
            {
                return i-1;
            }
            cards[n]--;            
        }
    }
    return 1;
}